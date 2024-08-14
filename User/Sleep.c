#include "main.h"


u8 mic_bit_temp=0;
u8 usb_bit_temp=0;
u8 usb_ad_bit_temp=0;

u8 key_bit_temp=0;
u8 key1_bit_temp=0;
u8 key2_bit_temp=0;
u8 key3_bit_temp=0;

//u8 switch_bit_temp=0;

u8 mic_bit_temp1=0;
u8 usb_bit_temp1=0;
u8 usb_ad_bit_temp1=0;

u8 key_bit_temp1=0;
u8 key1_bit_temp1=0;
u8 key2_bit_temp1=0;
u8 key3_bit_temp1=0;

void   Sleep_Gpio(void)
{
	
	

    LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_ALL);//开启  GPIO ABC全部时钟
	
	
	
	// 烧录口 PA2  PB6    PA2_H  PB6 不要配置   听说这吊毛(尹华建)默认自带上下拉  这里不能上拉 要出问题 那边有下拉
 
	   GPIOA->PUPDR = 0x00000000UL;
	   GPIOB->PUPDR = 0x00000000UL;

  
	   //LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_2);             //输出低
  	 //LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_2, LL_GPIO_MODE_OUTPUT);

	   //LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_6);             //输出低
  	 //LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_6, LL_GPIO_MODE_OUTPUT);
	
	
	
	  //PA0
     
	   LL_GPIO_SetPinMode(KEY1_PORT,KEY1_PIN,LL_GPIO_MODE_INPUT);
     LL_GPIO_SetPinPull(KEY1_PORT,KEY1_PIN,LL_GPIO_PULL_UP);
  
     //PA1
	   LL_GPIO_SetPinMode(KEY2_PORT,KEY2_PIN,LL_GPIO_MODE_INPUT);
     LL_GPIO_SetPinPull(KEY2_PORT,KEY2_PIN,LL_GPIO_PULL_UP);
     
     //PA2 CLK
	   LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_2,LL_GPIO_MODE_INPUT);     
  	 LL_GPIO_SetPinPull(GPIOA,LL_GPIO_PIN_2,LL_GPIO_PULL_NO);
     
     //PA3  
     LL_GPIO_SetPinMode(KEY3_PORT,KEY3_PIN,LL_GPIO_MODE_INPUT);
     LL_GPIO_SetPinPull(KEY3_PORT,KEY3_PIN,LL_GPIO_PULL_UP);
     
     
     if(!KEY1_IO)
     {
        LL_GPIO_SetPinMode(KEY1_PORT,KEY1_PIN,LL_GPIO_MODE_INPUT);
        LL_GPIO_SetPinPull(KEY1_PORT,KEY1_PIN,LL_GPIO_PULL_NO);
     }
     else if(!KEY2_IO)
     {
        LL_GPIO_SetPinMode(KEY2_PORT,KEY2_PIN,LL_GPIO_MODE_INPUT);
        LL_GPIO_SetPinPull(KEY2_PORT,KEY2_PIN,LL_GPIO_PULL_NO);
     }
     else if(!KEY3_IO)
     {
        LL_GPIO_SetPinMode(KEY3_PORT,KEY3_PIN,LL_GPIO_MODE_INPUT);
        LL_GPIO_SetPinPull(KEY3_PORT,KEY3_PIN,LL_GPIO_PULL_NO);
     }
     
     
     //PA4  SDA
  	 LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_4, LL_GPIO_MODE_INPUT);
     LL_GPIO_SetPinPull(GPIOA,LL_GPIO_PIN_4,LL_GPIO_PULL_NO);
	   //PA5  SCL
	   LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_5, LL_GPIO_MODE_INPUT);             //输出低  
  	 LL_GPIO_SetPinPull(GPIOA,LL_GPIO_PIN_5,LL_GPIO_PULL_NO);
     
	   //PA6
	   LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_6);             //输出低  
	   LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_6, LL_GPIO_MODE_OUTPUT);
     
     //PA7 MIC 
     LL_GPIO_SetPinMode(MIC_PORT,MIC_PIN,LL_GPIO_MODE_INPUT);
		 
		 
     //PB0  //输出端 2
//   	 LL_GPIO_SetPinMode(HEAT2_PORT,HEAT2_PIN,LL_GPIO_MODE_ANALOG);
     LL_GPIO_SetPinMode(HEAT2_PORT,HEAT2_PIN, LL_GPIO_MODE_INPUT);             //输出低  
  	 LL_GPIO_SetPinPull(HEAT2_PORT,HEAT2_PIN,LL_GPIO_PULL_DOWN);
     
	   //PB1  //输出端 1 
