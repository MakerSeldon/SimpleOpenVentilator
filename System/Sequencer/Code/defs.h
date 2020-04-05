#ifndef DEFS_H
#define DEFS_H

#include <arduino.h>


/** arduino pin identifiers for switches (faster/slower) and relays (charge/dump relays */
uint8_t const RELAY_CHARGE  = PIN7;
uint8_t const RELAY_DUMP    = PIN5;
uint8_t const SWITCH_DOWN   = PIN2;
uint8_t const SWITCH_UP     = PIN3;

/** pin states for relays and switches - active low */
uint8_t const RELAY_ON      = LOW;      /** arduino sinks current to activate relay tied to Vcc */
uint8_t const RELAY_OFF     = HIGH;
uint8_t const SWITCH_CLOSED = LOW;      /** normally open switches to gnd (uses internal pull ups) */ 
uint8_t const SWITCH_OPEN   = HIGH;

/** Counter values for charge and dump. The index value
 *  is the number of cycles per minute and the array values correspond to dump/charge
 *  times for each part.  ex: 12x per minute = 5 sec per cycle so index 12 gets dump and
 *  charge array values (in 10 ms ticks) that add up to 5 sec.  Valid range is 5 to 30 cycles  
 *  per minute. 
 * */
uint16_t const MAX_ARRAY_CHARGEDUMP = 31;   /** add 1 for the zero index */
uint16_t const COUNT_DUMP[MAX_ARRAY_CHARGEDUMP] = { 
      0,   0,   0,   0,   0, 150, 145, 141, 136, 132, 
    128, 123, 119, 114, 110, 106, 101,  97,  92,  88, 
     83,  79,  75,  70,  66,  61,  57,  53,  48,  44, 
     40
     };
uint16_t const COUNT_CHARGE[MAX_ARRAY_CHARGEDUMP] = {
       0,    0,    0,    0,    0, 1050,	 855,  716,	 614,  534, 	
     472,  422,	 381,  347,	 318,  294,	 274,  255,	 241,  227,
     217,  206,  197,  190,  184,  179,	 173,  169,	 166,  162,	
     160
     };
uint16_t const MIN_PER_MINUTE = 5U;
uint16_t const MAX_PER_MINUTE = 30U;
uint16_t const DEFAULT_CHARGEDUMP_INDEX = 10;   /** 10 per minute to start with */
uint16_t const COUNT_RELAY_OVERLAP = 5U;        /** 5 tick overlap, charge/dump relay switching */


/** switch polling interval, in 10ms increments via timer counter */
uint16_t const CNTR_SWITCH_VALUE  = 10;


/**
 * @note timer setup
 * */
/** 16MHz clock speed - value for generating 10 ms interrupts (timer1 set up for prescale of 8, 
 * ie 0.5us tick */
uint16_t const TIMER1_COUNT_FOR_INT = 20000U;

/** interrupt countdown timers */
uint8_t const NUMBER_OF_COUNTERS    = 2U;

uint8_t const CNTR_SWITCHES         = 0U;
uint8_t const CNTR_CHARGE_DUMP      = 1U;



/** extern definitions from isr.c*/
void read_switches(uint8_t *, uint8_t *);
void write_counter(uint8_t, uint16_t);
void read_counter(uint8_t, uint16_t *);


#endif
