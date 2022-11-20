/*
 * WDT_Priv.h
 *
 *  Created on: Nov 19, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef MCAL_WDT_WDT_PRIV_H_
#define MCAL_WDT_WDT_PRIV_H_

///***************** Macros **********//
///***************** WDT Registers  **********//
#define  WDTCR_REG    *((volatile u8 *)0X41)
#define  WDP0          0
#define  WDP1          1
#define  WDP2          2
#define  WDE           3
#define  WDTOE         4

#endif /* MCAL_WDT_WDT_PRIV_H_ */
