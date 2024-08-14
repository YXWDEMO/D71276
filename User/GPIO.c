#include "GPIO.h"
#include "main.h"






void led_init(void)
{	
	#if 0	
	//使能GPIO时钟
  LL_IOP_GRP1_EnableClock(LED_1_PortClk);
	//设置IO为输出模式
  LL_GPIO_SetPinMode(LED_1_Port, LED_1_Pin, LL_GPIO_MODE_OUTPUT);
	//设置IO为推挽输出
  LL_GPIO_SetPinOutputType(LED_1_Port, LED_1_Pin, LL_GPIO_OUTPUT_PUSHPULL);
	//设置IO速度
  LL_GPIO_SetPinSpeed(LED_1_Port, LED_1_Pin, LL_GPIO_SPEED_FREQ_LOW); 
	//设置IO为浮空
  LL_GPIO_SetPinPull(LED_1_Port, LED_1_Pin, LL_GPIO_PULL_NO); 

	  /* Enable GPIOA clock  */
  LL_IOP_GRP1_EnableClock(LED_1_PortClk);

  /* Configure PA1 pin in output push-pull mode to drive external LEDs */
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = LED_1_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(LED_1_Port, &GPIO_InitStruct);
		
	#endif

	
}

void key_init(void)
{ 
#if 0	
	//使能GPIO时钟
  LL_IOP_GRP1_EnableClock(KEY_1_PortClk);
	//设置IO为输入模式
  LL_GPIO_SetPinMode(KEY_1_Port, KEY_1_Pin, LL_GPIO_MODE_INPUT);
	//设置IO为上拉
  LL_GPIO_SetPinPull(KEY_1_Port, KEY_1_Pin, KEY_1_Pull);
	

	  /* Enable GPIOA clock  */
  LL_IOP_GRP1_EnableClock(KEY_1_PortClk);

  /* Configure PA1 pin in output push-pull mode to drive external LEDs */
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = KEY_1_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
  LL_GPIO_Init(KEY_1_Port, &GPIO_InitStruct);


  /* Configure PA1 pin in output push-pull mode to drive external LEDs */
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = LED_1_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(LED_1_Port, &GPIO_InitStruct);
  
  LL_EXTI_InitTypeDef EXTI_InitStruct={0};
	//下降沿触发
	EXTI_InitStruct.Line = KEY_1_Exti;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_EVENT;
  EXTI_InitStruct.Trigger = KEY_1_ExtiMode;
  LL_EXTI_Init(&EXTI_InitStruct);
	//触发源
  LL_EXTI_SetEXTISource(KEY_1_ExtiPort,KEY_1_ExtiLine);
	//使能中断
//	NVIC_SetPriority(KEY_1_ExtiIrqn, 0);
//  NVIC_EnableIRQ(KEY_1_ExtiIrqn);


	#endif
}



