# ATmega16-Drivers

## Content 

- [External Interrupts Driver](#external-interrupts-driver)
- [ADC Driver](#adc-driver)
- [SPI Driver](#spi-driver)


## External Interrupts Driver

### Directory Structure of the driver

![Directory Structure](https://github.com/Eslam26/ATmega16-Drivers/blob/master/media/EXTERNAL_INTERRUPTS_TREE.PNG)

- External_Interrupts.c : Main Source file of External Interrupts Driver
- External_Interrupts.h : Header file of External Interrupts Driver 
- External_Interrupts_PBcfg.c : Source file that contains the configuration structure of the driver
- External_Interrupts_Cfg: Header file that contains ATmega16 External Interrupts Driver configuration


### How to use 

* The configuration structure consists of three members; The first member is for INT0 configuration, The second member is for INT1 configuration and The third member for INT2 configuration. 
```C
typedef struct {
	E_Interrupts_INT0_configType INT0_configType;
	E_Interrupts_INT1_configType INT1_configType;
	E_Interrupts_INT2_configType INT2_configType;
}E_Interrupts_configType;
```

* you will find these preproccesors macros in External_Interrupts_Cfg.c file
```C
#define INT0_CONFIGURATION_MODE_CONFIG INT0_DEFAULT_MODE
#define INT1_CONFIGURATION_MODE_CONFIG INT1_DEFAULT_MODE
#define INT2_CONFIGURATION_MODE_CONFIG INT2_DEFAULT_MODE
```
* by default, each external interrupt is configured to excutes its ISR on every rising edge happens
* you can change this default mode with your configured according to te below table

  | Excutes its ISR on |    INT0_CONFIGURATION_MODE_CONFIG  |   INT1_CONFIGURATION_MODE_CONFIG  | INT2_CONFIGURATION_MODE_CONFIG|
  |--------------------|-----------------------------|----------------------------|--------------------------
  | On low level       | LOW_LEVEL_INT0              | LOW_LEVEL_INT1             |                         |
  | Any logical change | ANY_CHANGE_INT0             | ANY_CHANGE_INT1            |                         |
  | Falling Edge       | FALLING_EDGE_INT0           | FALLING_EDGE_INT1          | FALLING_EDGE_INT2       |
  | Rising Edge        | RISING_EDGE_INT0            | RISING_EDGE_INT1           | RISING_EDGE_INT2        |
  | OFF                | OFF_INT0                    | OFF_INT1                   | OFF_INT2                |
  
  * Example: If you want to configure INT0  to excutes its ISR on Any logical change and INT2 on RISING EDGE and turn off INT1
    - The preproccesors macros will be 
    ```C
    #define INT0_CONFIGURATION_MODE_CONFIG ANY_CHANGE_INT0
    #define INT1_CONFIGURATION_MODE_CONFIG OFF_INT1
    #define INT2_CONFIGURATION_MODE_CONFIG RISING_EDGE_INT2
    ```
* After that, you have to include the "External_Interrupts.h" file
* Then you have to intialize the driver by calling this function
```C
ExternalInterrupts_init(&interruptsConfig);
```
* Finally you have to set your callBack functions by calling this function

  * For INT0 callBack Function
  
  ```C
  ExternalInterrupts_INT0_setCallBack(<address of the function that you want to excute when the interrupt event occurs>);
  ```
  * For INT1 callBack Function
  
  ```C
  ExternalInterrupts_INT1_setCallBack(<address of the function that you want to excute when the interrupt event occurs>);
  ```

  * For INT2 callBack Function
  
  ```C
  ExternalInterrupts_INT2_setCallBack(<address of the function that you want to excute when the interrupt event occurs>);
  ```
  
## ADC Driver

### Directory Structure of the driver

![Directory Structure](https://github.com/Eslam26/ATmega16-Drivers/blob/master/media/ADC_TREE.PNG)

- ADC.c : Main Source file of ADC Driver
- ADC.h : Header file of ADC Driver 
- ADC_PBcfg.c : Source file that contains the configuration structure of the driver
- ADC_Cfg: Header file that contains ATmega16 ADC Driver configuration
- LCD.c : Source file of LCD Driver
- LCD.h : Header file of LCD Driver

### How to use 

* The configuration structure consists of seven members:

	1. Configuration of ADC Reference
	2. Configuration of Left Adjust Result Mode
	3. Configuration of Input Channels and Gain selections
	4. Configuration of Auto Trigger Mode
	5. Configuration of Interrupt Mode
	6. Configuration of ADC Prescaler
	7. Configuration of Auto Trigger Source
	
```C
typedef struct {
	ADC_Reference_Selection referenceSelectionConfig;
	ADC_LEFT_ADJUST_RESULT_MODE leftAdjustResultModeConfig;
	ADC_Input_Channel_and_Gain_Selections inputChannelGainSelectionsConfig;
	ADC_AUTO_TRIGGER_MODE autoTriggerModeConfig;
	ADC_INTERRUPT_ENABLE_MODE interruptEnableModeConfig;
	ADC_PRESCALER prescalerConfig;
	ADC_AUTO_TRIGGER_SOURCE autoTriggerSourceConfig;
}ADC_configType;
```

* you will find these preproccesors macros in ADC_Cfg.c file

```C
#define AREF_PIN_MODE_CONFIG DEFAULT_AREF_PIN_MODE
#define LEFT_ADJUST_RESULT_MODE_CONFIG DEFAULT_LEFT_ADJUST_RESULT_MODE
#define INPUT_CHANNEL_GAIN_SELECTION_MODE_CONFIG DEFAULT_INPUT_CHANNEL_GAIN_SELECTION_MODE
#define ADC_AUTO_TRIGGER_MODE_CONFIG DEFAULT_ADC_AUTO_TRIGGER_MODE
#define ADC_INTERRUPT_ENABLE_MODE_CONFIG DEFAULT_ADC_INTERRUPT_ENABLE_MODE
#define DIVISION_FACTOR_CONFIG DEFAULT_DIVISION_FACTOR
#define ADC_AUTO_TRIGGER_SOURCE_MODE_CONFIG DEFAULT_ADC_AUTO_TRIGGER_SOURCE_MODE
```
* by default, ADC Driver is configured on

	1. Configuration of ADC Reference : AREF, Internal Vref turned off 
  	2. Configuration of Left Adjust Result Mode : OFF
  	3. Configuration of Input Channels and Gain selections : SINGLE_ENDED_INPUT_ADC0
  	4. Configuration of Auto Trigger Mode : OFF
  	5. Configuration of Interrupt Mode : OFF
  	6. Configuration of ADC Prescaler : F_CPU/4
  	7. Configuration of Auto Trigger Source : Free Running Mode

* you can change this default mode with your configuration according to the following tables

	1. Configuration of ADC Reference
	
  |                                                                         |           AREF_PIN_MODE_CONFIG                       |
  |-------------------------------------------------------------------------|------------------------------------------------------|
  | AREF, Internal Vref turned off                                          | AREF_ON_INTERNAL_VREF_OFF                            | 
  | AVCC with external capacitor at AREF pin                                | AVCC_WITH_EXTERNAL_CAPACITOR_AT_AREF_PIN             | 
  | Internal 2.56V Voltage Reference with external capacitor at AREF pin    | INTERNAL_VOLTAGE_WITH_EXTERNAL_CAPACITOR_AT_AREF_PIN |
  
  
  	2. Configuration of Left Adjust Result Mode
	
	
  |              Left Adjust Result Mode          |           LEFT_ADJUST_RESULT_MODE_CONFIG             |
  |-----------------------------------------------|------------------------------------------------------|
  | OFF                                           | LEFT_ADJUST_RESULT_MODE_OFF                          | 
  | ON                                            | LEFT_ADJUST_RESULT_MODE_ON                           | 
  
	
 	3. Configuration of Input Channels and Gain selections
	
	
  |INPUT_CHANNEL_GAIN_SELECTION_MODE_CONFIG|   Single Ended Input  |  Postive Differential Input    | Negative Differential Input |
  |---------------------------------|-----------------------|-----------------------------------|-----------------------------|
  |SINGLE_ENDED_INPUT_ADC0          | ADC0                  |                                   |                             |
  |SINGLE_ENDED_INPUT_ADC1          | ADC1                  |                                   |                             |
  |SINGLE_ENDED_INPUT_ADC2          | ADC2                  |                                   |                             |
  |SINGLE_ENDED_INPUT_ADC3          | ADC3                  |                                   |                             |
  |SINGLE_ENDED_INPUT_ADC4          | ADC4                  |                                   |                             |
  |SINGLE_ENDED_INPUT_ADC5          | ADC5                  |                                   |                             |
  |SINGLE_ENDED_INPUT_ADC6          | ADC6                  |                                   |                             |
  |SINGLE_ENDED_INPUT_ADC7          | ADC7                  |                                   |                             |
  |ADC0_NEGATIVE_DIFFERENTIAL_ADC0_POSTIVE_DIFFERENTIAL_INPUT_GAIN_10 | |ADC0|ADC0|
  |ADC0_NEGATIVE_DIFFERENTIAL_ADC1_POSTIVE_DIFFERENTIAL_INPUT_GAIN_10 | |ADC1|ADC0|
  |ADC0_NEGATIVE_DIFFERENTIAL_ADC0_POSTIVE_DIFFERENTIAL_INPUT_GAIN_200| |ADC0|ADC0|
  |ADC0_NEGATIVE_DIFFERENTIAL_ADC1_POSTIVE_DIFFERENTIAL_INPUT_GAIN_200| |ADC1|ADC0|
  |ADC2_NEGATIVE_DIFFERENTIAL_ADC2_POSTIVE_DIFFERENTIAL_INPUT_GAIN_10 | |ADC2|ADC2|
  |ADC2_NEGATIVE_DIFFERENTIAL_ADC3_POSTIVE_DIFFERENTIAL_INPUT_GAIN_10 | |ADC3|ADC2|
  |ADC2_NEGATIVE_DIFFERENTIAL_ADC2_POSTIVE_DIFFERENTIAL_INPUT_GAIN_200| |ADC2|ADC2|
  |ADC2_NEGATIVE_DIFFERENTIAL_ADC3_POSTIVE_DIFFERENTIAL_INPUT_GAIN_200| |ADC3|ADC2|
  |ADC1_NEGATIVE_DIFFERENTIAL_ADC0_POSTIVE_DIFFERENTIAL_INPUT_GAIN_1  | |ADC0|ADC1|
  |ADC1_NEGATIVE_DIFFERENTIAL_ADC1_POSTIVE_DIFFERENTIAL_INPUT_GAIN_1  | |ADC1|ADC1|
  |ADC1_NEGATIVE_DIFFERENTIAL_ADC2_POSTIVE_DIFFERENTIAL_INPUT_GAIN_1  | |ADC2|ADC1|
  |ADC1_NEGATIVE_DIFFERENTIAL_ADC3_POSTIVE_DIFFERENTIAL_INPUT_GAIN_1  | |ADC3|ADC1|
  |ADC1_NEGATIVE_DIFFERENTIAL_ADC4_POSTIVE_DIFFERENTIAL_INPUT_GAIN_1  | |ADC4|ADC1|
  |ADC1_NEGATIVE_DIFFERENTIAL_ADC5_POSTIVE_DIFFERENTIAL_INPUT_GAIN_1  | |ADC5|ADC1|
  |ADC1_NEGATIVE_DIFFERENTIAL_ADC6_POSTIVE_DIFFERENTIAL_INPUT_GAIN_1  | |ADC6|ADC1|
  |ADC1_NEGATIVE_DIFFERENTIAL_ADC7_POSTIVE_DIFFERENTIAL_INPUT_GAIN_1  | |ADC7|ADC1|
  |ADC2_NEGATIVE_DIFFERENTIAL_ADC0_POSTIVE_DIFFERENTIAL_INPUT_GAIN_1  | |ADC0|ADC2|
  |ADC2_NEGATIVE_DIFFERENTIAL_ADC1_POSTIVE_DIFFERENTIAL_INPUT_GAIN_1  | |ADC1|ADC2|
  |ADC2_NEGATIVE_DIFFERENTIAL_ADC2_POSTIVE_DIFFERENTIAL_INPUT_GAIN_1  | |ADC2|ADC2|
  |ADC2_NEGATIVE_DIFFERENTIAL_ADC3_POSTIVE_DIFFERENTIAL_INPUT_GAIN_1  | |ADC3|ADC2|
  |ADC2_NEGATIVE_DIFFERENTIAL_ADC4_POSTIVE_DIFFERENTIAL_INPUT_GAIN_1  | |ADC4|ADC2|
  |ADC2_NEGATIVE_DIFFERENTIAL_ADC5_POSTIVE_DIFFERENTIAL_INPUT_GAIN_1  | |ADC5|ADC2|
  |SINGLE_ENDED_INPUT_1_22_Volts                                      |1.22 volts|||
  |SINGLE_ENDED_INPUT_ZERO_Volts                                      |0 V |||
  
  
  	4. Configuration of Auto Trigger Mode
	
	
  |              Auto Trigger Mode                |           ADC_AUTO_TRIGGER_MODE_CONFIG               |
  |-----------------------------------------------|------------------------------------------------------|
  | OFF                                           | ADC_AUTO_TRIGGER_OFF                                 | 
  | ON                                            | ADC_AUTO_TRIGGER_ON                                  |
  
  	5. Configuration of Interrupt Mode
	
  |              Interrupt Mode                   |           ADC_INTERRUPT_ENABLE_MODE_CONFIG           |
  |-----------------------------------------------|------------------------------------------------------|
  | OFF                                           | ADC_INTERRUPT_ENABLE_OFF                             | 
  | ON                                            | ADC_INTERRUPT_ENABLE_ON                              |
  
  	6. Configuration of ADC Prescaler
	
  |              Division Factor                  |           DIVISION_FACTOR_CONFIG                     |
  |-----------------------------------------------|------------------------------------------------------|
  | 2                                             | DIVISION_FACTOR_2                                    | 
  | 4                                             | DIVISION_FACTOR_4                                    |
  | 8                                             | DIVISION_FACTOR_8                                    |
  | 16                                            | DIVISION_FACTOR_16                                   |
  | 32                                            | DIVISION_FACTOR_32                                   |
  | 64                                            | DIVISION_FACTOR_64                                   |
  | 128                                           | DIVISION_FACTOR_128                                  |
  
  	7. Configuration of Auto Trigger Source
	
  |              Trigger Source                   |           ADC_AUTO_TRIGGER_SOURCE_MODE_CONFIG        |
  |-----------------------------------------------|------------------------------------------------------|
  |Free Running mode                              | FREE_RUNNING_MODE                                    | 
  |Analog Comparator                              | ANALOG_COMPARTOR                                     |
  |External Interrupt Request 0                   | EXTERNAL_INTERRUPT_REQUEST_ZERO                      |
  |Timer/Counter0 Compare Match                   | TIMER_COUNTER_0_COMPARE_MATCH                        |
  |Timer/Counter0 Overflow                        | TIMER_COUNTER_0_OVF                                  |
  |Timer/Counter1 Compare Match B                 | TIMER_COUNTER_1_COMPARE_MATCH_B                      |
  |Timer/Counter1 Overflow                        | TIMER_COUNTER_1_OVF                                  |
  |Timer/Counter1 Capture Event                   | TIMER_COUNTER_1_CAPTURE_EVENT                        |
      
		
  * Example: If you want to configure ADC driver on the following:
  
  	1. Configuration of ADC Reference :  AREF, Internal Vref turned off
  	2. Configuration of Left Adjust Result Mode : OFF
  	3. Configuration of Input Channels and Gain selections : Single Ended Input (ADC0)
  	4. Configuration of Auto Trigger Mode : OFF
  	5. Configuration of Interrupt Mode : OFF
  	6. Configuration of ADC Prescaler : F_CPU/8
  	7. Configuration of Auto Trigger Source : free running mode
    - The preproccesors macros will be 
	```C
	#define AREF_PIN_MODE_CONFIG AREF_ON_INTERNAL_VREF_OFF
	#define LEFT_ADJUST_RESULT_MODE_CONFIG LEFT_ADJUST_RESULT_MODE_OFF
	#define INPUT_CHANNEL_GAIN_SELECTION_MODE_CONFIG SINGLE_ENDED_INPUT_ADC0
	#define ADC_AUTO_TRIGGER_MODE_CONFIG ADC_AUTO_TRIGGER_OFF
	#define ADC_INTERRUPT_ENABLE_MODE_CONFIG ADC_INTERRUPT_ENABLE_OFF
	#define DIVISION_FACTOR_CONFIG DIVISION_FACTOR_8
	#define ADC_AUTO_TRIGGER_SOURCE_MODE_CONFIG FREE_RUNNING_MODE
	```
* After that, you have to include the "ADC.h" file
* Then you have to intialize the driver by calling this function
```C
ADC_init(&ADC_configStructure);
```
* Finally, if you enabled ADC Interrupt Mode, so you have to set your callback function
  
  ```C
  ADC_setCallBack(<address of the function that you want to excute when the ADC conversion completes>);
  ```

## SPI Driver

### Directory Structure of the driver

![Directory Structure](https://github.com/Eslam26/ATmega16-Drivers/blob/master/media/SPI_TREE.PNG)

- SPI.c : Main Source file of SPI Driver
- SPI.h : Header file of SPI Driver 
- SPI_PBcfg.c : Source file that contains the configuration structure of the driver
- SPI_Cfg: Header file that contains ATmega16 SPI Driver configuration


### How to use 

* The configuration structure consists of six members:

	1. Configuration of Interrupt Mode
	2. Configuration of Data Order Mode
	3. Configuration of Master/Slave Selection
	4. Configuration of SPI TRANSMISSION MODE
	5. Configuration of Clock Prescaler
	6. Configuration of Double Speed Bit Mode
	
```C
typedef struct{
	SPI_INTERRUPT_ENABLE_MODE interruptEnableModeConfig;
	SPI_DATA_ORDER_MODE dataOrderModeConfig;
	SPI_MASTER_SLAVE_SELECT masterSlaveSelectionConfig;
	SPI_DATA_MODES dataModesConfig;
	SPI_CLOCK_PRESCALER clockPrescalerConfig;
	SPI_DOUBLE_SPEED_BIT_MODE doubleSpeedBitModeConfig;
}SPI_configType;
```

* you will find these preproccesors macros in SPI_Cfg.c file

```C
#define SPI_INTERRUPT_MODE_CONFIG DEFAULT_SPI_INTERRUPT_MODE
#define SPI_DATA_ORDER_CONFIG DEFAULT_SPI_DATA_ORDER
#define SPI_MASTER_SLAVE_CONFIG DEFAULT_SPI_MASTER_SLAVE
#define SPI_DATA_MODE_CONFIG DEFAULT_SPI_DATA_MODE
#define SPI_CLOCK_PRESCALER_SELECTOR_CONFIG DEFAULT_SPI_CLOCK_PRESCALER_SELECTOR
#define SPI_DOUBLE_SPEED_BIT_CONFIG DEFAULT_SPI_DOUBLE_SPEED_BIT
```

* by default, SPI Driver is configured on

	1. Configuration of Interrupt Mode: Disables
	2. Configuration of Data Order Mode: Most Significant Bit transmitted first
	3. Configuration of Master/Slave Selection: Master
	4. Configuration of SPI TRANSMISSION MODE: SPI_MODE_0
	5. Configuration of Clock Prescaler: F_CPU/4
	6. Configuration of Double Speed Bit Mode: OFF

* you can change this default mode with your configurations according to te below table

	1.  Configuration of Interrupt Mode
	
  |              Interrupt Mode                   |           SPI_INTERRUPT_MODE_CONFIG                  |
  |-----------------------------------------------|------------------------------------------------------|
  | OFF                                           | SPI_INTERRUPT_ENABLE_OFF                             | 
  | ON                                            | SPI_INTERRUPT_ENABLE_ON                              |
  
  	2. Configuration of Data Order Mode

  |              Data Order Mode                  |           SPI_DATA_ORDER_CONFIG                      |
  |-----------------------------------------------|------------------------------------------------------|
  |Most Significant Bit transmitted first         | SPI_MSB_TRANSMITED_FIRST                             | 
  |Least Significant Bit transmitted first        | SPI_LSB_TRANSMITED_FIRST                             |
  
  	3. Configuration of Master/Slave Selection
	
  |              Master/Slave Selection           |           SPI_MASTER_SLAVE_CONFIG                    |
  |-----------------------------------------------|------------------------------------------------------|
  |Master                                         | MASTER_SPI_MODE                                      | 
  |Slave                                          | SLAVE_SPI_MODE                                       |
  
  	
  	4. Configuration of SPI TRANSMISSION MODE
	
  |              SPI MODE (STANDARD)              |           SPI_DATA_MODE_CONFIG                    |
  |-----------------------------------------------|------------------------------------------------------|
  |Mode 0                                         | SPI_MODE_0                                           | 
  |Mode 1                                         | SPI_MODE_1                                           |
  |Mode 2                                         | SPI_MODE_2                                           |
  |Mode 3                                         |SPI_MODE_3                                            |
  
  	5. Configuration of Clock Prescaler

  |              CLOCK Prescaler                  |           SPI_CLOCK_PRESCALER_SELECTOR_CONFIG        |
  |-----------------------------------------------|------------------------------------------------------|
  | 2                                             | F_OSC_2                                              | 
  | 4                                             | F_OSC_4                                              |
  | 8                                             | F_OSC_8                                              |
  | 16                                            | F_OSC_16                                             |
  | 32                                            | F_OSC_32                                             |
  | 64                                            | F_OSC_64                                             |
  | 128                                           | F_OSC_128                                            |
  
  	6. Configuration of Double Speed Bit Mode
	
  |              Double Speed Bit Mode            |           SPI_DOUBLE_SPEED_BIT_CONFIG                |
  |-----------------------------------------------|------------------------------------------------------|
  |OFF                                            | SPI_DOUBLE_SPEED_BIT_MODE_OFF                        | 
  |ON                                             | SPI_DOUBLE_SPEED_BIT_MODE_ON                         |
  
  
  * Example: If you want to configure SPI driver on the following:
  
	1. Configuration of Interrupt Mode: Disables
	2. Configuration of Data Order Mode: Most Significant Bit transmitted first
	3. Configuration of Master/Slave Selection: Master
	4. Configuration of SPI TRANSMISSION MODE: SPI_MODE_0
	5. Configuration of Clock Prescaler: F_CPU/4
	6. Configuration of Double Speed Bit Mode: OFF
	
    - The preproccesors macros will be 
	```C
	#define SPI_INTERRUPT_MODE_CONFIG SPI_INTERRUPT_ENABLE_OFF
	#define SPI_DATA_ORDER_CONFIG SPI_MSB_TRANSMITED_FIRST
	#define SPI_MASTER_SLAVE_CONFIG MASTER_SPI_MODE
	#define SPI_DATA_MODE_CONFIG SPI_MODE_0
	#define SPI_CLOCK_PRESCALER_SELECTOR_CONFIG F_OSC_4
	#define SPI_DOUBLE_SPEED_BIT_CONFIG SPI_DOUBLE_SPEED_BIT_MODE_OFF
	```
	
* After that, you have to include the "SPI.h" file
* Then you have to intialize the driver by calling this function
```C
SPI_init(&SPI_configStructure);
```
* Finally, if you enabled SPI Interrupt Mode, so you have to set your callback function
  
  ```C
  SPI_setCallBack(<address of the function that you want to excute when the SPI transmission completes>);
  ```
  




