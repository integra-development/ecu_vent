/*
 * timers.h
 *
 *  Created on: 27. ožu 2023.
 *      Author: Rajko
 */

#ifndef INC_TIMERS_H_
#define INC_TIMERS_H_

#include <SI_EFM8BB3_Register_Enums.h>
#include "pin_names.h"
uint32_t millis	= 0;

uint16_t xdata ledTimer	= 0;
unsigned int previousMillis = 0; // variable to store the last time the LED was toggled
const unsigned long interval = 200; // interval (in ms) for LED toggle
unsigned int currentMillis = 0;
uint32_t bitPattern=0;
uint32_t	newKey=0;
uint32_t	oldKey=0;
uint8_t timerValue;
uint16_t msCount=0;
char pulseCount=0;



uint16_t pulse_duration;
uint16_t pulse_width;
 uint16_t pulse_start_time;
 uint32_t counterus = 0;
 volatile uint8_t nec_state = 0;
 volatile uint32_t nec_code = 0;
 volatile uint8_t nec_code_ready = 0;

//-----------------------------------------------------------------------------
// TIMER2_ISR
//-----------------------------------------------------------------------------
//
// TIMER2 ISR Content goes here. Remember to clear flag bits:
// TMR2CN0::TF2H (Timer # High Byte Overflow Flag)
// TMR2CN0::TF2L (Timer # Low Byte Overflow Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (TIMER0_ISR, TIMER0_IRQn)
 {

	msCount++;
	TH0 = 0x3F; // Set Timer0 High byte
		TL0 = 0x1D; // Set Timer0 Low byte


 }

SI_INTERRUPT (TIMER2_ISR, TIMER2_IRQn)
{


	 millis++;
	 /* if(msCount<50)
		        msCount++;
*/



if ( millis - currentMillis > 1000){
	currentMillis = millis;
	LED_RAIN = !LED_RAIN;
		}




	SFRPAGE = 0x10;
	TMR2CN0_TF2H = 0;
	TMR2CN0_TF2L = 0;
}



extern bit swventpressed;
extern bit swlidpressed;
extern uint8_t lidstate;
extern uint8_t ventstate;
// Interrupt service routine for Timer3 overflow
SI_INTERRUPT(TIMER3_ISR, TIMER3_IRQn)
{

}





SI_INTERRUPT (INT0_ISR, INT0_IRQn)
{
	 timerValue = msCount;
		    msCount = 0;

		    TH0 = 0x3F; // Set Timer0 High byte
		    		TL0 = 0x1D; // Set Timer0 Low byte



		    pulseCount++;

		    if((timerValue>=50)) // If the pulse width is greater than 50ms, this will mark the SOF
		    {
		        pulseCount = -2; // First 2 counts needs to be skipped hence pulse count is set to -2
		        bitPattern = 0;
		    }
		    else if((pulseCount>=0) && (pulseCount<32)) //Accumulate the bit values between 0-31.
		    {
		        if(timerValue>=2)                      //pulse width greater than 2ms is considered as LOGIC1
		        {
		            bitPattern |=(uint32_t)1<<(31-pulseCount);
		        }
		        else
		        {

		        }
		    }
		    else if(pulseCount>=32)                  //This will mark the End of frame as 32 pulses are received
		    {
		        newKey = bitPattern;                // Copy the newKey(patter) and set the pulse count to 0;

		        pulseCount = 0;
		    }

}
#endif /* INC_TIMERS_H_ */
