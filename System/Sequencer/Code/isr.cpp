/**
 *  @brief  This module includes the interrupt service routine and several functions to 
 *          access the state information.
 * 
 *  @details    The isr reads io pins and saves the values in local variables.  The values
 *              are read multiple times to eliminate noise during transitions of state.
 *              For code safety, accessor functions to read these values are also included.  
 */

#include <arduino.h>
#include "defs.h"



/**
 * @note timer 1
 * */

/** number of counters to decrement for main loop taskings */
static uint16_t countdown_array[NUMBER_OF_COUNTERS] = {0};


/**
 * @note timer 2
 * */

/** live readings of previous pin states, updated each interrupt */
static uint8_t switch_down_buffer   = 0U;
static uint8_t switch_up_buffer     = 0U;
static uint8_t switch_down_debounced = 0U;
static uint8_t switch_up_debounced = 0U;

/** for locking of pin state reads by getter func */
static uint8_t const  IS_LOCKED     = 1U;
static uint8_t const  IS_UNLOCKED   = 0U;
static uint8_t isr_lock             = IS_UNLOCKED;   /** flag for isr and readout function coordination */

/** debounce masks - need 4 equivalent successive reads to debounce */
uint8_t const ALL_HIGH = 0x0f;
uint8_t const ALL_LOW = 0x00;


/** 
 * @brief timer 1 isr decrements each counter in its array every 10 ms until it is zero.
 * @details This is set up for divide by 8 prescaler and a count of 20000 in OC reload mode.
 * */
ISR(TIMER1_COMPA_vect)
{
    /** decrement all counters until = 0 */
    for (unsigned int i = 0; i < NUMBER_OF_COUNTERS; i++)
    {
        if (0U != countdown_array[i])
        {
            countdown_array[i] -= 1;
        }
    }
}


/** 
 * @brief Returns a counter's value.
 * */
void read_counter(uint8_t counter_num, uint16_t *value)
{
    if (counter_num < NUMBER_OF_COUNTERS)
    {
        *value = countdown_array[counter_num];
    }
}


/** 
 * @brief Sets a counter's value. 
 * */
void write_counter(uint8_t counter_num, uint16_t value)
{
    if (counter_num < NUMBER_OF_COUNTERS)
    {
        countdown_array[counter_num] = value;
    }
}


/**
 * @brief Reads and places switch states into buffer, saves debounced switch readings.
 * @details With prescale divider of 1024, this overflow happens every 64.38ms
 */
ISR(TIMER2_OVF_vect)
{
    /** read the switch state and place in buffer in bit7 */
    switch_down_buffer = switch_down_buffer >> 1;
    if (HIGH == digitalRead(SWITCH_DOWN))
        {
            switch_down_buffer |= 0x80;
        }

    switch_up_buffer = switch_up_buffer >> 1;
    if (HIGH == digitalRead(SWITCH_UP))
        {
            switch_up_buffer |= 0x80;
        }

    /** update the local pin_states array to reflect current filtered states. */
    if (IS_UNLOCKED == isr_lock)
    {   
        /** examine last 4 readings and update current readings iff all match */
        if (ALL_HIGH == switch_down_buffer >> 4)
        {
            switch_down_debounced = HIGH;
        } 
        else if (ALL_LOW == switch_down_buffer >> 4)
        {
            switch_down_debounced = LOW;
        }

        if (ALL_HIGH == switch_up_buffer >> 4)
        {
            switch_up_debounced = HIGH;
        } 
        else if (ALL_LOW == switch_up_buffer >> 4)
        {
            switch_up_debounced = LOW;
        }
    }
    
}


/** 
 * @brief   Returns the debounced switch states.
 */
void read_switches(uint8_t *switch_up, uint8_t *switch_down)
{
    isr_lock = IS_LOCKED;
    *switch_up = switch_up_debounced;
    *switch_down = switch_down_debounced;
    isr_lock = IS_UNLOCKED;
}