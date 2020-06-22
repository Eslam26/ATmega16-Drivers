/*******************************************************************************************************
 *  [MODULE]      :      <SPI>                                                                         *
 *  [FILE NAME]   :      <SPI_ModuleTest.c>                                                            *
 *  [AUTHOR]      :      <Eslam EL-Naggar>                                                             *
 *  [DATE CREATED]:      <Dec 4, 2019>                                                                 *
 *  [Description} :      <source file for ATmega16 SPI Driver Module Test>                             *
 ******************************************************************************************************/

#include "SPI.h"

int main(void)
{
	SPI_init(&SPI_configStructure);
	CLEAR_BIT(DDRA,PA0); //configure PA0 as input pin
    while(1)
    {
		if(BIT_IS_SET(PINA,PA0)) //if switch is pressed
		{
			SPI_sendByte(1);
		}
		else
		{
			SPI_sendByte(0);
		}
    }
}
