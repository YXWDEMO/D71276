/**
  ******************************************************************************
  * @file    py32c642_it.c
  * @author  MCU Application Team
  * @brief   Interrupt Service Routines.
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
#include "py32c642_it.h"


/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/
/* External variables --------------------------------------------------------*/

/******************************************************************************/
/*           Cortex-M0+ Processor Interruption and Exception Handlers         */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  while (1)
  {
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{         
	

	
}
void EXTI0_1_IRQHandler(void)
{
  /* Handle EXTI interrupt request */
  if(LL_EXTI_IsActiveFlag(LL_EXTI_LINE_0))
  {
    LL_EXTI_ClearFlag(LL_EXTI_LINE_0);
  }
	if(LL_EXTI_IsActiveFlag(LL_EXTI_LINE_1))
  {
    LL_EXTI_ClearFlag(LL_EXTI_LINE_1);
  }
}
void EXTI2_3_IRQHandler(void)
{
  /* Handle EXTI interrupt request */
  if(LL_EXTI_IsActiveFlag(LL_EXTI_LINE_2))
  {
    LL_EXTI_ClearFlag(LL_EXTI_LINE_2);
  }
	if(LL_EXTI_IsActiveFlag(LL_EXTI_LINE_3))
  {
    LL_EXTI_ClearFlag(LL_EXTI_LINE_3);
  }
}
void EXTI4_15_IRQHandler(void)
{
  /* Handle EXTI interrupt request */
  if(LL_EXTI_IsActiveFlag(LL_EXTI_LINE_4))
  {
    LL_EXTI_ClearFlag(LL_EXTI_LINE_4);
  }
	if(LL_EXTI_IsActiveFlag(LL_EXTI_LINE_5))
  {
    LL_EXTI_ClearFlag(LL_EXTI_LINE_5);
  }
  if(LL_EXTI_IsActiveFlag(LL_EXTI_LINE_7))
  {
    LL_EXTI_ClearFlag(LL_EXTI_LINE_7);
  }
}
extern uint8_t tim_flag;



//u8   abc = 0;

//20us



u8    Disp_Event;


void TIM14_IRQHandler(void)
{
	if((LL_TIM_ReadReg(TIM14,SR) & LL_TIM_SR_UIF) == 1 && LL_TIM_IsEnabledIT_UPDATE(TIM14))
  {
    LL_TIM_ClearFlag_UPDATE(TIM14);
//    if(SysInfo.Time_1200us < 8){SysInfo.Time_1200us++;}
//    else
//    {
//          SysInfo.Time_1200us = 1;
////          Breath_Deal();
//    }
//		if(SysInfo.Time_500us < 5){SysInfo.Time_500us++;}
//    else
//    {
//          SysInfo.Time_500us = 1; //大概300us左右
//          //WB8600M_Write_One(0x01,Breath_Test);
//    }
		if(SysInfo.Time_100us < 1){SysInfo.Time_100us++;}
		else
		{	
		   SysInfo.Time_100us = 1;
		   
        tim_flag++;   
		if(OutInfo.Out_Mos_Interrup_Ctr_Flag)
   {
	    
		  if(OutInfo.Out_Pwm_Cycle < DUTY_MAX_VOLT){OutInfo.Out_Pwm_Cycle++;}
	    else{OutInfo.Out_Pwm_Cycle  = 0;}
			
			if(Out_Mode == 2 || (!Out_Load))
      {
        if(OutInfo.Out_Pwm_Cycle <= OutInfo.Out_Pwm_Duty)
        {
            MOS1_ON;
        }
        else
        {
            MOS1_OFF;
            OutInfo.Out_Short_Check_En = 0;
        }
        if(OutInfo.Out_Pwm_Cycle <= OutInfo.Out_Pwm_Duty-1)
        {
            OutInfo.Out_Short_Check_En = 1;
        }
        else
        {
            OutInfo.Out_Short_Check_En = 0;
        }   
        
      }
      
      if(Out_Mode == 2 || Out_Load)
      {
        if(OutInfo.Out_Pwm_Cycle <= OutInfo.Out_Pwm_Duty1)
        {
            MOS2_ON;
        }
        else
        {
            MOS2_OFF;
            OutInfo.Out_Short_Check_En = 0;
        }
        if(OutInfo.Out_Pwm_Cycle <= OutInfo.Out_Pwm_Duty1-1)
        {
            OutInfo.Out_Short_Check_En = 1;
        }
        else
        {
            OutInfo.Out_Short_Check_En = 0;
        }    
      }
      
      
      
			if(OutInfo.Out_Pwm_Cycle == 5)
				  OutInfo.Out_Duty_Main_Deal_Flag = 1;

			if(OutInfo.Out_Short_Check_Load)
			{
			   if(!OutInfo.Out_Short_Check_En)
				 {
				    OutInfo.Out_Short_Check_Error = 1;
				 }
			
			}
	 }
		
		
		
	if(SysInfo.Time_1ms < 10){SysInfo.Time_1ms++;}
   else
   {
     SysInfo.Time_1ms = 1;
	   SysInfo._1ms_Flag = 1;
	 if(SysInfo.Time_10ms < 10){SysInfo.Time_10ms++;}
   else
	 {
	    SysInfo.Time_10ms = 1;
	    SysInfo._10ms_Flag = 1;
		  if(SysInfo.Time_100ms < 10){SysInfo.Time_100ms++;}
			else
      {
            SysInfo.Time_100ms = 1;
			      SysInfo._100ms_Flag = 1;
            if(OUTLOAD)
            {
                if(Oil_Time)
                {
                  Oil_Time --;
                }
            }
				    if(OutInfo.Smok_Time){OutInfo.Smok_Time--;}
			      if(SysInfo.Sleep_Time){SysInfo.Sleep_Time--;}
			
			}
	 
	 
	 } 



}   

}
	 
  //显示驱动
	#if 0 
  Dispinfo.sys_led_display_isr_cnt++;
	if(Dispinfo.sys_led_display_isr_cnt >= 1)
	{
	   Dispinfo.sys_led_display_isr_cnt = 0;
		 PIN7_IN;PIN6_IN;PIN5_IN;PIN4_IN;PIN3_IN;
	   PIN2_IN;PIN1_IN;
	
	   if(Dispinfo.Disp_EN == 0)
		 { 
		     Dispinfo.Disp_offset = 0;
			   
		 }
		 else if(!Dispinfo.Disp_Dis)
		 {  
			 #if  0	
		   switch(Dispinfo.Disp_offset)
			 {
		     case 0:
					 
				   if(Dispinfo.Disp_Data&c_bit_0){ PIN1_L;PIN2_H; }
					 if(Dispinfo.Disp_Data&c_bit_1){ PIN1_L;PIN3_H; }
				   if(Dispinfo.Disp_Data&c_bit_2){ PIN1_L;PIN4_H; }
				 
				 break;
				 
				 
				 case 1:
					 if(Dispinfo.Disp_Data&c_bit_3){ PIN1_L;PIN5_H; }
					 if(Dispinfo.Disp_Data&c_bit_4){ PIN1_L;PIN6_H; }
				   if(Dispinfo.Disp_Data&c_bit_5){ PIN1_L;PIN7_H; }
				 
				 
				 break;

					 
				 case 2:
					   if(Dispinfo.Disp_Data&c_bit_6){ PIN2_L;PIN1_H; }
					   if(Dispinfo.Disp_Data&c_bit_7){ PIN2_L;PIN3_H; }
				     if(Dispinfo.Disp_Data&c_bit_8){ PIN2_L;PIN4_H; }
				 
				 break;
				 
				 
				 case 3:
					  if(Dispinfo.Disp_Data&c_bit_9) { PIN2_L;PIN5_H; }
					  if(Dispinfo.Disp_Data&c_bit_10){ PIN2_L;PIN6_H; }
				    if(Dispinfo.Disp_Data&c_bit_11){ PIN2_L;PIN7_H; }

				 break;
				 
				 
				 case 4:
					 
				     if(Dispinfo.Disp_Data&c_bit_12){ PIN3_L;PIN1_H; }
					   if(Dispinfo.Disp_Data&c_bit_13){ PIN3_L;PIN2_H; }
				     if(Dispinfo.Disp_Data&c_bit_14){ PIN3_L;PIN4_H; }
				 
				 break;
				 
				 
				 
				 case 5:
					  if(Dispinfo.Disp_Data&c_bit_15){ PIN3_L;PIN5_H; }
					  if(Dispinfo.Disp_Data&c_bit_16){ PIN3_L;PIN6_H; }
				    if(Dispinfo.Disp_Data&c_bit_17){ PIN3_L;PIN7_H; }
	 
				 break;
				 
				 
				 case 6:
					   if(Dispinfo.Disp_Data&c_bit_18){ PIN4_L;PIN1_H; }
					   if(Dispinfo.Disp_Data&c_bit_19){ PIN4_L;PIN2_H; }
				     if(Dispinfo.Disp_Data&c_bit_20){ PIN4_L;PIN3_H; }			 
				 break;
				 
				 case 7:
					  if(Dispinfo.Disp_Data&c_bit_21){ PIN4_L;PIN5_H; }
					  if(Dispinfo.Disp_Data&c_bit_22){ PIN4_L;PIN6_H; }
				    if(Dispinfo.Disp_Data&c_bit_23){ PIN4_L;PIN7_H; }
				 
				 break;
				 
				 
				 case 8:
					   if(Dispinfo.Disp_Data&c_bit_24){ PIN5_L;PIN1_H; }
					   if(Dispinfo.Disp_Data&c_bit_25){ PIN5_L;PIN2_H; }
				     
				 break;
				 
				 case 9:
					   if(Dispinfo.Disp_Data&c_bit_26){ PIN5_L;PIN3_H; }
					   if(Dispinfo.Disp_Data&c_bit_27){ PIN5_L;PIN4_H; }
				 break;
					 
				 case 10:
             if(Dispinfo.Disp_Data&c_bit_28){ PIN5_L;PIN6_H;PIN7_H; }
         break;

         case 11:
             if(Dispinfo.Disp_Data&c_bit_29){ PIN6_L;PIN1_H;PIN2_H; }  
         break;

         case 12:
              if(Dispinfo.Disp_Data&c_bit_30){PIN6_L;PIN3_H;PIN4_H;PIN5_H; }
         break;				 
				 		 
			 

			 
			 }
			 if(Dispinfo.Disp_offset < 12){Dispinfo.Disp_offset++;}else{Dispinfo.Disp_offset = 0;Breath_Deal();}//一个周期刷新就是 20us*13 = 260us
			#else
			
			
//			if(Dispinfo.Breath_En)
//			{
//			  if(Disp_Event < 2){Disp_Event++; Breath_Deal();   
//                               if(Dispinfo.Breath_Cycle < Dispinfo.Breath_Duty){  Dispinfo.Disp_Data |= DISP_LOG_MASKE;  if(Disp_Event == 1){PIN5_L;PIN6_H;PIN7_H; }else if(Disp_Event == 2){  PIN6_L;PIN3_H;PIN4_H;PIN5_H; PIN1_H;PIN2_H;  }  }
//	                           	else{   Dispinfo.Disp_Data &= ~DISP_LOG_MASKE; }
//                   

//                                 }else{Disp_Event = 0;}
//		  }else{Disp_Event = 0 ;}
			
			

       switch(Dispinfo.Disp_offset)
			 {
			     
				 
				 
			 
		     case 0:
					 
				   if(Dispinfo.Disp_Data&c_bit_0){ PIN1_L;PIN2_H; }
					 if(Dispinfo.Disp_Data&c_bit_1){ PIN1_L;PIN3_H; }
				   if(Dispinfo.Disp_Data&c_bit_2){ PIN1_L;PIN4_H; }
				   if(Dispinfo.Disp_Data&c_bit_3){ PIN1_L;PIN5_H; }
					 if(Dispinfo.Disp_Data&c_bit_4){ PIN1_L;PIN6_H; }
				   if(Dispinfo.Disp_Data&c_bit_5){ PIN1_L;PIN7_H; }
				 break;
				 
				
				 
				 
				 case 1:
					   if(Dispinfo.Disp_Data&c_bit_6){ PIN2_L;PIN1_H; }
					   if(Dispinfo.Disp_Data&c_bit_7){ PIN2_L;PIN3_H; }
				     if(Dispinfo.Disp_Data&c_bit_8){ PIN2_L;PIN4_H; }
						if(Dispinfo.Disp_Data&c_bit_9) { PIN2_L;PIN5_H; }
					  if(Dispinfo.Disp_Data&c_bit_10){ PIN2_L;PIN6_H; }
				    if(Dispinfo.Disp_Data&c_bit_11){ PIN2_L;PIN7_H; }
				 break;
				 
				 
				 
				 
				 case 2:
					 
				     if(Dispinfo.Disp_Data&c_bit_12){ PIN3_L;PIN1_H; }
					   if(Dispinfo.Disp_Data&c_bit_13){ PIN3_L;PIN2_H; }
				     if(Dispinfo.Disp_Data&c_bit_14){ PIN3_L;PIN4_H; }
					   if(Dispinfo.Disp_Data&c_bit_15){ PIN3_L;PIN5_H; }
					   if(Dispinfo.Disp_Data&c_bit_16){ PIN3_L;PIN6_H; }
				     if(Dispinfo.Disp_Data&c_bit_17){ PIN3_L;PIN7_H; }
				 break;
				 
				 
				
				 
				 
				 case 3:
					   if(Dispinfo.Disp_Data&c_bit_18){ PIN4_L;PIN1_H; }
					   if(Dispinfo.Disp_Data&c_bit_19){ PIN4_L;PIN2_H; }
				     if(Dispinfo.Disp_Data&c_bit_20){ PIN4_L;PIN3_H; }
				     if(Dispinfo.Disp_Data&c_bit_21){ PIN4_L;PIN5_H; }
					   if(Dispinfo.Disp_Data&c_bit_22){ PIN4_L;PIN6_H; }
				     if(Dispinfo.Disp_Data&c_bit_23){ PIN4_L;PIN7_H; }
				 break;
				 
				 
				 
				 case 4:
					   if(Dispinfo.Disp_Data&c_bit_24){ PIN5_L;PIN1_H; }
					   if(Dispinfo.Disp_Data&c_bit_25){ PIN5_L;PIN2_H; }
						 if(Dispinfo.Disp_Data&c_bit_26){ PIN5_L;PIN3_H; }
					   if(Dispinfo.Disp_Data&c_bit_27){ PIN5_L;PIN4_H; }
			
				       if(Dispinfo.Disp_Data&c_bit_28){ PIN5_L;PIN6_H;PIN7_H; }
						 
				 break;
				 

         case 5:
					
               if(Dispinfo.Disp_Data&c_bit_29){ PIN6_L;PIN1_H;PIN2_H; } 
               if(Dispinfo.Disp_Data&c_bit_30){ PIN6_L;PIN3_H;PIN4_H;PIN5_H; }	 
						 
         break;
			 }
			 if(Dispinfo.Disp_offset < 5){Dispinfo.Disp_offset++;}else{Dispinfo.Disp_offset = 0;Breath_Deal();}



       #endif			 
			 
			 
		 }
	}
  #endif
		
		
		
		
  }
}






//100us


void TIM1_BRK_UP_TRG_COM_IRQHandler(void)
{
	if((LL_TIM_ReadReg(TIM1,SR) & LL_TIM_SR_UIF) == 1 && LL_TIM_IsEnabledIT_UPDATE(TIM1))
  {
    LL_TIM_ClearFlag_UPDATE(TIM1);
    tim_flag++;   
  }
}
/******************************************************************************/
/* PY32C642 Peripheral Interrupt Handlers                                     */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file.                                          */
/******************************************************************************/

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
