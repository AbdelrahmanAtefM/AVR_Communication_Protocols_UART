/*
 * WDT_Prog.c
 *
 *  Created on: Nov 19, 2022
 *      Author: AbdelRahman Atef
 */

///***************** INCLUDES **********//
#include "WDT_Int.h"

///***************** Functions **********//
///
/////***function to enable WDT
void M_WDT_void_WDTEnable(void)
{
	///******* To enable WDT
	 // Set WDE bit in WDTCR_REG
    SetBit(WDTCR_REG , WDE);
    /// ***** To select (2.1s) window time
    SetBit(WDTCR_REG , WDP0);
    SetBit(WDTCR_REG , WDP1);
    SetBit(WDTCR_REG , WDP2);

}
void M_WDT_void_WDTDisable(void)
{
	 SetBit(WDTCR_REG , WDTOE);
	 ClrBit(WDTCR_REG , WDE);


}
void M_WDT_void_WDTRefresh(void)
{
   asm("WDR");
}
