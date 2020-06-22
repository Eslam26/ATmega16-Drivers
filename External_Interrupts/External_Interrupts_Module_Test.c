/*******************************************************************************************************
 *  [FILE NAME]   :      <External_Interrupts_Module_Test.c>                                           *
 *  [AUTHOR]      :      <Eslam EL-Naggar>                                                             *
 *  [DATE CREATED]:      <Dec 4, 2019>                                                                 *
 *  [Description} :      <source file for external interrupts module test>                             *
 ******************************************************************************************************/

/*----------------------------------------INCLUDES----------------------------------------------------*/

#include "External_Interrupts.h"

/*----------------------------------------DEFINITIONS-------------------------------------------------*/
#define INT0_LED_PORT PORTC
#define INT1_LED_PORT PORTC
#define INT2_LED_PORT PORTC

#define INT0_LED_DIRECTION_PORT DDRC
#define INT1_LED_DIRECTION_PORT DDRC
#define INT2_LED_DIRECTION_PORT DDRC

#define INT0_LED_PIN_NUMBER 0
#define INT1_LED_PIN_NUMBER 1
#define INT2_LED_PIN_NUMBER 2

#define MIILI_SEC_500 500
/*-------------------------------------Functions Definitions------------------------------------------*/
void INT0_CallBackFunction (void)
{
	/* toggling LED_0 */
	SET_BIT(INT0_LED_PORT,INT0_LED_PIN_NUMBER);
	_delay_ms(MIILI_SEC_500);
	CLEAR_BIT(INT0_LED_PORT,INT0_LED_PIN_NUMBER);

}

void INT1_CallBackFunction(void)
{
	/* toggling LED_1 */
	SET_BIT(INT1_LED_PORT,INT1_LED_PIN_NUMBER);
	_delay_ms(MIILI_SEC_500);
	CLEAR_BIT(INT1_LED_PORT,INT1_LED_PIN_NUMBER);
}

void INT2_CallBackFunction(void)
{
	/* toggling LED_2 */
	SET_BIT(INT2_LED_PORT,INT2_LED_PIN_NUMBER);
	_delay_ms(MIILI_SEC_500);
	CLEAR_BIT(INT2_LED_PORT,INT2_LED_PIN_NUMBER);
}
/*--------------------------------------Main Function-------------------------------------------------*/

int main (void)
{
	/* Call ExternalInterrupts_init function to initialize E_Interrupts settings */
	ExternalInterrupts_init(&interruptsConfig);
	/* Setting the CallBack Function when INT0 executes */
	ExternalInterrupts_INT0_setCallBack(INT0_CallBackFunction);
	/* Setting the CallBack Function when INT1 executes */
	ExternalInterrupts_INT1_setCallBack(INT1_CallBackFunction);
	/* Setting the CallBack Function when INT2 executes */
	ExternalInterrupts_INT2_setCallBack(INT2_CallBackFunction);

	/* Set LED Pins direction to be output pins */
	SET_BIT(INT0_LED_DIRECTION_PORT,INT0_LED_PIN_NUMBER);
	SET_BIT(INT1_LED_DIRECTION_PORT,INT1_LED_PIN_NUMBER);
	SET_BIT(INT2_LED_DIRECTION_PORT,INT2_LED_PIN_NUMBER);

	while(1)
	{

	}
	return 0;
}


