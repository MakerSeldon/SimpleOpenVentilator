
/**
 *  This code is not approved for life support use.  You may freely use this code to test various 
 *  physical implementations for future uses under applicable guidelines and approvals of relevant 
 *  governance bodies. 
 *  
 * @brief   This code toggles two relays with a fixed time period adjustable through 2 user input 
 *          switches. 
 *   
 * @note    This demo code relies on a 16MHz system clock speed on an Arduino controller.
 * @note    At powerup and unanticipated resets, default operational parameters are loaded.  
 * @note    The input switches are normally open switches connected to gnd and to gpio pins 
 *          configured as inputs with internal pull up resistors.  Therefore when not pressed, 
 *          they will read HIGH. 
 * @note    Solid State Relays are used.  These require less current and do not requie extra 
 *          components to snub inductive kickback like mechanical types.  The relays chosen must 
 *          not require input currents exceeding the gpio pin limit of 40mA, and must be compatible 
 *          with the Arduino supply voltage (+5V for UNO).  TE Potter & Brumfield SSR-240D25 is an
 *          available and suitable part. 
 * @note    The relays are connected to the supply voltage (+5V for UNO) and also to a gpio pin 
 *          configured as an output.  This means the relays high voltage sides are Active when the 
 *          gpio pin is driven LOW, and Inactive when driven HIGH.
 * @todo    Ideas: Better user feedback for cycles per minute. Failsafe via watchdog for both isr 
 *          and main loop. Previous opertional parameters saved in eeprom for power cycles.
 * */

#include <Arduino.h>
#include <defs.h>

/** startup timing - these are adjusted via the switch inputs.  We're using a set of variables 
 *  so we can make adjustments in one place in the main loop to place some overlap delay in 
 *  opening/closing relays.
*/
uint16_t wait_dump      = COUNT_DUMP[DEFAULT_CHARGEDUMP_INDEX];
uint16_t wait_d         = COUNT_RELAY_OVERLAP;
uint16_t wait_charge    = COUNT_CHARGE[DEFAULT_CHARGEDUMP_INDEX];
uint16_t wait_c         = COUNT_RELAY_OVERLAP;

/** enum to keep track of current charge/dump state */
uint8_t const CHARGE  = 0U;
uint8_t const C_WAIT  = 1U;
uint8_t const DUMP    = 2U;
uint8_t const D_WAIT  = 3U;
static uint8_t chargedump_state = DUMP;

/** keeps the current cycle times via index into counter timing arrays */
uint16_t dumpcharge_index = DEFAULT_CHARGEDUMP_INDEX;

/** helpers for enabling only one step up or down per switch press */
uint8_t const SET   = 1U;
uint8_t const RESET = 0U;
uint8_t switch_pressed = RESET;    

/**
 * @brief main arduino loop, repeats forever.
 * @details The main loop code is non-blocking.  All delays and timing are through polling 
 *          of countdown timers under control of timer1 interrupts.  Switch status is 
 *          maintained through io pin reads and debouncing in timer2 interrupts.
 * */ 