//   	 LL_GPIO_SetPinMode(HEAT1_PORT,HEAT1_PIN,LL_GPIO_MODE_ANALOG);
     LL_GPIO_SetPinMode(HEAT1_PORT,HEAT1_PIN, LL_GPIO_MODE_INPUT);             //输出低  
  	 LL_GPIO_SetPinPull(HEAT1_PORT,HEAT1_PIN,LL_GPIO_PULL_DOWN);
     
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
		 
     //PB5
     LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_5);             //输出低  
  	 LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);
     
     //PB6  DAT
     LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_6,LL_GPIO_MODE_INPUT);
     LL_GPIO_SetPinPull(GPIOB,LL_GPIO_PIN_6,LL_GPIO_PULL_NO);
     
	   //PB7 充电开关	 //输入使能充电
	   LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_7,LL_GPIO_MODE_INPUT);
     LL_GPIO_SetPinPull(GPIOB,LL_GPIO_PIN_7,LL_GPIO_PULL_NO);
		
		 //PC1 CHRG     这个叼毛(尹华健)要上拉	
	   LL_GPIO_SetPinMode(CHRG_PORT,CHRG_PIN,LL_GPIO_MODE_INPUT);
		 LL_GPIO_SetPinPull(CHRG_PORT,CHRG_PIN,LL_GPIO_PULL_UP);

     //PC0
  	 LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_0,LL_GPIO_MODE_ANALOG);



