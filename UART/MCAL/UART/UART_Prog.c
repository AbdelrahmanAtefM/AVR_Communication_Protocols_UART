/*
 * UART_Prog.c
 *
 *  Created on: Nov 20, 2022
 *      Author: AbdelRahman Atef
 */

///***************** INCLIDES **********//
#include "UART_Int.h"

///***************** PROTOTYPES **********//

///***************** Function to initialize UART **********//
void M_UART_void_UartInt(void)
{

///***************** Select UART BAUD RATE **********//
   UBRRL_REG = UART_BAUD_RATE;
///***************** Select UART MODE **********//
#if   USART_MODE  ==  ASYNCHRONOUS
	////***** To Select  ASYNCHRONOUS clear UMSEL bit in UCSRC_REG ******//
	 ClrBit(UCSRC_REG ,UMSEL);
#elif USART_MODE  ==  SYNCHRONOUS
	 ////***** To Select  SYNCHRONOUS Set UMSEL bit in UCSRC_REG ******//
	 SetBit(UCSRC_REG ,UMSEL);
#endif

 ///***************** Select UART PARITY MODE **********//
#if     UART_PARITY_MODE == DISABLED
 ////***** To disable parity clear (UPM1 & UPM0) bits in UCSRC_REG ******//
   ClrBit(UCSRC_REG ,UPM0 );
   ClrBit(UCSRC_REG ,UPM1 );

#elif   UART_PARITY_MODE == EVEN_PARITY
////***** To disable EVEN_PARITY clear UPM0 and set UPM1 bits in UCSRC_REG ******//
     ClrBit(UCSRC_REG ,UPM0 );
     ClrBit(UCSRC_REG ,UPM1 );

#elif   UART_PARITY_MODE == ODD_PARITY
////***** To select ODD_PARITY set (UPM1 & UPM0) bits in UCSRC_REG ******//
     SetBit(UCSRC_REG ,UPM0 );
     SetBit(UCSRC_REG ,UPM1 );
#endif

 ///***************** Select UART Character size **********//
#if    UART_CHARACTER_SIZE == _5BITS
     //// Clear  UCSZ0 bit in UCSRC_REG
        ClrBit(UCSRC_REG ,UCSZ0 );
    ////  Clear  UCSZ1 bit in UCSRC_REG
        ClrBit(UCSRC_REG ,UCSZ1 );
	////  Clear  UCSZ2 bit in UCSRB_REG
        ClrBit(UCSRB_REG ,UCSZ2 );

#elif  UART_CHARACTER_SIZE == _6BITS
        //// Set    UCSZ0 bit in UCSRC_REG
        SetBit(UCSRC_REG ,UCSZ0 );
        //// Clear  UCSZ1 bit in UCSRC_REG
        ClrBit(UCSRC_REG ,UCSZ1 );
        //// Clear  UCSZ2 bit in UCSRB_REG
        ClrBit(UCSRB_REG ,UCSZ2 );

#elif  UART_CHARACTER_SIZE == _7BITS
        //// Clear  UCSZ0 bit in UCSRC_REG
        ClrBit(UCSRC_REG ,UCSZ0 );
        //// Set    UCSZ1 bit in UCSRC_REG
        SetBit(UCSRC_REG ,UCSZ1 );
        //// Clear  UCSZ2 bit in UCSRB_REG
        ClrBit(UCSRB_REG ,UCSZ2 );

#elif  UART_CHARACTER_SIZE == _8BITS
        //// Set   UCSZ0 bit in UCSRC_REG
        SetBit(UCSRC_REG ,UCSZ0 );
        //// set   UCSZ1 bit in UCSRC_REG
        SetBit(UCSRC_REG ,UCSZ1 );
        //// Clear UCSZ2 bit in UCSRB_REG
        ClrBit(UCSRB_REG ,UCSZ2 );

#elif  UART_CHARACTER_SIZE == _9BITS
        //// set  UCSZ0 bit in UCSRC_REG
        SetBit(UCSRC_REG ,UCSZ0 );
        //// set  UCSZ1 bit in UCSRC_REG
        SetBit(UCSRC_REG ,UCSZ1 );
        //// set  UCSZ2 bit in UCSRB_REG
        SetBit(UCSRB_REG ,UCSZ2 );
#endif

///***************** Select UART STOP BIT **********//
#if    UART_STOP_BIT  == ONE_BIT
        //// Clear USBS bit in UCSRC_REG
		ClrBit(UCSRC_REG ,USBS );
#elif  UART_STOP_BIT  == TWO_BIT
	    //// Clear USBS bit in UCSRC_REG
		SetBit(UCSRC_REG ,USBS );
#endif

////***** To enable TX and RX ******//
   // set TXEN in UCSRB_REG to enable TX
	SetBit(UCSRB_REG , TXEN);
  // set RXEN in UCSRB_REG to enable RX
	SetBit(UCSRB_REG , RXEN);
}
///*****************  UART Transmit Function **********//
void M_UART_void_UartTx(u8 Local_u8Data)
{
	UDR_REG = Local_u8Data;
	u32 Local_u32Counter = 0;
	while (Local_u32Counter < 500000)
	{
		Local_u32Counter ++;
		if (GetBit(UCSRA_REG , TXC) == 1)
	    break;
	}
}
///*****************  UART Receive  Function **********//
void M_UART_void_UartRx(u8* Local_u8PtrData)
{

		u16 Local_u32Counter =0;
		while (Local_u32Counter < 500000)
		{
			Local_u32Counter ++;
			if (GetBit(UCSRA_REG , RXC) == 1)
			break;
		}
	*Local_u8PtrData = UDR_REG ;
}