void loop()
{
    uint8_t switch_up = 0U;
    uint8_t switch_down = 0U;
    uint16_t cntr_value = 0U;

    /**
     * @note this section reads the switches adjusts the dump/charge index
     * */
    read_counter(CNTR_SWITCHES, &cntr_value);
    if (0U == cntr_value)
    {
        read_switches(&switch_up, &switch_down);
        write_counter(CNTR_SWITCHES, CNTR_SWITCH_VALUE);

        if ((SWITCH_CLOSED == switch_down) && (RESET == switch_pressed))
        {
            if (MIN_PER_MINUTE < dumpcharge_index)
            {
                dumpcharge_index -= 1;
            }
            Serial.println(dumpcharge_index);   /** prints index, but also flashes tx led for user feedback */
            switch_pressed = SET;
        }
        else if ((SWITCH_CLOSED == switch_up) && (RESET == switch_pressed))
        {
            if (MAX_PER_MINUTE > dumpcharge_index)
            {
                dumpcharge_index += 1;
            }
            Serial.println(dumpcharge_index);   /** prints index, but also flashes tx led for user feedback */
            switch_pressed = SET;
        }
        else if ((SET == switch_pressed) && (SWITCH_OPEN == switch_up) && (SWITCH_OPEN == switch_down))
        {
            switch_pressed = RESET;
        }       
    }   /** end: if (0U == cntr_value) */
 

    /** 
     * @note Adjust the values for the cycle times.
     * */
    if (DUMP == chargedump_state)
    {
        wait_dump = COUNT_DUMP[dumpcharge_index];
        wait_charge = COUNT_CHARGE[dumpcharge_index] - COUNT_RELAY_OVERLAP - COUNT_RELAY_OVERLAP;
    }

    /**
     * @note This section reads the charge/dump counter and if it timed out (=0)
     *        then use the current state to set up the next state.  The actions 
     *        in each case are for the completion of that case.
     * */
    read_counter(CNTR_CHARGE_DUMP, &cntr_value);
    if (0U == cntr_value)
    {
        switch (chargedump_state)
        {
        case CHARGE:
            digitalWrite(LED_BUILTIN, HIGH);
            digitalWrite(RELAY_DUMP, RELAY_OFF);
            chargedump_state = C_WAIT;
            write_counter(CNTR_CHARGE_DUMP, wait_c);
            break;

        case C_WAIT:
            digitalWrite(RELAY_CHARGE, RELAY_ON);
            chargedump_state = DUMP;
            write_counter(CNTR_CHARGE_DUMP, wait_charge);
            break;

        case DUMP:
            digitalWrite(LED_BUILTIN, LOW);
            digitalWrite(RELAY_CHARGE, RELAY_OFF);
            chargedump_state = D_WAIT;
            write_counter(CNTR_CHARGE_DUMP, wait_d);
            break;

        case D_WAIT:
            digitalWrite(RELAY_DUMP, RELAY_ON);
            chargedump_state = CHARGE;
            write_counter(CNTR_CHARGE_DUMP, wait_dump);
            break;

        default:
            digitalWrite(RELAY_DUMP, RELAY_OFF);
            chargedump_state = CHARGE;
        }  
    }   /** end: if (0U == cntr_value) */




}   /** end: loop() */


/**
 * @brief Setup for timer1 for output compare interrupts and auto reset.
 * @details This sets up the 16 bit timer1 counter to trigger an output compare interrupt
 *          which automatically resets.  Use of servo functions and analog pins 9 and 10 
 *          are precluded by using this timer for our own functions.
 * @note  This sets up a divide-by-8 prescaler to the 16MHz clock for a 0.5 us tick rate. 
 *        A 40000 count in the oc register therefore produces an interrupt every 20ms.
 */
void timer1_configure(void)
{
    /** disconnect output compares from pins, and set half the wgm mode 4 */
    TCCR1A = 0x00;

    /** setup the other half of the wgm mode 4 CTC mode 4 (reset counter upon interrupt) */
    TCCR1B &= ~(1 << WGM13);
    TCCR1B |= (1 << WGM12);

    /** set prescale to divide by 8 - 010 in CS12|CS11|CS10 positions in config register */
    TCCR1B &= ~(1 << CS12);
    TCCR1B |= (1 << CS11);
    TCCR1B &= ~(1 << CS10);

    /** clear timer1 counter and set compare value */
    TCNT1 = 0;
    OCR1A = TIMER1_COUNT_FOR_INT;

    /** allow timer1 compare interrupt in mask */
    TIMSK1 = (1 << OCIE1A);

    /** enable interrupts globally */
    sei();
}


/**
 * @brief Setup for timer2 for overflow interrupt every ~16.4ms.
 * @details Call this before timer1_configure since that enables global interrupts.
 *          Using timer2 interferes with arduino tone() and PWM/AnalogWrite() to pins 3 and 11.
 * @note  This sets up a divide-by-1024 prescaler to the 16MHz clock for a 64 us tick rate. 
 *        Overflow occurs every 16.38ms.
 */
void timer2_configure(void)
{
    /** disconnect output compares from pins */
    TCCR2A = 0x00;

    /** set prescale to divide by 1024 */
    TCCR2B = 0x07;

    /** allow timer2 overflow interrupt in mask */
    TIMSK2 = (1 << TOIE2);
}


/** @brief The standard arduino setup function, executes only once on startup.
 *  @details We set up the io pins, timer interrupts, and some initial operational
 *              states.
 * */
void setup()
{
    Serial.begin(9600);
    Serial.println(F("start setup.."));
    
    /** setup relay pins for outputs */
    pinMode(RELAY_CHARGE, OUTPUT);
    pinMode(RELAY_DUMP, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);

    /** setup switch pins for internal pullup resistors */
    pinMode(SWITCH_DOWN, INPUT_PULLUP);
    pinMode(SWITCH_UP, INPUT_PULLUP);

    /** configure and activate the timer interrupts */
    timer2_configure();
    timer1_configure();

    /** start the switch counter */
    write_counter(CNTR_SWITCHES, CNTR_SWITCH_VALUE);

    /** set the initial state of the cycle */
    chargedump_state = DUMP;

    Serial.println(F("end setup.."));
}
  

  