void   Gpio_Init(void)
{
   
	  GPIOA->MODER = 0x0000FFEFUL;
	  GPIOB->MODER = 0x0000EFFFUL;
	  GPIOC->MODER = 0x0000000FUL;
	
	  GPIOB->OSPEEDR = 0x00003000UL;
	
	  GPIOA->PUPDR  = 0x00000020UL;
	  GPIOB->PUPDR = 0x00001000UL;
	
	
	  //PA2H  PB6 不要配置   听说这吊毛默认自带上下拉
	
     LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_ALL);//开启  GPIO ABC全部时钟
	  
     //PA0
	   LL_GPIO_SetPinMode(KEY1_PORT,KEY1_PIN,LL_GPIO_MODE_INPUT);
     LL_GPIO_SetPinPull(KEY1_PORT,KEY1_PIN,LL_GPIO_PULL_UP);
  
     //PA1
	   LL_GPIO_SetPinMode(KEY2_PORT,KEY2_PIN,LL_GPIO_MODE_INPUT);
     LL_GPIO_SetPinPull(KEY2_PORT,KEY2_PIN,LL_GPIO_PULL_UP);
     
     //PA2 CLK
	   //LL_GPIO_SetPinMode(KEY3_PORT,KEY3_PIN,LL_GPIO_MODE_INPUT);
     //LL_GPIO_SetPinPull(KEY3_PORT,KEY3_PIN,LL_GPIO_PULL_UP);
     
     //PA3  KEY3
	   LL_GPIO_SetPinMode(KEY3_PORT,KEY3_PIN,LL_GPIO_MODE_INPUT);             
  	 LL_GPIO_SetPinPull(KEY3_PORT,KEY3_PIN,LL_GPIO_PULL_UP);
     
     //PA4  SDA
     //LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_7,LL_GPIO_MODE_INPUT);
     //LL_GPIO_SetPinPull(GPIOB,LL_GPIO_PIN_7,LL_GPIO_PULL_NO);
	   //LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_4); 
     LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_4, LL_GPIO_MODE_OUTPUT);
     LL_GPIO_SetPinOutputType(GPIOA,LL_GPIO_PIN_4,LL_GPIO_OUTPUT_OPENDRAIN);
     LL_GPIO_SetPinSpeed(GPIOA,LL_GPIO_PIN_4,LL_GPIO_SPEED_FREQ_VERY_HIGH);
     //LL_GPIO_SetPinOutputType(SDA_PORT,SDA_PIN,LL_GPIO_OUTPUT_OPENDRAIN);
	   //PA5  SCL
     
	   //LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_5); 
     LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);
     LL_GPIO_SetPinOutputType(GPIOA,LL_GPIO_PIN_5,LL_GPIO_OUTPUT_OPENDRAIN);
     LL_GPIO_SetPinSpeed(GPIOA,LL_GPIO_PIN_4,LL_GPIO_SPEED_FREQ_VERY_HIGH);
     //LL_GPIO_SetPinPull(SDA_PORT,SDA_PIN,LL_GPIO_PULL_NO);
     
	   //PA6
	   LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_6);             //输出低  
	   LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_6, LL_GPIO_MODE_OUTPUT);
     
     //PA7 MIC 
     LL_GPIO_SetPinMode(MIC_PORT,MIC_PIN,LL_GPIO_MODE_INPUT);
		 
		 
     //PB0  //输出端 2
   	 LL_GPIO_SetPinMode(HEAT2_PORT,HEAT2_PIN,LL_GPIO_MODE_ANALOG);
     
	   //PB1  //输出端 1 
   	 LL_GPIO_SetPinMode(HEAT1_PORT,HEAT1_PIN,LL_GPIO_MODE_ANALOG);

     //PB2  MOS	1
	   LL_GPIO_SetOutputPin(MOS1_PORT,MOS1_PIN);             //输出高      
	   LL_GPIO_SetPinMode(MOS1_PORT, MOS1_PIN, LL_GPIO_MODE_OUTPUT);     
	   LL_GPIO_SetPinOutputType(MOS1_PORT, MOS1_PIN, LL_GPIO_OUTPUT_PUSHPULL); 
     
	   //PB3  MOS 2 
     LL_GPIO_SetOutputPin(MOS2_PORT,MOS2_PIN);             //输出高      
	   LL_GPIO_SetPinMode(MOS2_PORT, MOS2_PIN, LL_GPIO_MODE_OUTPUT);     
	   LL_GPIO_SetPinOutputType(MOS2_PORT, MOS2_PIN, LL_GPIO_OUTPUT_PUSHPULL); 
     
     //PB4  Key
	   LL_GPIO_SetPinMode(KEY_PORT,KEY_PIN,LL_GPIO_MODE_INPUT);             
  	 LL_GPIO_SetPinPull(KEY_PORT,KEY_PIN,LL_GPIO_PULL_NO);
		 
     //PB5  CLK
     LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_5,LL_GPIO_MODE_INPUT);
     LL_GPIO_SetPinPull(GPIOB,LL_GPIO_PIN_5,LL_GPIO_PULL_NO);
     
     //PB6  DAT
     //LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_6,LL_GPIO_MODE_INPUT);
     //LL_GPIO_SetPinPull(GPIOB,LL_GPIO_PIN_6,LL_GPIO_PULL_NO);
     
	   //PB7 充电开关	 //输入使能充电
	   LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_7,LL_GPIO_MODE_INPUT);
     LL_GPIO_SetPinPull(GPIOB,LL_GPIO_PIN_7,LL_GPIO_PULL_NO);
		
		 //PC1 CHRG     这个叼毛(尹华建)要上拉	
	   LL_GPIO_SetPinMode(CHRG_PORT,CHRG_PIN,LL_GPIO_MODE_INPUT);
		 LL_GPIO_SetPinPull(CHRG_PORT,CHRG_PIN,LL_GPIO_PULL_UP);

     //PC0
  	 LL_GPIO_SetPinMode(GPIOC,LL_GPIO_PIN_0,LL_GPIO_MODE_ANALOG);


//数码管

//     LL_GPIO_SetPinSpeed(GPIOA,LL_GPIO_PIN_0,LL_GPIO_SPEED_FREQ_VERY_HIGH);
//		 LL_GPIO_SetPinSpeed(GPIOA,LL_GPIO_PIN_1,LL_GPIO_SPEED_FREQ_VERY_HIGH);
//		 LL_GPIO_SetPinSpeed(GPIOA,LL_GPIO_PIN_3,LL_GPIO_SPEED_FREQ_VERY_HIGH);
//		 LL_GPIO_SetPinSpeed(GPIOA,LL_GPIO_PIN_4,LL_GPIO_SPEED_FREQ_VERY_HIGH);
//		 LL_GPIO_SetPinSpeed(GPIOC,LL_GPIO_PIN_0,LL_GPIO_SPEED_FREQ_VERY_HIGH);
//		 LL_GPIO_SetPinSpeed(GPIOC,LL_GPIO_PIN_1,LL_GPIO_SPEED_FREQ_VERY_HIGH);
//		 LL_GPIO_SetPinSpeed(GPIOB,LL_GPIO_PIN_7,LL_GPIO_SPEED_FREQ_VERY_HIGH);

//		 


//     PIN1_IN;PIN2_IN;PIN3_IN;PIN4_IN;
//		 PIN5_IN;PIN6_IN;PIN7_IN;

  
}














