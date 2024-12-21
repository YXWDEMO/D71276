#ifndef __GPIO_H
#define __GPIO_H
#include "main.h"



#ifdef KEY_USE
//KEY
	#define KEY_1_PortClk   	 LL_IOP_GRP1_PERIPH_GPIOB
	#define KEY_1_Port   	 		 GPIOB
	#define KEY_1_Pin  		 		 LL_GPIO_PIN_2
	#define KEY_1_Pull				 LL_GPIO_PULL_NO
	#define KEY_1_Exti				 LL_EXTI_LINE_2
	#define KEY_1_ExtiMode     LL_EXTI_TRIGGER_RISING_FALLING
	#define KEY_1_ExtiPort		 LL_EXTI_CONFIG_PORTB
	#define KEY_1_ExtiLine     LL_EXTI_CONFIG_LINE2
	#define KEY_1_ExtiIrqn		 EXTI2_3_IRQn
#endif

//MIC
#define MIC_1_PortClk      LL_IOP_GRP1_PERIPH_GPIOA
#define MIC_1_Port   	 		 GPIOA
#define MIC_1_Pin  		 		 LL_GPIO_PIN_1
#define MIC_1_Pull				 LL_GPIO_PULL_DOWN
#define MIC_1_Exti				 LL_EXTI_LINE_1
#define MIC_1_ExtiMode     LL_EXTI_TRIGGER_RISING_FALLING  //上升下降沿
#define MIC_1_ExtiPort		 LL_EXTI_CONFIG_PORTA
#define MIC_1_ExtiLine     LL_EXTI_CONFIG_LINE1
#define MIC_1_ExtiIrqn		 EXTI0_1_IRQn

//CHRG
#define CHRG_1_PortClk      LL_IOP_GRP1_PERIPH_GPIOA
#define CHRG_1_Port   	 		GPIOA
#define CHRG_1_Pin  		 		LL_GPIO_PIN_4
#define CHRG_1_Pull				  LL_GPIO_PULL_UP 
#define CHRG_1_Exti				  LL_EXTI_LINE_4
#define CHRG_1_ExtiMode     LL_EXTI_TRIGGER_RISING_FALLING  //上升下降沿
#define CHRG_1_ExtiPort		  LL_EXTI_CONFIG_PORTA
#define CHRG_1_ExtiLine     LL_EXTI_CONFIG_LINE4
#define CHRG_1_ExtiIrqn		  EXTI4_15_IRQn

// //SWITCH
// #define SWITCH_PortClk      LL_IOP_GRP1_PERIPH_GPIOA
// #define SWITCH_Port   	 		GPIOA
// #define SWITCH_Pin  		 		LL_GPIO_PIN_1
// #define SWITCH_Pull				  LL_GPIO_PULL_NO
// #define SWITCH_Exti				  LL_EXTI_LINE_1
// #define SWITCH_ExtiMode     LL_EXTI_TRIGGER_RISING_FALLING  //上升下降沿
// #define SWITCH_ExtiPort		  LL_EXTI_CONFIG_PORTA
// #define SWITCH_ExtiLine     LL_EXTI_CONFIG_LINE1
// #define SWITCH_ExtiIrqn		  EXTI0_1_IRQn
// //SWITCH1
// #define SWITCH1_PortClk      LL_IOP_GRP1_PERIPH_GPIOA
// #define SWITCH1_Port   	 		GPIOA
// #define SWITCH1_Pin  		 		LL_GPIO_PIN_3
// #define SWITCH1_Pull				  LL_GPIO_PULL_NO
// #define SWITCH1_Exti				  LL_EXTI_LINE_3
// #define SWITCH1_ExtiMode     LL_EXTI_TRIGGER_RISING_FALLING  //上升下降沿
// #define SWITCH1_ExtiPort		  LL_EXTI_CONFIG_PORTA
// #define SWITCH1_ExtiLine     LL_EXTI_CONFIG_LINE3
// #define SWITCH1_ExtiIrqn		  EXTI2_3_IRQn



#define ADC_0_GPIO      LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_1, LL_GPIO_MODE_ANALOG)
#define ADC_1_GPIO      LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_3, LL_GPIO_MODE_ANALOG)
#define ADC_2_GPIO      LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_4, LL_GPIO_MODE_ANALOG)
#define ADC_3_GPIO      LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_6, LL_GPIO_MODE_ANALOG)
#define ADC_4_GPIO      LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_7, LL_GPIO_MODE_ANALOG)
#define ADC_5_GPIO      LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_0, LL_GPIO_MODE_ANALOG)
#define ADC_6_GPIO      LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_6, LL_GPIO_MODE_ANALOG)
#define ADC_7_GPIO      LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_0, LL_GPIO_MODE_ANALOG)

void led_init(void);
void key_init(void);

void   Gpio_Init(void);


#endif
