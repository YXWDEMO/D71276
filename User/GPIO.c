#include "GPIO.h"
#include "main.h"
// #define KEY_USE

void led_init(void)
{
#if 0	
	//使能GPIO时钟
  LL_IOP_GRP1_EnableClock(LED_1_PortClk);
	//设置IO为输出模�?
  LL_GPIO_SetPinMode(LED_1_Port, LED_1_Pin, LL_GPIO_MODE_OUTPUT);
	//设置IO为推挽输�?
  LL_GPIO_SetPinOutputType(LED_1_Port, LED_1_Pin, LL_GPIO_OUTPUT_PUSHPULL);
	//设置IO速度
  LL_GPIO_SetPinSpeed(LED_1_Port, LED_1_Pin, LL_GPIO_SPEED_FREQ_LOW); 
	//设置IO为浮�?
  LL_GPIO_SetPinPull(LED_1_Port, LED_1_Pin, LL_GPIO_PULL_NO);

#endif
	/* Enable GPIOA clock  */
	//   LL_IOP_GRP1_EnableClock(LED_1_PortClk);

	//   /* Configure PA1 pin in output push-pull mode to drive external LEDs */
	//   LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
	//   GPIO_InitStruct.Pin = LED_1_Pin;
	//   GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	//   GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	//   GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	//   GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	//   LL_GPIO_Init(LED_1_Port, &GPIO_InitStruct);
}

void key_init(void)
{
// #ifdef KEY_USE
// 	// 使能GPIO时钟
// 	LL_IOP_GRP1_EnableClock(KEY_1_PortClk);
// 	// 设置IO为输入模�?
// 	LL_GPIO_SetPinMode(KEY_1_Port, KEY_1_Pin, LL_GPIO_MODE_INPUT);
// 	// 设置IO为上�?
// 	LL_GPIO_SetPinPull(KEY_1_Port, KEY_1_Pin, KEY_1_Pull);
// #endif

// #ifdef KEY_USE
// 	LL_EXTI_InitTypeDef EXTI_InitStruct = {0};
// 	// 下降沿触�?
// 	EXTI_InitStruct.Line = KEY_1_Exti;
// 	EXTI_InitStruct.LineCommand = ENABLE;
// 	EXTI_InitStruct.Mode = LL_EXTI_MODE_EVENT;
// 	EXTI_InitStruct.Trigger = KEY_1_ExtiMode;
// 	LL_EXTI_Init(&EXTI_InitStruct);
// 	// 触发�?
// 	LL_EXTI_SetEXTISource(KEY_1_ExtiPort, KEY_1_ExtiLine);
// #endif

// 	// 使能GPIO时钟
// 	LL_IOP_GRP1_EnableClock(MIC_1_PortClk);
// 	// 设置IO为输入模�?
// 	LL_GPIO_SetPinMode(MIC_1_Port, MIC_1_Pin, LL_GPIO_MODE_INPUT);
// 	// 设置IO为上�?
// 	LL_GPIO_SetPinPull(MIC_1_Port, MIC_1_Pin, MIC_1_Pull);

// 	// 使能GPIO时钟
// 	LL_IOP_GRP1_EnableClock(MIC_1_PortClk);
// 	// 设置IO为输入模�?
// 	LL_GPIO_SetPinMode(CHRG_1_Port, CHRG_1_Pin, LL_GPIO_MODE_INPUT);
// 	// 设置IO为上�?
// 	LL_GPIO_SetPinPull(CHRG_1_Port, CHRG_1_Pin, MIC_1_Pull);

// 	LL_EXTI_InitTypeDef EXTI_InitStruct = {0};

// 	EXTI_InitStruct.Line = MIC_1_Exti;
// 	EXTI_InitStruct.LineCommand = ENABLE;
// 	EXTI_InitStruct.Mode = LL_EXTI_MODE_EVENT;
// 	EXTI_InitStruct.Trigger = MIC_1_ExtiMode;
// 	LL_EXTI_Init(&EXTI_InitStruct);
// 	// 触发�?
// 	LL_EXTI_SetEXTISource(MIC_1_ExtiPort, MIC_1_ExtiLine);

// 	EXTI_InitStruct.Line = CHRG_1_Exti;
// 	EXTI_InitStruct.LineCommand = ENABLE;
// 	EXTI_InitStruct.Mode = LL_EXTI_MODE_EVENT;
// 	EXTI_InitStruct.Trigger = CHRG_1_ExtiMode;
// 	LL_EXTI_Init(&EXTI_InitStruct);
// 	// 触发�?
// 	LL_EXTI_SetEXTISource(CHRG_1_ExtiPort, CHRG_1_ExtiLine);

	// 使能�?�?
	//	NVIC_SetPriority(KEY_1_ExtiIrqn, 0);
	//  NVIC_EnableIRQ(KEY_1_ExtiIrqn);
}

