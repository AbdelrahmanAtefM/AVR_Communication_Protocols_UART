/*
 * UART_Cnfg.h
 *
 *  Created on: Nov 20, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef MCAL_UART_UART_CNFG_H_
#define MCAL_UART_UART_CNFG_H_

/*
 * select USART Mode :
 * ASYNCHRONOUS
 * SYNCHRONOUS
 */
#define  USART_MODE    ASYNCHRONOUS

/*
 * select UART PARITY MODE:
 * DISABLED
 * EVEN_PARITY
 * ODD_PARITY
 */

#define UART_PARITY_MODE  DISABLED
/*
 * select UART CHARACTER SIZE:
 *  _5BITS
 *  _6BITS
 *  _7BITS
 *  _8BITS
 *  _9BITS
 */
#define UART_CHARACTER_SIZE    _8BITS

/*
 * Select UART_STOP_BIT :
 *  ONE_BIT
 *  TWO_BIT
 */
#define UART_STOP_BIT   ONE_BIT


/*
 * These choice from ATMEGA32 data sheet page 168 table 71
 * Select UART_BAUD_RATE for F_osc = 16.0000MHz :
 * Select 416 for  2400
 * Select 207 for  4800
 * Select 103 for  9600
 */

#define UART_BAUD_RATE    103


#endif  /* MCAL_UART_UART_CNFG_H_*/
