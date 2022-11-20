/*
 * UART_Priv.h
 *
 *  Created on: Nov 20, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef MCAL_UART_UART_PRIV_H_
#define MCAL_UART_UART_PRIV_H_

///***************** Macros **********//

///***************** UART Registers **********//
#define UCSRA_REG      *((volatile u8 *)0x2B)
#define RXC            7
#define TXC            6

#define UCSRB_REG      *((volatile u8 *)0x2A)
#define RXEN           4
#define TXEN           3
#define UCSZ2          2

#define UCSRC_REG      *((volatile u8 *)0x40)
#define UMSEL          6
#define UPM0           4
#define UPM1           5
#define UCSZ0          1
#define UCSZ1          2
#define USBS           3

#define UDR_REG        *((volatile u8 *)0x2C)


#define UBRRL_REG      *((volatile u8 *)0x29)


///*****************  UART MODES **********//
#define ASYNCHRONOUS   1
#define SYNCHRONOUS    2

///*****************  UART PARITY MODES **********//
#define DISABLED      0
#define ODD_PARITY    1
#define EVEN_PARITY   2


///*****************  UART Character size **********//
#define _5BITS       5
#define _6BITS       6
#define _7BITS       7
#define _8BITS       8
#define _9BITS       9

///*****************  UART STOP BIT  **********//
#define ONE_BIT      1
#define TWO_BIT      2

#endif /* MCAL_UART_UART_PRIV_H_ */
