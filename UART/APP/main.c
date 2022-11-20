/*
 * main.c
 *
 *  Created on: Sep 15, 2022
 *      Author: AbdelRahman Atef
 */


///********************* Application on  UART ********************//


///*****************INCLUDES**********//
#include "main.h"      ///*** this is a header file to contain all includes of Application



int main ()
{
	///***************** Initialize UART **********//
	M_UART_void_UartInt();
	///***************** Initialize LCD To print data **********//
	H_LCD_Void_LCDInt();

	u8 Local_u8Value ;  //// Local variable to store data
    while (1)
       {
    	///*****************  UART Receiver  **********//
          M_UART_void_UartRx(&Local_u8Value);
       ///***************** LCD display character **********//
	      H_LCD_Void_LCDDisplayCharacter(Local_u8Value);
      ///// I used IF condition to clear screen
	      if ((Local_u8Value == 'c') || ( Local_u8Value == 'C'))
	      {
	    	  H_Lcd_void_LCDClear(); //// LCD clear
	      }
	      ///// delay for 5 sec
         _delay_ms(500);
       }


}

