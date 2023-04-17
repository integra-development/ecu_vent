/**************************************************************************************************
 * @file        check_sysetm.c
 * @brief       CheckSystem process
 * @author      Marko Svetak
 * @version     v0.5.0
 * @copyright   Integra d.o.o.
 *************************************************************************************************/
#ifndef __CHECK_SYSTEM_H__
#define __CHECK_SYSTEM_H__



#include "timers.h"
#include "processes/parameters.h"


//-------------------------------------------------------------------------------------------------
// CPU reset
//-------------------------------------------------------------------------------------------------
void resetPCToZero(void) {
	((void (code *)(void)) 0) ();
}
void resetCPU(void) {
	SFRPAGE = 0x00;
    RSTSRC = RSTSRC_SWRSF__SET | RSTSRC_PORSF__SET;
}


//-------------------------------------------------------------------------------------------------
// checkProcess TASK
// ------------------------------------------------------------------------------------------------
void checkProcess(void) {
	if(checkTimer > 2500) {
		switch(CHECK_PROCESS_STATE) {
			case 1: {

				if (millis - checkTimer > 5000){
				CHECK_PROCESS_STATE++;
				}
				break;
			}

			default: {
				CHECK_PROCESS_STATE = 1;
				checkTimer = 0;
				break;
			}
		}
	}

}

#endif //__CHECK_SYSTEM_H__
