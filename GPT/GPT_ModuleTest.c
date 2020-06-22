/*******************************************************************************************************
 *  [MODULE]      :      <GPT>                                                                         *
 *  [FILE NAME]   :      <GPT_ModuleTest.c>                                                            *
 *  [AUTHOR]      :      <Eslam EL-Naggar>                                                             *
 *  [DATE CREATED]:      <Dec 6, 2019>                                                                 *
 *  [Description} :      <source file for ATmega16 GPT Driver Module Test>                             *
 ******************************************************************************************************/

#include "GPT.h"

uint8 g_tick = 0;

void Timer_0_TestFunction(void) {
	g_tick++;

	PORTC ^= (1 << PC0); /* toggle PC0 Pin on each Timer interrupt execution */
}
int main(void) {
	uint8 counter = 0;
	DDRC |= 0x01;
	PORTC &= 0xFE;

	SREG |= (1 << 7); /* enable global interrupts in MC */

	/* initialize GPT driver */
	GPT_init(&GPT_configStructure);
	/* set GPT_0 callBack Function */
	GPT_0_setCallBack(Timer_0_TestFunction);
	/* enable GPT_0 */
	GPT_enable(0);
	while (1) {

	}
}
