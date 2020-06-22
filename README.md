# ATmega16-Drivers

## Content 

- [External Interrupts Driver](#external-interrupts-driver)
- [GPT Driver](#gpt-driver)
- [ADC Driver](#adc-driver)
- [SPI Driver](#spi-driver)
- [TWI Driver](#twi-driver)
- [USART Driver](#usart-driver)


## External Interrupts Driver

### Directory Structure of the External Intrrupts Driver

![Directory Structure](https://github.com/Eslam26/ATmega16-Drivers/blob/master/media/EXTERNAL_INTERRUPTS_TREE.PNG)

- External_Interrupts.c : Main Source file of External Interrupts Driver
- External_Interrupts.h : Header file of External Interrupts Driver 
- External_Interrupts_PBcfg.c : Source file that contains the configuration structure of the driver
- External_Interrupts_Cfg: Header file that contains ATmega16 External Interrupts Driver configuration


### Configurations

1. In External_Interrupts_Cfg.c file, you will find these preproccesors macros. By default, each external interrupt is configured to excutes its ISR on every rising edge happens.
```C
#define INT0_CONFIGURATION_MODE_CONFIG INT0_DEFAULT_MODE
#define INT1_CONFIGURATION_MODE_CONFIG INT1_DEFAULT_MODE
#define INT2_CONFIGURATION_MODE_CONFIG INT2_DEFAULT_MODE
```

2. You can reconfigure the driver with your own configurations according to the table below

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
3. You have to include the "External_Interrupts.h" file in your application source file
4. You have to intialize the driver by calling this function
	```C
	ExternalInterrupts_init(&interruptsConfig);
	```
5. You have to set your callBack functions by calling this function

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
  
## GPT Driver

### Directory Structure of the GPT Driver

![Directory Structure](https://github.com/Eslam26/ATmega16-Drivers/blob/master/media/GPT_TREE.PNG)

- GPT.c : Main Source file of GPT Driver
- GPT.h : Header file of GPT Driver 
- GPT_PBcfg.c : Source file that contains the configuration structure of the driver
- GPT_Cfg: Header file that contains ATmega16 External GPT configuration

### Configurations

1. In GPT_Cfg.c file, you will find these preproccesors macros. By default, Timer 0 is the only timer that is configured. Timer 1 and 2 is not configured.
```C
#define GPT_0_CHANNEL_INTIALIZED_NOT_INTIALIZED_CONFIG DEFAULT_GPT_0_CHANNEL_INTIALIZED_NOT_INTIALIZED_CONFIG
#define GPT_0_TICKS_NUMBER_CONFIG DEFAULT_GPT_0_TICKS_NUMBER_CONFIG
#define GPT_0_CLOCK_PRESCALER_CONFIG DEFAULT_GPT_0_CLOCK_PRESCALER_CONFIG
#define GPT_0_CONTINOUS_ONESHOT_MODE_CONFIG DEFAULT_GPT_0_CONTINOUS_ONESHOT_MODE_CONFIG

#define GPT_1_CHANNEL_INTIALIZED_NOT_INTIALIZED_CONFIG DEFAULT_GPT_1_CHANNEL_INTIALIZED_NOT_INTIALIZED_CONFIG
#define GPT_1_TICKS_NUMBER_CONFIG DEFAULT_GPT_1_TICKS_NUMBER_CONFIG
#define GPT_1_CLOCK_PRESCALER_CONFIG DEFAULT_GPT_1_CLOCK_PRESCALER_CONFIG
#define GPT_1_CONTINOUS_ONESHOT_MODE_CONFIG DEFAULT_GPT_1_CONTINOUS_ONESHOT_MODE_CONFIG

#define GPT_2_CHANNEL_INTIALIZED_NOT_INTIALIZED_CONFIG DEFAULT_GPT_2_CHANNEL_INTIALIZED_NOT_INTIALIZED_CONFIG
#define GPT_2_TICKS_NUMBER_CONFIG DEFAULT_GPT_2_TICKS_NUMBER_CONFIG
#define GPT_2_CLOCK_PRESCALER_CONFIG DEFAULT_GPT_2_CLOCK_PRESCALER_CONFIG
#define GPT_2_CONTINOUS_ONESHOT_MODE_CONFIG DEFAULT_GPT_2_CONTINOUS_ONESHOT_MODE_CONFIG
```

2. You can reconfigure the driver with your own configurations according to the tables below

	1. Configuration of GPT Channel Intialization, you have to set the timer channel that you want to use to Intialized value
	
  	|                    |    GPT_x_CHANNEL_INTIALIZED_NOT_INTIALIZED_CONFIG |
  	|--------------------|---------------------------------------------------|
  	| Intialized         | GPT_CHANNEL_INTIALIZED                            |
  	| Not Intialized     | GPT_CHANNEL_NOT_INTIALIZED                        | 
  
  	2. Configuration of GPT Channel Ticks Number
	
  	|                    |    GPT_x_TICKS_NUMBER_CONFIG                      |
  	|--------------------|---------------------------------------------------|
  	| Timer 0            | 0.....256                                         |
  	| Timer 1            | 0.....65536                                       |
  	| Timer 2            | 0.....256                                         |
  
  	3. Configuration of GPT Channel Clock Prescaler 
	
	|                                |    GPT_x_CLOCK_PRESCALER_CONFIG                   |
  	|--------------------------------|---------------------------------------------------|
  	| F_CPU/8                        | PRESCALER_8                                       |
  	| F_CPU/64                       | PRESCALER_64                                      |
  	| F_CPU/256                      | PRESCALER_256                                     |
	| F_CPU/1024                     | PRESCALER_1024                                    |
	| External Source on Falling Edge| PRESCALER_EXTERNAL_SOURCE_FALLING_EDGE            |
	| External Source on Rising Edge | PRESCALER_EXTERNAL_SOURCE_RISING_EDGE             |
	
	
	4. Configuration of GPT Channel Running Mode
	
	|                    |    GPT_x_CONTINOUS_ONESHOT_MODE_CONFIG                    |
  	|--------------------|-----------------------------------------------------------|
  	| One Shot Mode      | GPT_CH_MODE_ONESHOT                                       |
  	| Continous Mode     | GPT_CH_MODE_CONTINUOUS                                    |
	
	* Example: If you want to configure Timer 1 on: 
		1. Ticks Number: 100
		2. Clock Prescaler: F_CPU/8
		3. Running Mode: Continous mode 
	The preprocessor macros of Timer 1 will be:
	```c
	#define GPT_1_CHANNEL_INTIALIZED_NOT_INTIALIZED_CONFIG GPT_CHANNEL_INTIALIZED
	#define GPT_1_TICKS_NUMBER_CONFIG 100
	#define GPT_1_CLOCK_PRESCALER_CONFIG PRESCALER_8
	#define GPT_1_CONTINOUS_ONESHOT_MODE_CONFIG GPT_CH_MODE_CONTINUOUS
	```
	
3. You have to include the "GPT.h" file in your application source file
4. You have to intialize the driver by calling this function
	```C
	GPT_init(&GPT_configStructure);
	```
5. You have to set your callBack functions by calling this function

	* Timer 0:
	```C
	GPT_0_setCallBack(<address of the function that you want to excute when timer 0 compare match event occurs>);
	```

	* Timer 1:
	```C
	GPT_1_setCallBack(<address of the function that you want to excute when timer 1 compare match event occurs>);
	```
	
	
	* Timer 2:
	```C
	GPT_2_setCallBack(<address of the function that you want to excute when timer 2 compare match event occurs>);
	```
	
## ADC Driver

### Directory Structure of the ADC Driver

![Directory Structure](https://github.com/Eslam26/ATmega16-Drivers/blob/master/media/ADC_TREE.PNG)

- ADC.c : Main Source file of ADC Driver
- ADC.h : Header file of ADC Driver 
- ADC_PBcfg.c : Source file that contains the configuration structure of the driver
- ADC_Cfg: Header file that contains ATmega16 ADC Driver configuration
- LCD.c : Source file of LCD Driver just to display the data 
- LCD.h : Header file of LCD Driver

### Configurations 

1. In ADC_Cfg.c file, you will find these preproccesors macros. By default, ADC Driver is configured on:

	1. Configuration of ADC Reference : AREF, Internal Vref turned off 
  	2. Configuration of Left Adjust Result Mode : OFF
  	3. Configuration of Input Channels and Gain selections : SINGLE_ENDED_INPUT_ADC0
  	4. Configuration of Auto Trigger Mode : OFF
  	5. Configuration of Interrupt Mode : OFF
  	6. Configuration of ADC Prescaler : F_CPU/4
  	7. Configuration of Auto Trigger Source : Free Running Mode

	```C
	#define AREF_PIN_MODE_CONFIG DEFAULT_AREF_PIN_MODE
	#define LEFT_ADJUST_RESULT_MODE_CONFIG DEFAULT_LEFT_ADJUST_RESULT_MODE
	#define INPUT_CHANNEL_GAIN_SELECTION_MODE_CONFIG DEFAULT_INPUT_CHANNEL_GAIN_SELECTION_MODE
	#define ADC_AUTO_TRIGGER_MODE_CONFIG DEFAULT_ADC_AUTO_TRIGGER_MODE
	#define ADC_INTERRUPT_ENABLE_MODE_CONFIG DEFAULT_ADC_INTERRUPT_ENABLE_MODE
	#define DIVISION_FACTOR_CONFIG DEFAULT_DIVISION_FACTOR
	#define ADC_AUTO_TRIGGER_SOURCE_MODE_CONFIG DEFAULT_ADC_AUTO_TRIGGER_SOURCE_MODE
	```

2. You can reconfigure the driver with your own configurations according to the tables below

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
3. You have to include the "ADC.h" file in your application source file
4. You have to intialize the driver by calling this function
	```C
	ADC_init(&ADC_configStructure);
	```
5. If you enabled ADC Interrupt Mode, you have to set your callBack function by calling this function
  
  	```C
  	ADC_setCallBack(<address of the function that you want to excute when the ADC conversion completes>);
  	```

## SPI Driver

### Directory Structure of the SPI driver

![Directory Structure](https://github.com/Eslam26/ATmega16-Drivers/blob/master/media/SPI_TREE.PNG)

- SPI.c : Main Source file of SPI Driver
- SPI.h : Header file of SPI Driver 
- SPI_PBcfg.c : Source file that contains the configuration structure of the driver
- SPI_Cfg: Header file that contains ATmega16 SPI Driver configuration


### Configurations 

1. In SPI_Cfg.c file, you will find these preproccesors macros. By default, SPI Driver is configured on:
	1. Configuration of Interrupt Mode: OFF
	2. Configuration of Data Order Mode: Most Significant Bit transmitted first
	3. Configuration of Master/Slave Selection: Master
	4. Configuration of SPI TRANSMISSION MODE: SPI_MODE_0
	5. Configuration of Clock Prescaler: F_CPU/4
	6. Configuration of Double Speed Bit Mode: OFF

	```C
	#define SPI_INTERRUPT_MODE_CONFIG DEFAULT_SPI_INTERRUPT_MODE
	#define SPI_DATA_ORDER_CONFIG DEFAULT_SPI_DATA_ORDER
	#define SPI_MASTER_SLAVE_CONFIG DEFAULT_SPI_MASTER_SLAVE
	#define SPI_DATA_MODE_CONFIG DEFAULT_SPI_DATA_MODE
	#define SPI_CLOCK_PRESCALER_SELECTOR_CONFIG DEFAULT_SPI_CLOCK_PRESCALER_SELECTOR
	#define SPI_DOUBLE_SPEED_BIT_CONFIG DEFAULT_SPI_DOUBLE_SPEED_BIT
	```
	
2. You can reconfigure the driver with your own configurations according to the tables below

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
	
3. You have to include the "SPI.h" file in your application source file
4. You have to intialize the driver by calling this function
	```C
	SPI_init(&SPI_configStructure);
	```
5. If you enabled ADC Interrupt Mode, you have to set your callBack function by calling this function
	```C
	SPI_setCallBack(<address of the function that you want to excute when the SPI transmission completes>);
	```
	
## TWI Driver

### Directory Structure of the TWI Driver

![Directory Structure](https://github.com/Eslam26/ATmega16-Drivers/blob/master/media/TWI_TREE.PNG)

- TWI.c : Main Source file of TWI Driver
- TWI.h : Header file of TWI Driver 
- TWI_PBcfg.c : Source file that contains the configuration structure of the driver
- TWI_Cfg: Header file that contains ATmega16 TWI Driver configuration


### Configurations 

1. In TWI_Cfg.c file, you will find these preproccesors macros. By default, TWI Driver is configured on:
	1. Configuration of Clock Prescaler: F_CPU/1
	2. Configuration of General Call Recognition Mode: Off
	3. Configuration of Slave Address: 0x01
	
	```C
	#define TWI_CLOCK_PRESCALER_CONFIG DEFAULT_TWI_CLOCK_PRESCALER
	#define TWI_GENERAL_CALL_RECOGNITION_ENABLE_MODE_CONFIG DEFAULT_TWI_GENERAL_CALL_RECOGNITION_ENABLE_MODE
	#define TWI_SLAVE_ADDRESS_CONFIG DEFAULT_TWI_SLAVE_ADDRESS
	```
	
2. You can reconfigure the driver with your own configurations according to the tables below

	1.  Configuration of Clock Prescaler
	
  	|              CLOCK Prescaler                  |           TWI_CLOCK_PRESCALER_CONFIG                 |
  	|-----------------------------------------------|------------------------------------------------------|
  	| 1                                             | F_OSC_1                                              | 
  	| 4                                             | F_OSC_4                                              |
  	| 16                                            | F_OSC_16                                             |
  	| 64                                            | F_OSC_64                                             |
  
  	2. Configuration of General Call Recognition Mode

  	|             General Call Recognition Mode     |    TWI_GENERAL_CALL_RECOGNITION_ENABLE_MODE_CONFIG   |
  	|-----------------------------------------------|------------------------------------------------------|
  	|OFF                                            | TWI_GENERAL_CALL_RECOGNITION_ENABLE_OFF              | 
  	|ON                                             | TWI_GENERAL_CALL_RECOGNITION_ENABLE_ON               |
  
  	3. Configuration of Slave Address
	
  	|                                               |           TWI_SLAVE_ADDRESS_CONFIG                   |
  	|-----------------------------------------------|------------------------------------------------------|
  	|Slave Address                                  | 1.....127                                            | 
 
  	* Example: If you want to configure TWI driver on the following:	
		1. Configuration of Clock Prescaler: F_CPU/4
		2. Configuration of General Call Recognition Mode: ON
		3. Configuration of Slave Address: 0x06
    	- The preproccesors macros will be 
	```C
	#define TWI_CLOCK_PRESCALER_CONFIG F_OSC_4
	#define TWI_GENERAL_CALL_RECOGNITION_ENABLE_MODE_CONFIG TWI_GENERAL_CALL_RECOGNITION_ENABLE_ON
	#define TWI_SLAVE_ADDRESS_CONFIG 0x06
	```
	
3. You have to include the "TWI.h" file in your application source file
4. You have to intialize the driver by calling this function
	```C
	TWI_init(&TWI_configStructure);
	```
	
## USART Driver

### Directory Structure of the USART Driver

![Directory Structure](https://github.com/Eslam26/ATmega16-Drivers/blob/master/media/USART_TREE.PNG)

- USART.c : Main Source file of SPI Driver
- USART.h : Header file of SPI Driver 
- USART_PBcfg.c : Source file that contains the configuration structure of the driver
- USART_Cfg: Header file that contains ATmega16 SPI Driver configuration


### Configurations 

1. In USART_Cfg.c file, you will find these preproccesors macros. By default, SPI Driver is configured on:
	1. Configuration of Double Transmission Mode: OFF
	2. Configuration of Multi-Processor Communication Mode: OFF
	3. Configuration of RX Complete Intrreupt Mode: OFF
	4. Configuration of TX Complete Intrreupt Mode: OFF
	5. Configuration of UDR Empty Interrupt Mode: OFF
	6. Configuration of USART Mode: Asynchronous
	7. Configuration of Parity Bit Mode : Disabled
	8. Configuration of Stop Bit Mode: One Stop Bit
	9. Configuration of Character Size: 8-bit Character Size
	10. Configuration of Clock Polarity : Transmitted Data On Rising Edge and Recieved Data Falling Edge
	11. Configuration of BaurdRate Value: 9600

	```C
	#define USART_DOUBLE_TRANSMISSION_ENABLE_MODE_CONFIG DEFAULT_USART_DOUBLE_TRANSMISSION_ENABLE_MODE_CONFIG
	#define USART_MULTI_PROCESSOR_COUMMUNICATION_ENABLE_MODE_CONFIG DEFAULT_USART_MULTI_PROCESSOR_COUMMUNICATION_ENABLE_MODE_CONFIG
	#define USART_RX_COMPLETE_INTERRUPT_ENABLE_MODE_CONFIG DEFAULT_USART_RX_COMPLETE_INTERRUPT_ENABLE_MODE_CONFIG
	#define USART_TX_COMPLETE_INTERRUPT_ENABLE_MODE_CONFIG DEFAULT_USART_TX_COMPLETE_INTERRUPT_ENABLE_MODE_CONFIG
	#define USART_DATA_R_EMPTY_INTERRUPT_ENABLE_MODE_CONFIG DEFAULT_USART_DATA_R_EMPTY_INTERRUPT_ENABLE_MODE_CONFIG
	#define USART_MODE_SELECT_CONFIG DEFAULT_USART_MODE_SELECT_CONFIG
	#define USART_PATITY_MODE_CONFIG DEFAULT_USART_PATITY_MODE_CONFIG
	#define USART_STOP_BIT_MODE_CONFIG DEFAULT_USART_STOP_BIT_MODE_CONFIG
	#define USART_CHARACTER_SIZE_CONFIG DEFAULT_USART_CHARACTER_SIZE_CONFIG
	#define USART_CLOCK_POLARITY_CONFIG DEFAULT_USART_CLOCK_POLARITY_CONFIG
	#define USART_BAUDRATE_VALUE_CONFIG DEFAULT_USART_BAUDRATE_VALUE_CONFIG
	```
	
2. You can reconfigure the driver with your own configurations according to the tables below

	1.  Configuration of Double Transmission Mode
	
  	|                                               |       USART_DOUBLE_TRANSMISSION_ENABLE_MODE_CONFIG   |
  	|-----------------------------------------------|------------------------------------------------------|
  	| OFF                                           | USART_DOUBLE_TRANSMISSION_MODE_ENABLE_OFF            | 
  	| ON                                            | USART_DOUBLE_TRANSMISSION_MODE_ENABLE_ON             |
  
  	2. Configuration of Multi-Processor Communication Mode

  	|                                               |USART_MULTI_PROCESSOR_COUMMUNICATION_ENABLE_MODE_CONFIG |
  	|-----------------------------------------------|--------------------------------------------------------|
  	|OFF                                            | USART_MULTI_PROCESSOR_COUMMUNICATION_ENABLE_OFF        | 
  	|ON                                             | USART_MULTI_PROCESSOR_COUMMUNICATION_ENABLE_ON         |
  
  	3. Configuration of RX Complete Intrreupt Mode
	
  	|                                               |    USART_RX_COMPLETE_INTERRUPT_ENABLE_MODE_CONFIG    |
  	|-----------------------------------------------|------------------------------------------------------|
  	|OFF                                            | USART_RX_COMPLETE_INTERRUPT_ENABLE_OFF               | 
  	|ON                                             | USART_RX_COMPLETE_INTERRUPT_ENABLE_OFF               |
	
	4. Configuration of TX Complete Intrreupt Mode
	
  	|                                               |    USART_TX_COMPLETE_INTERRUPT_ENABLE_MODE_CONFIG    |
  	|-----------------------------------------------|------------------------------------------------------|
  	|OFF                                            | USART_TX_COMPLETE_INTERRUPT_ENABLE_OFF               | 
  	|ON                                             | USART_TX_COMPLETE_INTERRUPT_ENABLE_OFF               |
	
	5. Configuration of UDR Empty Intrreupt Mode
	
  	|                                               |    USART_DATA_R_EMPTY_INTERRUPT_ENABLE_MODE_CONFIG   |
  	|-----------------------------------------------|------------------------------------------------------|
  	|OFF                                            | USART_DATA_R_EMPTY_INTERRUPT_ENABLE_OFF              | 
  	|ON                                             | USART_DATA_R_EMPTY_INTERRUPT_ENABLE_ON               |
  
  	6. Configuration of USART MODE
	
  	|                                               |           USART_MODE_SELECT_CONFIG                   |
  	|-----------------------------------------------|------------------------------------------------------|
  	|Synchronous Mode                               | SYNCHRONOUS_OPERATION_MODE                           | 
  	|Asynchronous Mode                              | ASYNCHRONOUS_OPERATION_MODE                          |
	
	7. Configuration of Parity Bit Mode 
	
	|                                               |             USART_PATITY_MODE_CONFIG                 |
  	|-----------------------------------------------|------------------------------------------------------|
  	|Disabled                                       | USART_PATITY_DISABLED                                | 
  	|Even Parity                                    | USART_EVEN_PATITY                                    | 
	|Odd Parity                                     | USART_ODD_PATITY                                     |
	
	8. Configuration of Stop Bit Mode 
	
	|                                               |          USART_STOP_BIT_MODE_CONFIG                  |
  	|-----------------------------------------------|------------------------------------------------------| 
  	|One Stop Bit                                   | USART_ONE_STOP_BIT                                   | 
	|Two Stop Bits                                  | USART_TWO_STOP_BITS                                  |
	
	9. Configuration of Character Size
	
	|                                               |         USART_CHARACTER_SIZE_CONFIG                  |
  	|-----------------------------------------------|------------------------------------------------------|
  	| 5 bit                                         |USART_5_BIT                                           | 
  	| 6 bit                                         |USART_6_BIT                                           |
  	| 7 bit                                         |USART_7_BIT                                           |
  	| 8 bit                                         |USART_8_BIT                                           |
  	| 9 bit                                         |USART_9_BIT                                           |
	
  
  	10. Configuration of Clock Polarity
	* Choose Transmitted Data On Rising Edge and Recieved Data Falling Edge mode if you configured USART Mode as Asynchronous Mode 

  	|                                               |            USART_CLOCK_POLARITY_CONFIG               |
  	|-----------------------------------------------|------------------------------------------------------|
  	|Transmitted Data On Rising Edge and Recieved Data Falling Edge| USART_TRANSMITTED_DATA_RISING_EDGE_RECIEVED_DATA_FALLING_EDGE                                              | 
  	|Transmitted Data On Falling Edge and Recieved Data Rising Edge| USART_TRANSMITTED_DATA_FALLING_EDGE_RECIEVED_DATA_RISING_EDGE                                              |
  	* Example: If you want to configure SPI driver on the following:	
		1. Configuration of Double Transmission Mode: OFF
		2. Configuration of Multi-Processor Communication Mode: OFF
		3. Configuration of RX Complete Intrreupt Mode: OFF
		4. Configuration of TX Complete Intrreupt Mode: OFF
		5. Configuration of UDR Empty Interrupt Mode: OFF
		6. Configuration of USART Mode: Asynchronous
		7. Configuration of Parity Bit Mode : Disabled
		8. Configuration of Stop Bit Mode: One Stop Bit
		9. Configuration of Character Size: 8-bit Character Size
		10. Configuration of Clock Polarity : Transmitted Data On Rising Edge and Recieved Data Falling Edge
		11. Configuration of BaurdRate Value: 9600
    	- The preproccesors macros will be 
	```C
	#define USART_DOUBLE_TRANSMISSION_ENABLE_MODE_CONFIG USART_DOUBLE_TRANSMISSION_MODE_ENABLE_OFF
	#define USART_MULTI_PROCESSOR_COUMMUNICATION_ENABLE_MODE_CONFIG USART_MULTI_PROCESSOR_COUMMUNICATION_ENABLE_OFF
	#define USART_RX_COMPLETE_INTERRUPT_ENABLE_MODE_CONFIG USART_RX_COMPLETE_INTERRUPT_ENABLE_OFF
	#define USART_TX_COMPLETE_INTERRUPT_ENABLE_MODE_CONFIG USART_TX_COMPLETE_INTERRUPT_ENABLE_OFF
	#define USART_DATA_R_EMPTY_INTERRUPT_ENABLE_MODE_CONFIG USART_DATA_R_EMPTY_INTERRUPT_ENABLE_OFF
	#define USART_MODE_SELECT_CONFIG ASYNCHRONOUS_OPERATION_MODE
	#define USART_PATITY_MODE_CONFIG USART_PATITY_DISABLED
	#define USART_STOP_BIT_MODE_CONFIG USART_ONE_STOP_BIT
	#define USART_CHARACTER_SIZE_CONFIG USART_8_BIT
	#define USART_CLOCK_POLARITY_CONFIG USART_TRANSMITTED_DATA_RISING_EDGE_RECIEVED_DATA_FALLING_EDGE
	#define USART_BAUDRATE_VALUE_CONFIG 9600
	```
	
3. You have to include the "USART.h" file in your application source file
4. You have to intialize the driver by calling this function
	```C
	USART_init(&USART_configStructure);
	```
5. If you enabled RX Complete Intrreupt Mode, you have to set your callBack function by calling this function
	```C
	USART_RXC_setCallBack(<address of the function that you want to excute when the RX is set>);
	```
6. If you enabled TX Complete Intrreupt Mode, you have to set your callBack function by calling this function
	```C
	USART_TXC_setCallBack(<address of the function that you want to excute when the TX is set>);
	```
7. If you enabled UDR Emptu Intrreupt Mode, you have to set your callBack function by calling this function
	```C
	USART_UDRE_setCallBack(<address of the function that you want to excute when the UDRE is set>);
	```
  




