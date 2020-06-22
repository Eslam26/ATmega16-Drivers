/*******************************************************************************************************
 *  [MODULE]      :      <SPI>                                                                         *
 *  [FILE NAME]   :      <SPI_PBcfg.c>                                                                 *
 *  [AUTHOR]      :      <Eslam EL-Naggar>                                                             *
 *  [DATE CREATED]:      <Dec 4, 2019>                                                                 *
 *  [Description} :      <source file for ATmega16 SPI Driver that contains the configuration struct>  *
 ******************************************************************************************************/


/*--------------------------------------------INCLUDES------------------------------------------------*/
#include "SPI.h"


/*----------------------------------------CONFIGURATION STRUCTURE-------------------------------------*/
SPI_configType SPI_configStructure ={
		SPI_INTERRUPT_MODE_CONFIG,
		SPI_DATA_ORDER_CONFIG,
		SPI_MASTER_SLAVE_CONFIG,
		SPI_DATA_MODE_CONFIG,
		SPI_CLOCK_PRESCALER_SELECTOR_CONFIG,
		SPI_DOUBLE_SPEED_BIT_CONFIG
};