//数码管
//     PIN1_L;PIN2_L;PIN3_L;PIN4_L;
//		 PIN5_L;PIN6_L;PIN7_L;

		
//		LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_ALL,LL_GPIO_MODE_INPUT);
//		 LL_GPIO_SetPinPull(GPIOB,LL_GPIO_PIN_ALL,LL_GPIO_PULL_DOWN);
//		 
//		 LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_ALL,LL_GPIO_MODE_INPUT);
//		 LL_GPIO_SetPinPull(GPIOA,LL_GPIO_PIN_ALL,LL_GPIO_PULL_DOWN);
//		 
//		 LL_GPIO_SetPinMode(GPIOC,LL_GPIO_PIN_ALL,LL_GPIO_MODE_INPUT);
//		 LL_GPIO_SetPinPull(GPIOC,LL_GPIO_PIN_ALL,LL_GPIO_PULL_DOWN);
	LL_EXTI_InitTypeDef EXTI1_InitStruct={0};
	
		 //PC1  PB7  PA5   
	EXTI1_InitStruct.Line = KEY_0_Exti;
  EXTI1_InitStruct.LineCommand = ENABLE;
  EXTI1_InitStruct.Mode = LL_EXTI_MODE_EVENT;
  EXTI1_InitStruct.Trigger = KEY_0_ExtiMode;
  LL_EXTI_Init(&EXTI1_InitStruct);
	//触发源
  LL_EXTI_SetEXTISource(KEY_0_ExtiPort,KEY_0_ExtiLine);
	//使能中断
	NVIC_SetPriority(KEY_0_ExtiIrqn, 0);
  NVIC_EnableIRQ(KEY_0_ExtiIrqn);

  LL_EXTI_InitTypeDef EXTI2_InitStruct={0};
	//双沿降沿触发
	EXTI2_InitStruct.Line = KEY_1_Exti;
  EXTI2_InitStruct.LineCommand = ENABLE;
  EXTI2_InitStruct.Mode = LL_EXTI_MODE_EVENT;
  EXTI2_InitStruct.Trigger = KEY_1_ExtiMode;
  LL_EXTI_Init(&EXTI2_InitStruct);
	//触发源
  LL_EXTI_SetEXTISource(KEY_1_ExtiPort,KEY_1_ExtiLine);
	//使能中断
	NVIC_SetPriority(KEY_1_ExtiIrqn, 0);
  NVIC_EnableIRQ(KEY_1_ExtiIrqn);
	
  LL_EXTI_InitTypeDef EXTI3_InitStruct={0};  
	EXTI3_InitStruct.Line = KEY_2_Exti;
  EXTI3_InitStruct.LineCommand = ENABLE;
  EXTI3_InitStruct.Mode = LL_EXTI_MODE_EVENT;
  EXTI3_InitStruct.Trigger = KEY_2_ExtiMode;
  LL_EXTI_Init(&EXTI3_InitStruct);
	//触发源
  LL_EXTI_SetEXTISource(KEY_2_ExtiPort,KEY_2_ExtiLine);
	//使能中断
	NVIC_SetPriority(KEY_2_ExtiIrqn, 0);
  NVIC_EnableIRQ(KEY_2_ExtiIrqn);
  
  LL_EXTI_InitTypeDef EXTI4_InitStruct={0};
  EXTI4_InitStruct.Line = KEY_3_Exti;
  EXTI4_InitStruct.LineCommand = ENABLE;
  EXTI4_InitStruct.Mode = LL_EXTI_MODE_EVENT;
  EXTI4_InitStruct.Trigger = KEY_3_ExtiMode;
  LL_EXTI_Init(&EXTI4_InitStruct);
	//触发源
  LL_EXTI_SetEXTISource(KEY_3_ExtiPort,KEY_3_ExtiLine);
	//使能中断
	NVIC_SetPriority(KEY_3_ExtiIrqn, 0);
  NVIC_EnableIRQ(KEY_3_ExtiIrqn);

  
  LL_EXTI_InitTypeDef EXTI5_InitStruct={0};
	//下降沿触发
	EXTI5_InitStruct.Line = MIC_1_Exti;
  EXTI5_InitStruct.LineCommand = ENABLE;
  EXTI5_InitStruct.Mode = LL_EXTI_MODE_EVENT;
  EXTI5_InitStruct.Trigger = MIC_1_ExtiMode;
  LL_EXTI_Init(&EXTI5_InitStruct);
	//触发源
  LL_EXTI_SetEXTISource(MIC_1_ExtiPort,MIC_1_ExtiLine);
	//使能中断
	NVIC_SetPriority(MIC_1_ExtiIrqn, 0);
  NVIC_EnableIRQ(MIC_1_ExtiIrqn);
	
	
	 LL_EXTI_InitTypeDef EXTI6_InitStruct={0};
	//下降沿触发
	EXTI6_InitStruct.Line = CHRG_1_Exti;
  EXTI6_InitStruct.LineCommand = ENABLE;
  EXTI6_InitStruct.Mode = LL_EXTI_MODE_EVENT;
  EXTI6_InitStruct.Trigger = CHRG_1_ExtiMode;
  LL_EXTI_Init(&EXTI6_InitStruct);
	//触发源
  LL_EXTI_SetEXTISource(CHRG_1_ExtiPort,CHRG_1_ExtiLine);
	//使能中断
	NVIC_SetPriority(CHRG_1_ExtiIrqn, 0);
  NVIC_EnableIRQ(CHRG_1_ExtiIrqn);




}
void enter_stop(void)
{	
	LL_TIM_DisableCounter(TIM1);
	LL_TIM_DisableCounter(TIM14);
	
  LL_TIM_ClearFlag_UPDATE(TIM1);
  LL_TIM_DisableIT_UPDATE(TIM1);

  LL_TIM_ClearFlag_UPDATE(TIM14);
  LL_TIM_DisableIT_UPDATE(TIM14);
	
	LL_APB1_GRP2_DisableClock(RCC_APBENR2_TIM1EN);
	LL_APB1_GRP2_DisableClock(RCC_APBENR2_TIM14EN);
	
	Get_Usb_Ad();

	if(BatInfo.Usb_Ad_Volt >= 300)
	{
		usb_ad_bit_temp = 1;
	}
	else
	{
		usb_ad_bit_temp = 0;
	}
	
	adc_disable();
	
	LL_IWDG_ReloadCounter(IWDG);	//喂狗
	
	Sleep_Gpio();
	
	if(MIC_IO)
	{
		mic_bit_temp=1;
	}
  else
	{		
		mic_bit_temp=0;	
	}

	if(CHRG_IO)	
	{
		usb_bit_temp=1;
	}
	else
	{
		usb_bit_temp=0;
	}

	if(KEY_IO)
	{
	  key_bit_temp=1;
	}
	else
	{
		key_bit_temp=0;
	}
  
  if(KEY1_IO)
	{
	  key1_bit_temp=1;
	}
	else
	{
		key1_bit_temp=0;
	}
  
  if(KEY2_IO)
	{
	  key2_bit_temp=1;
	}
	else
	{
		key2_bit_temp=0;
	}
  
  if(KEY3_IO)
	{
	  key3_bit_temp=1;
	}
	else
	{
		key3_bit_temp=0;
	}
  
  
  
LPTIM_SLEEP:
	adc_disable();
	lptim_start();
	//关闭滴答中断
	CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);
  /* STOP mode with low power regulator ON */
  LL_PWR_SetLprMode(LL_PWR_LPR_MODE_LPR);
  /* SRAM retention voltage aligned with digital LDO output */
  LL_PWR_SetStopModeSramVoltCtrl(LL_PWR_SRAM_RETENTION_VOLT_CTRL_LDO);
  /* Enter DeepSleep mode */
  LL_LPM_EnableDeepSleep();
  /* Request Wait   */
   __SEV();
   __WFE();
   __WFE();
  LL_LPM_EnableSleep();
	//开启滴答中断
	SET_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);

	LL_IWDG_ReloadCounter(IWDG);

	if(1)
	{
		if(MIC_IO)
		{
			mic_bit_temp1=1;
		}
		else
		{		
			mic_bit_temp1=0;
		}

		if(CHRG_IO)	
		{
			usb_bit_temp1=1;
		}
		else
		{
			usb_bit_temp1=0;
		}

		if(KEY_IO)
		{
			key_bit_temp1=1;
		}
		else
		{
			key_bit_temp1=0;
		}
    
    if(KEY1_IO)
    {
      key1_bit_temp1=1;
    }              
    else           
    {              
      key1_bit_temp1=0;
    }              
                   
    if(KEY2_IO)   
    {              
      key2_bit_temp1=1;
    }              
    else           
    {              
      key2_bit_temp1=0;
    }              
                   
    if(KEY3_IO)   
    {              
      key3_bit_temp1=1;
    }              
    else           
    {              
      key3_bit_temp1=0;
    }
    
		BatVoltage();
		Get_Usb_Ad();

		if(BatInfo.Usb_Ad_Volt >= 300)
		{
			usb_ad_bit_temp1 = 1;
		}
		else
		{
			usb_ad_bit_temp1 = 0;
		}

		if((key_bit_temp!=key_bit_temp1)||(key1_bit_temp!=key1_bit_temp1)||(key2_bit_temp!=key2_bit_temp1)||(key3_bit_temp!=key3_bit_temp1)||(usb_ad_bit_temp!=usb_ad_bit_temp1)||(mic_bit_temp!=mic_bit_temp1) ||(usb_bit_temp!=usb_bit_temp1) || (BatInfo.Usb_Full_Flag&&(BatInfo.Bat_Volt < 4050)))
		{
			if(BatInfo.Usb_Full_Flag && (BatInfo.Bat_Volt < 4050))
			{
				BatInfo.Usb_Full_Flag = 0;
			}
		}
		else
		{
			goto LPTIM_SLEEP;
		}
	}

	// 开启定时器时钟
	LL_APB1_GRP2_EnableClock(RCC_APBENR2_TIM1EN);
	LL_APB1_GRP2_EnableClock(RCC_APBENR2_TIM14EN);

	// 开启定时器中断
  LL_TIM_ClearFlag_UPDATE(TIM1);
  LL_TIM_EnableIT_UPDATE(TIM1);

  LL_TIM_ClearFlag_UPDATE(TIM14);
  LL_TIM_EnableIT_UPDATE(TIM14);

	// 使能定时器
	LL_TIM_EnableCounter(TIM1);
	LL_TIM_EnableCounter(TIM14);
	
}





void   Sleep(void)
{

   if(Dispinfo.Disp_Num||OUTLOAD||BatInfo.Usb_Ad_Volt>= 300||USBIN||BatInfo.Bat_Leve_Delay_Cnt){SysInfo.Sleep_Time = 30;}
	 else if(!SysInfo.Sleep_Time)
	 {
       
      WB8600M_Write_One(0x12,0x00); 
		  if(SysInfo.Power_Rest)
			{
			  SysInfo.Power_Rest  = 0;
			  Get_Power_Rest_BatLeve();
			}
	    
	    //Sleep_Gpio();
	    
			
	    OutInfo.Out_Mos_Interrup_Ctr_Flag = 0; 
			MOS_OFF;
	    
	    enter_stop();
	    
	    Sys_Init();
	    WB8600M_Write_One(0x12,0x01);
	    WB8600M_Write_One(0x10,0x00);	  //00~0F是逐渐增加亮度 0xff
	    WB8600M_Write_One(0x11,0x0f);   //
	    WB8600M_Write_All(0x00,0x00);
	    WB8600M_Write_One(0x12,0x03);	  //03-工作状态，显示开  01-工作状态，显示关  00-Shutdown
	    SysInfo.Sleep_Time = 30;
	 
	 }



}



