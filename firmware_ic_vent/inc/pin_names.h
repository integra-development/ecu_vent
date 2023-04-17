/*
 * pin_names.h
 *
 *  Created on: Oct 2, 2019
 *      Author: marko
 */

#ifndef __PIN_NAMES_H__
#define __PIN_NAMES_H__

#include <SI_EFM8BB3_Register_Enums.h>

//-------------------------------------------------------------------------------------------------
// Pin names
//-------------------------------------------------------------------------------------------------
SI_SBIT(VREF,		SFR_P0, 0);	// VREF ADC
SI_SBIT(AGND,		SFR_P0, 1);	// Analog Ground
SI_SBIT(IR_RX	, 	SFR_P0, 2);	// input from IR
SI_SBIT(OUT_RD, 	SFR_P0, 3);	// Output for Rain Detector
SI_SBIT(TX0, 		SFR_P0, 4);	// UART0 TX
SI_SBIT(RX0, 		SFR_P0, 5);	// UART0 RX
SI_SBIT(ML_2,		SFR_P0, 6);	// MOTOR LID CTRL 2    L     H     L     H
SI_SBIT(ML_1,		SFR_P0, 7);	// MOTOR LID CTRL 1    L     L     H     H
//													  STOP  RVS   FWD   BRK
SI_SBIT(ML_CS,		SFR_P1, 0);	// MOTOR LID CURRENT SENSE - DIGITAL INPUT
SI_SBIT(MV_2,		SFR_P1, 1);	// MOTOR VENT CTRL 2    H     H     L    L
SI_SBIT(MV_1,		SFR_P1, 2);	// MOTOR VENT CTRL 1    H     L     L    H
//													  STOP  RVS   FWD   BRK
SI_SBIT(MV_CS	,	SFR_P1, 3);	// ADC2 // MOTOR VENT CURRENT SENSE - DIGITAL INPUT
SI_SBIT(MISO	,	SFR_P1, 4);	//  NOT IN USE
SI_SBIT(SSF		,	SFR_P1, 5);	//   OPTIONAL FRAM
SI_SBIT(MOSI	,	SFR_P1, 6);	//
SI_SBIT(SCLK	,	SFR_P1, 7);	//

SI_SBIT(PWM_PMB,	SFR_P2, 0);	// NU - DIGITAL IN
SI_SBIT(RAIN_IN,	SFR_P2, 1);	// RAIN SENSOR DIGITAL IN
SI_SBIT(SSS, 		SFR_P2, 2);	// NU - DIGITAL IN
SI_SBIT(SA3, 		SFR_P2, 3);	// NU - DIGITAL IN
SI_SBIT(SW_LID, 	SFR_P2, 4);	// SWITCH LID - DIGITAL IN  - PULL UP
SI_SBIT(SW_VENT, 	SFR_P2, 5);	// SWITCH_VENT - DIGITAL IN
SI_SBIT(SA0, 		SFR_P2, 6);	// NU - DIGITAL IN

SI_SBIT(NU,			SFR_P3, 0);	//  NU - DIGITAL IN
SI_SBIT(LED_RAIN, 	SFR_P3, 1);	// LED RAIN - OUTPUT ACT 0
SI_SBIT(LED_LID, 	SFR_P3, 2);	// LED LID - OUTPUT ACT 0
SI_SBIT(LED_VENT, 	SFR_P3, 3);	// LED VENT - OUTPUT ACT 0
SI_SBIT(C2D, 		SFR_P3, 7);	// NU - DIGITAL IN

#endif /* __PIN_NAMES_H__ */
