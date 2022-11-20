/*
 * UART_Int.h
 *
 *  Created on: Nov 20, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

///***************** INCLUDES **********//

#include "UART_Cnfg.h"
#include "UART_Priv.h"
#include "STD_TYPS.h"
#include "BIT_MATH.h"

///***************** PROTOTYPES **********//
///***************** Function to initialize UART **********//
void M_UART_void_UartInt(void);
///*****************  UART Transmit Function **********//
void M_UART_void_UartTx(u8);
///*****************  UART Receive  Function **********//
void M_UART_void_UartRx(u8*);
///***************** Function to Select UART BUAD RATE   **********//
void M_UART_void_UartSetBuadRate(u32);

#endif /* MCAL_UART_UART_INT_H_ */