void Gpio_Init(void)
{
	//   GPIOA->MODER = 0x0000FFEFUL;
	//   GPIOB->MODER = 0x0000EFFFUL;
	//   GPIOC->MODER = 0x0000000FUL;
	
	//   GPIOB->OSPEEDR = 0x00003000UL;
	
	//   GPIOA->PUPDR  = 0x00000020UL;
	//   GPIOB->PUPDR = 0x00001000UL;

	LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_ALL); // 开�?  GPIO ABC全部时钟


#ifdef KEY_USE
	LL_GPIO_SetPinMode(KEY_PORT, KEY_PIN, LL_GPIO_MODE_INPUT);
  LL_GPIO_SetPinPull(KEY_PORT, KEY_PIN, LL_GPIO_PULL_NO);
#endif

	// MOS
	LL_GPIO_SetOutputPin(MOS_PORT, MOS_PIN);	   // 输出�?
	LL_GPIO_SetOutputPin(MOS1_PORT, MOS1_PIN);	   // 输出�?

  LL_GPIO_SetPinMode(MOS_PORT, MOS_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinOutputType(MOS_PORT, MOS_PIN, LL_GPIO_OUTPUT_PUSHPULL);

	LL_GPIO_SetPinMode(MOS1_PORT, MOS1_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinOutputType(MOS1_PORT, MOS1_PIN, LL_GPIO_OUTPUT_PUSHPULL);

	LL_GPIO_SetPinMode(Dis_Ic_PORT, Dis_Ic_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinOutputType(Dis_Ic_PORT, Dis_Ic_PIN, LL_GPIO_OUTPUT_PUSHPULL);
	// LL_GPIO_SetOutputPin(Dis_Ic_PORT, Dis_Ic_PIN);	   // 输出�?
	Dis_Ic_ON;
	// LL_GPIO_SetPinMode(Dis_Ic_PORT, Dis_Ic_PIN, LL_GPIO_MODE_INPUT);
    // LL_GPIO_SetPinPull(Dis_Ic_PORT, Dis_Ic_PIN, LL_GPIO_PULL_UP);
  //SDA
	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_3, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_3, LL_GPIO_OUTPUT_PUSHPULL);
	LL_GPIO_SetPinSpeed(GPIOB, LL_GPIO_PIN_3, LL_GPIO_SPEED_FREQ_VERY_HIGH);

	//SCL
	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_5, LL_GPIO_OUTPUT_PUSHPULL);
	LL_GPIO_SetPinSpeed(GPIOB, LL_GPIO_PIN_5, LL_GPIO_SPEED_FREQ_VERY_HIGH);

	// MIC
	LL_GPIO_SetPinMode(MIC_PORT, MIC_PIN, LL_GPIO_MODE_INPUT);
	LL_GPIO_SetPinPull(MIC_PORT, MIC_PIN, LL_GPIO_PULL_DOWN);

	// USB IN
	LL_GPIO_SetPinMode(USB_PORT, USB_PIN, LL_GPIO_MODE_ANALOG);

	// CHRG
	LL_GPIO_SetPinMode(CHRG_PORT, CHRG_PIN, LL_GPIO_MODE_INPUT);
	LL_GPIO_SetPinPull(CHRG_PORT, CHRG_PIN, LL_GPIO_PULL_UP);

	// CHRG EN
	CHRG_ENABLE;
	LL_GPIO_SetPinMode(CHRG_EN_PORT, CHRG_EN_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinOutputType(CHRG_EN_PORT, CHRG_EN_PIN, LL_GPIO_OUTPUT_PUSHPULL);
	LL_GPIO_SetPinPull(CHRG_EN_PORT, CHRG_EN_PIN, LL_GPIO_PULL_NO);
	LL_GPIO_SetPinSpeed(CHRG_EN_PORT, CHRG_EN_PIN, LL_GPIO_SPEED_FREQ_VERY_HIGH);

  //
	// LL_GPIO_SetPinMode(Dis_Ic_PORT, Dis_Ic_PIN, LL_GPIO_MODE_OUTPUT);
	// LL_GPIO_SetPinOutputType(Dis_Ic_PORT, Dis_Ic_PIN, LL_GPIO_OUTPUT_PUSHPULL);
	// LL_GPIO_ResetOutputPin(Dis_Ic_PORT,Dis_Ic_PIN);
	// Dis_Ic_ON;

	// 输出�?检�?   直接模拟�?
	LL_GPIO_SetPinMode(HEAT_PORT, HEAT_PIN, LL_GPIO_MODE_ANALOG);
	LL_GPIO_SetPinMode(HEAT1_PORT, HEAT1_PIN, LL_GPIO_MODE_ANALOG);

}
