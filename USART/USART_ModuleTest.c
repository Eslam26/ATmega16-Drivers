/*******************************************************************************************************
 *  [MODULE]      :      <USART>                                                                       *
 *  [FILE NAME]   :      <USART_ModuleTest.c>                                                          *
 *  [AUTHOR]      :      <Eslam EL-Naggar>                                                             *
 *  [DATE CREATED]:      <Dec 5, 2019>                                                                 *
 *  [Description} :      <source file for ATmega16 USART Driver Module Test>                           *
 ******************************************************************************************************/

#include "USART.h"

int main(void)
{
	uint8 data;
	/* initialize USART Driver */
	USART_init(&USART_configStructure);
    while(1)
    {
    	/* Receive the byte */
		data = USART_recieveByte();
		/* Send the received byte */
		USART_sendByte(data);
    }
}
