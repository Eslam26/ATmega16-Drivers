/*******************************************************************************************************
 *  [MODULE]      :      <ADC>                                                                         *
 *  [FILE NAME]   :      <ADC_ModuleTest.c>                                                            *
 *  [AUTHOR]      :      <Eslam EL-Naggar>                                                             *
 *  [DATE CREATED]:      <Dec 5, 2019>                                                                 *
 *  [Description} :      <Source file for the ATmega16 ADC Driver Module Test>                         *
 ******************************************************************************************************/

#include "ADC.h"
#include "lcd.h"

int main(){
	DDRA &= ~(1<<0);
	ADC_init(&ADC_configStructure);
	LCD_init();
	LCD_clearScreen();


	while(1)
	{
		LCD_goToRowColumn(0,1);
		LCD_displayString("Reading: ");
		/*  display the potentiometer reading that is connected to ADC 0 */
		LCD_intgerToString(ADC_readChannel(0));
		LCD_displayString(" ");
		_delay_ms(1000);
		LCD_clearScreen();
	}

	return 0;
}


