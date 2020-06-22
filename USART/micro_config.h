/*******************************************************************************************************
 *  [MODULE]      :      <USART>                                                                         *
 *  [FILE NAME]   :      <micro_config.h>                                                              *
 *  [AUTHOR]      :      <Eslam EL-Naggar>                                                             *
 *  [DATE CREATED]:      <Dec 3, 2019>                                                                 *
 *  [Description} :      <Header file for ATmega16 Microcontroller config and libraries>               *
 ******************************************************************************************************/

#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_

#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif  

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#endif /* MICRO_CONFIG_H_ */
