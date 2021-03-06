/*******************************************************************************************************
 *  [MODULE]      :      <External Interrupts>                                                                         *
 *  [FILE NAME]   :      <External_Interrupts.c>                                                                       *
 *  [AUTHOR]      :      <Eslam EL-Naggar>                                                             *
 *  [DATE CREATED]:      <Dec 4, 2019>                                                                 *
 *  [Description} :      <source file for ATmega16 External Interrupts Driver>                                         *
 ******************************************************************************************************/

/*----------------------------------------INCLUDES----------------------------------------------------*/

#include "External_Interrupts.h"

/*--------------------------------------DEFINITIONS---------------------------------------------------*/
#define NULL_PTR ((void*)0)

/*------------------------------------GLOBAL VARIABLES------------------------------------------------*/
static volatile void (*	g_INT0_callBackPtr)(void) = NULL_PTR;
static volatile void (*	g_INT1_callBackPtr)(void) = NULL_PTR;
static volatile void (*	g_INT2_callBackPtr)(void) = NULL_PTR;

/*----------------------------------ISR DEFINITIONS---------------------------------------------------*/
ISR(INT0_vect)
{
	if (g_INT0_callBackPtr != NULL_PTR) {
			(*g_INT0_callBackPtr)();
}
}

ISR(INT1_vect)
{
	if (g_INT1_callBackPtr != NULL_PTR) {
			(*g_INT1_callBackPtr)();
}

}

ISR(INT2_vect)
{
	if (g_INT2_callBackPtr != NULL_PTR) {
			(*g_INT2_callBackPtr)();
}

}
/*--------------------------------------FUNCTIONS DEFINITIONS----------------------------------------*/

/*----------------------------------------------------------------------------------------------------
 [Function Name]:  ExternalInterrupts_init
 [Description]  :  This function is responsible for initialize external interrupts
 [Returns]      :  This function returns void
 ----------------------------------------------------------------------------------------------------*/
void ExternalInterrupts_init(
		E_Interrupts_configType * E_Interrupts_configType_Ptr) {
	SREG   &= ~(ONE<<I_BIT);      // Disable interrupts by clearing I-bit
	if (E_Interrupts_configType_Ptr->INT0_configType == OFF_INT0) {
		GICR &= ~(ONE<<INT0);
	} else {

		CLEAR_BIT(INT0_DIRECTION_PORT,INT0_PORT_PIN);   // Configure INT0 pin as input pin
		GICR |= (ONE<<INT0);  // Enable external interrupt pin INT0
		MCUCR = (MCUCR & 0b11111100) | ((E_Interrupts_configType_Ptr->INT0_configType & 0b00000011)<<(ISC00));

	}
	if (E_Interrupts_configType_Ptr->INT1_configType == OFF_INT1) {
		GICR &= ~(ONE<<INT1);

	} else {
		CLEAR_BIT(INT1_DIRECTION_PORT,INT1_PORT_PIN);   // Configure INT1 pin as input pin
		GICR |= (ONE<<INT1);  // Enable external interrupt pin INT1
		MCUCR = (MCUCR & 0b11111100) | ((E_Interrupts_configType_Ptr->INT1_configType & 0b00000011)<<(ISC10));

	}

	if (E_Interrupts_configType_Ptr->INT2_configType == OFF_INT2) {
		GICR &= ~(ONE<<INT2);
	} else {
		CLEAR_BIT(INT2_DIRECTION_PORT,INT2_PORT_PIN); // Configure INT2 pin as input pin
		GICR   |= (ONE<<INT2);	// Enable external interrupt pin INT2
		MCUCSR = (MCUCSR & 0b10111111) | ((E_Interrupts_configType_Ptr->INT2_configType & 0b00000001)<<(ISC2));
	}

	SREG   |= (ONE<<I_BIT);
}

/*----------------------------------------------------------------------------------------------------
 [Function Name]:  ExternalInterrupts_Deinit
 [Description]  :  This function is responsible for deinitilization of external interrupts
 [Returns]      :  This function returns void
 ----------------------------------------------------------------------------------------------------*/
void ExternalInterrupts_Deinit()
{
	GICR &= ~(ONE<<INT0);
	GICR &= ~(ONE<<INT1);
	GICR &= ~(ONE<<INT2);
}


/*----------------------------------------------------------------------------------------------------
 [Function Name]:  ExternalInterrupts_INT0_setCallBack
 [Description]  :  This function is responsible for getting the address of the function which
 						will be executed when INT0 occurs
 [Returns]      :  This function returns void
 ----------------------------------------------------------------------------------------------------*/

void ExternalInterrupts_INT0_setCallBack(void (*INT0_setCallBack_Ptr)(void)) {
	g_INT0_callBackPtr = INT0_setCallBack_Ptr;
}

/*----------------------------------------------------------------------------------------------------
 [Function Name]:  ExternalInterrupts_INT1_setCallBack
 [Description]  :  This function is responsible for getting the address of the function which
 						will be executed when INT1 occurs
 [Returns]      :  This function returns void
 ----------------------------------------------------------------------------------------------------*/

void ExternalInterrupts_INT1_setCallBack(void (*INT1_setCallBack_Ptr)(void)) {
	g_INT1_callBackPtr = INT1_setCallBack_Ptr;
}

/*----------------------------------------------------------------------------------------------------
 [Function Name]:  ExternalInterrupts_INT2_setCallBack
 [Description]  :  This function is responsible for getting the address of the function which
 						will be executed when INT2 occurs
 [Returns]      :  This function returns void
 ----------------------------------------------------------------------------------------------------*/

void ExternalInterrupts_INT2_setCallBack(void (*INT2_setCallBack_Ptr)(void)) {
	g_INT2_callBackPtr = INT2_setCallBack_Ptr;
}

