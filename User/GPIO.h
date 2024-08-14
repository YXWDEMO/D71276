#ifndef __GPIO_H
#define __GPIO_H
#include "main.h"










//#define LED_1_PortClk   	  LL_IOP_GRP1_PERIPH_GPIOB
//#define LED_1_Port   	      GPIOB
//#define LED_1_Pin  		      LL_GPIO_PIN_5
//#define LED_1_OFF  		      LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_5)
//#define LED_1_ON  		      LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_1)



//#define HEAT_1_PortClk   	  LL_IOP_GRP1_PERIPH_GPIOB
//#define HEAT_1_Port   	 		GPIOB
//#define HEAT_1_Pin  		 		LL_GPIO_PIN_0
//#define HEAT_1_Pull				  LL_GPIO_PULL_NO
//#define HEAT_1_Exti				  LL_EXTI_LINE_0
//#define HEAT_1_ExtiMode     LL_EXTI_TRIGGER_RISING_FALLING
//#define HEAT_1_ExtiPort		  LL_EXTI_CONFIG_PORTB
//#define HEAT_1_ExtiLine     LL_EXTI_CONFIG_LINE0
//#define HEAT_1_ExtiIrqn		  EXTI0_1_IRQn


//KEY
#define KEY_0_PortClk   	 LL_IOP_GRP1_PERIPH_GPIOB
#define KEY_0_Port   	 		 GPIOB
#define KEY_0_Pin  		 		 LL_GPIO_PIN_4
#define KEY_0_Pull				 LL_GPIO_PULL_NO
#define KEY_0_Exti				 LL_EXTI_LINE_4
#define KEY_0_ExtiMode     LL_EXTI_TRIGGER_RISING_FALLING
#define KEY_0_ExtiPort		 LL_EXTI_CONFIG_PORTB
#define KEY_0_ExtiLine     LL_EXTI_CONFIG_LINE4
#define KEY_0_ExtiIrqn		 EXTI4_15_IRQn

//KEY
#define KEY_1_PortClk   	 LL_IOP_GRP1_PERIPH_GPIOA
#define KEY_1_Port   	 		 GPIOA
#define KEY_1_Pin  		 		 LL_GPIO_PIN_0
#define KEY_1_Pull				 LL_GPIO_PULL_NO
#define KEY_1_Exti				 LL_EXTI_LINE_0
#define KEY_1_ExtiMode     LL_EXTI_TRIGGER_RISING_FALLING
#define KEY_1_ExtiPort		 LL_EXTI_CONFIG_PORTA
#define KEY_1_ExtiLine     LL_EXTI_CONFIG_LINE0
#define KEY_1_ExtiIrqn		 EXTI0_1_IRQn


//KEY
#define KEY_2_PortClk   	 LL_IOP_GRP1_PERIPH_GPIOA
#define KEY_2_Port   	 		 GPIOA
#define KEY_2_Pin  		 		 LL_GPIO_PIN_1
#define KEY_2_Pull				 LL_GPIO_PULL_NO
#define KEY_2_Exti				 LL_EXTI_LINE_1
#define KEY_2_ExtiMode     LL_EXTI_TRIGGER_RISING_FALLING
#define KEY_2_ExtiPort		 LL_EXTI_CONFIG_PORTA
#define KEY_2_ExtiLine     LL_EXTI_CONFIG_LINE1
#define KEY_2_ExtiIrqn		 EXTI0_1_IRQn


//KEY
#define KEY_3_PortClk   	 LL_IOP_GRP1_PERIPH_GPIOA
#define KEY_3_Port   	 		 GPIOA
#define KEY_3_Pin  		 		 LL_GPIO_PIN_3
#define KEY_3_Pull				 LL_GPIO_PULL_NO
#define KEY_3_Exti				 LL_EXTI_LINE_3
#define KEY_3_ExtiMode     LL_EXTI_TRIGGER_RISING_FALLING
#define KEY_3_ExtiPort		 LL_EXTI_CONFIG_PORTA
#define KEY_3_ExtiLine     LL_EXTI_CONFIG_LINE3
#define KEY_3_ExtiIrqn		 EXTI2_3_IRQn



//PA7
#define MIC_1_PortClk      LL_IOP_GRP1_PERIPH_GPIOA
#define MIC_1_Port   	 		 GPIOA
#define MIC_1_Pin  		 		 LL_GPIO_PIN_7
#define MIC_1_Pull				 LL_GPIO_PULL_DOWN  //有硬件下拉
#define MIC_1_Exti				 LL_EXTI_LINE_7
#define MIC_1_ExtiMode     LL_EXTI_TRIGGER_RISING_FALLING  //上升下降沿
#define MIC_1_ExtiPort		 LL_EXTI_CONFIG_PORTA
#define MIC_1_ExtiLine     LL_EXTI_CONFIG_LINE7
#define MIC_1_ExtiIrqn		 EXTI4_15_IRQn

//CHRG
#define CHRG_1_PortClk      LL_IOP_GRP1_PERIPH_GPIOC
#define CHRG_1_Port   	 		GPIOC
#define CHRG_1_Pin  		 		LL_GPIO_PIN_1
#define CHRG_1_Pull				  LL_GPIO_PULL_UP 
#define CHRG_1_Exti				  LL_EXTI_LINE_1
#define CHRG_1_ExtiMode     LL_EXTI_TRIGGER_RISING_FALLING  //上升下降沿
#define CHRG_1_ExtiPort		  LL_EXTI_CONFIG_PORTC
#define CHRG_1_ExtiLine     LL_EXTI_CONFIG_LINE1
#define CHRG_1_ExtiIrqn		  EXTI0_1_IRQn







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
