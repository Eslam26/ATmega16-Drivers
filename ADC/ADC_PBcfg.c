/*******************************************************************************************************
 *  [MODULE]      :      <ADC>                                                                         *
 *  [FILE NAME]   :      <ADC_PBcfg.c>                                                                 *
 *  [AUTHOR]      :      <Eslam EL-Naggar>                                                             *
 *  [DATE CREATED]:      <Dec 5, 2019>                                                                 *
 *  [Description} :      <Source file for ADC configuration struct>                                    *
 ******************************************************************************************************/


/*---------------------------------------------INCLUDES-----------------------------------------------*/
#include "ADC.h"



/*-------------------------------------CONFIGURATION STRUCTURE----------------------------------------*/
ADC_configType ADC_configStructure ={
		AREF_PIN_MODE_CONFIG,
		LEFT_ADJUST_RESULT_MODE_CONFIG,
		INPUT_CHANNEL_GAIN_SELECTION_MODE_CONFIG,
		ADC_AUTO_TRIGGER_MODE_CONFIG,
		ADC_INTERRUPT_ENABLE_MODE_CONFIG,
		DIVISION_FACTOR_CONFIG,
		ADC_AUTO_TRIGGER_SOURCE_MODE_CONFIG

};


