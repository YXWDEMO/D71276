/**
  ******************************************************************************
  * @file    main.c
  * @author  MCU Application Team
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private define ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private user code ---------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void APP_SystemClockConfig(void);

/**
  * @brief  Application Entry Function.
  * @param  None
  * @retval int
  */

uint16_t a[3]={0};
uint8_t ADC_CHA[]={0,2,3};
uint8_t tim_flag=0;
uint8_t tim_10msflag=0;



volatile   u8   Data_a                   __attribute__((at(0x20000A00)));
volatile   u8   Data_b                   __attribute__((at(0x20000A10)));
volatile   u8   Data_c                   __attribute__((at(0x20000A20)));
volatile   u8   Bat_Leve_Data            __attribute__((at(0x20000A30))); 



void     Set_Data(void)
{

  Data_a = 0XAA;
  Data_b = 0XBB;
  Data_c = 0XCC;
  Bat_Leve_Data = BatInfo.Bat_Leve;
}



void     Clr_Data(void)
{

  Data_a = 0X00;
  Data_b = 0X00;
  Data_c = 0X00;

}


u8     Deal_Data(void)
{
   if(Data_a == 0XAA&&Data_b == 0XBB&&Data_c == 0XCC)
   {
	    return 1;
	 
	 }
	 else{return 0; }

}



u8   Test1;
u8   Test2;
u8   Test3;


/*

				 
//				 if(Test1 < 5){Test1++;}
//				 else
//				 {
//				    Test1 = 0;
//					 
//					 if(Test2 < 9){Test2++;}else{Test2 = 0;}
//					 
//					 Dispinfo.Disp_Data = _t_list_digit_list_d0[Test2];
//				   Dispinfo.Disp_EN = 1;
//				 }



*/

void   Sys_Init(void)
{

     APP_SystemClockConfig();
    option_init();
  	Gpio_Init();
		adc_init();
	  timer14_init();
}





extern u8 luminance;

int main(void)
{
  
  //时钟初始化，设置系统时钟为24M
  APP_SystemClockConfig();
//	LL_mDelay(100);
	option_init();
	Gpio_Init();
//	timer1_init();
	adc_init();
	iwdg_init();
	timer14_init();
//	lptim_init();
  
//SysInfo.Power_Rest = 1;

	lptim_init();
	lptim_start();
  
  WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,0x00);	  //00~0F是逐渐增加亮度 0xff
	WB8600M_Write_One(0x11,0x0f);   //
	WB8600M_Write_All(0x00,0x00);
	WB8600M_Write_One(0x12,0x03);	  //03-工作状态，显示开  01-工作状态，显示关  00-Shutdown
  
	if(MIC_IO||Deal_Data())
	{
	  Disp_Short;
		SysInfo.Power_Rest = 1;
		BatInfo.Bat_Leve = Bat_Leve_Data;
	}
	else
	{
	    Disp_Power_Rest;
		  Get_Power_Rest_BatLeve();
      Oil_Time = 40000;
      Out_Mode = 0;
	}
	Power_Rest_Scan();
	SysInfo.Sleep_Time = 30;
  
//  Dispinfo.Breath_En = 1;
//	Dispinfo.Breath_Cycle = 0;
//  Dispinfo.Breath_Count = 15;
//	Dispinfo.Breath_LM    = 0;
//	Dispinfo.Breath_Duty  = 0;
//	Dispinfo.Breath_Num   = 100;
	Clr_Data();
	while (1)
	{	 
       Out_Deal();
       
       if(SysInfo._1ms_Flag)
			 {
			    SysInfo._1ms_Flag = 0;
			    LL_IWDG_ReloadCounter(IWDG);
			 }
			 
			 if(SysInfo._10ms_Flag)
       {
			   SysInfo._10ms_Flag = 0;
				 Port_Scan();
         DISP_Deal();
         WB8600M_Deal();
			 } 
			 
			 if(SysInfo._100ms_Flag)
       {
			   SysInfo._100ms_Flag = 0;
			   Get_Bat_Leve();
         Sleep();
			 } 
	}
}



	



/**
  * @brief  System clock configuration function
  * @param  None
  * @retval None
  */
static void APP_SystemClockConfig(void)
{
	
	//使能相关时钟
  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
  LL_RCC_HSI_Enable();
  while(LL_RCC_HSI_IsReady() != 1)
  {
  }
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSISYS);
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSISYS)
  {
  }
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
	//初始化1ms的滴答计时器
  LL_Init1msTick(24000000);
	//开启滴答中断
	SET_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);
	//设置系统时间
  LL_SetSystemCoreClock(24000000);
}

/**
  * @brief  Error handling function
  * @param  None
  * @retval None
  */
void APP_ErrorHandler(void)
{
  /* Infinite loop */
  while (1)
  {
  }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file：Pointer to the source file name
  * @param  line：assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add His own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* Infinite loop */
  while (1)
  {
  }
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
