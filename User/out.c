#include "main.h"









OutInfoTypedef    OutInfo;

u8    Out_Mode;//输出模式 0:单发  1:单发增强  2:双发
u8    Out_Load;//输出发热丝选择
u8    Out_Load_Cnt;//输出发热丝计数


//void   Short(void)
//{
//   if(OUTLOAD)
//	 {
//	    if(OutInfo.Out_Short_Check_En)
//	    {
//				OutInfo.Out_Short_Check_Error = 0;
//			  OutInfo.Out_Short_Check_Load = 1;
//				OutInfo.Out_Adc_Volt = GetADCValue(OUT_CHANNEL);
//			  OutInfo.Out_Short_Check_Load = 0;
//			  
//				if(OutInfo.Out_Short_Check_En&&!OutInfo.Out_Short_Check_Error)
//				{
//				   
//				  if(OutInfo.Out_Adc_Volt >= 200&&OutInfo.Out_Adc_Volt < 3500)
//					{
//					  Disp_Short;
//					  return;
//					}
//				
//				
//				}
//			}  
//	 }
//}



void   OutOffDeal(void)
{
   OutInfo.Out_Mos_Interrup_Ctr_Flag = 0;
	 MOS_OFF;  
   DIGA_IO;
}







void   Get_Out_Volt(void)
{ 
       if(Out_Mode == 2 || (!Out_Load))
       {
          OutInfo.Out_Adc_Volt = GetADCValue(OUT1_CHANNEL);
          OutInfo.Out_Volt = (u32)OutInfo.Out_Adc_Volt*BatInfo.Bat_Volt>>12;
       }
       if(Out_Mode == 2 || Out_Load)
       {
          OutInfo.Out_Adc_Volt1 = GetADCValue(OUT2_CHANNEL);
          OutInfo.Out_Volt1 = (u32)OutInfo.Out_Adc_Volt1*BatInfo.Bat_Volt>>12;
       }
}




void    Out_Deal(void)
{  
	
	
	
	
	
   u8   i = 0;
	
//	u8   Short_TestFlag = 0;
	
	
	
	 if(OUTSTART)
   {
	   CLR_OUTSTART;
     if(Dispinfo.Disp_Task == OverStop)
     {
        Dispinfo.Disp_Num = 0;
        Dispinfo.Disp_Task = 0;
     }
		 if(!Dispinfo.Disp_Num)
		 {
		   BatVoltage();
			 if(BatInfo.Bat_Volt <= 3200||BatInfo.Bat_Low_Lock)
			 { 
				 BatInfo.Bat_Leve = 0;
				 Get_Bat_Leve_Map();
				 BatInfo.Bat_Low_Lock = 1;
				 BatInfo.Bat_Out_Smok_Time = 0;  
         BatInfo.Bat_Down_En = 0;
			   Disp_Bat_Low;
			   return;
			 }
			 
			 
//			 if(!HEATIN)
//			 {
//			   Disp_No_Heat;
//			   return;
//			 }

			 OutInfo.Out_Mos_Interrup_Ctr_Flag = 0;
			 Smok_Start_Bat_Leve_Deal();
			 Set_Data();
       ATUO_IO;
//       Short_TestFlag = 0;
			 i = 50;
       
			 while(i)
       {
          i--;
          MOS1_ON;     
//          if(i < 40)
//          {  
//            //if(!HEAT_IO)
//            //{
//                MOS_OFF;
//                Short_TestFlag = 1;  
//                break; 
//            //}  
//          }     
       }
//			 if(Short_TestFlag)
//       { 
//          Disp_Short;
//          return;   
//       }
			 
			 
		 	 OutInfo.Out_Adc_Volt  = GetADCValue(OUT1_CHANNEL);
       OutInfo.Out_Adc_Volt1 = GetADCValue(OUT2_CHANNEL);
			 MOS_OFF;
			 

			 if(BatInfo.Bat_Volt <= 3600){OutInfo.Short_Volt = 3960;}
			 else{OutInfo.Short_Volt = 3960;}
			 
			 if(OutInfo.Out_Adc_Volt <= OutInfo.Short_Volt)
       {  
          Disp_Short;
          return; 
       }
//       else if(OutInfo.Out_Adc_Volt1 <= 3000 && OutInfo.Out_Adc_Volt1 >= 1500)
//		   {
//          //First_Heat_Flag = 0;
//          //Heat_Turn_Err = 1;
//          //Disp_HeatTurnSmoke;
//          //return;
//		   }
//		   else if(OutInfo.Out_Adc_Volt >= 4090)
//		   {
//          Disp_No_Heat;
//          return;
//		   }
       i = 50;
		   while(i){ i--;MOS2_ON;}
       OutInfo.Out_Adc_Volt  = GetADCValue(OUT1_CHANNEL);
       OutInfo.Out_Adc_Volt1 = GetADCValue(OUT2_CHANNEL);
       MOS_OFF;
       if(OutInfo.Out_Adc_Volt1 <= OutInfo.Short_Volt)
       {  
          Disp_Short;
          return; 
       }
//       else if(OutInfo.Out_Adc_Volt <= 3000 && OutInfo.Out_Adc_Volt >= 1500)
//		   {
//          //First_Heat_Flag = 0;
//          //Heat_Turn_Err = 1;
//          //Disp_HeatTurnSmoke;
//          //return;
//		   }
//		   else if(OutInfo.Out_Adc_Volt1 >= 4090)
//		   {
//          Disp_No_Heat;
//          return;
//		   }
			 else
			 {  
				  CHRG_DIS;

          if(Out_Mode == 2)
          {
                OutInfo.Set_Out_Volt  = 3330;
                OutInfo.Set_Out_Volt1 = 3330;
                MOS_ON;
                OutInfo.Out_Pwm_Duty  = DUTY_MAX_VOLT;
                OutInfo.Out_Pwm_Duty1 = DUTY_MAX_VOLT;
                OutInfo.Out_Pwm_Cycle = 0;
          }
          else
          {
                if(Out_Load_Cnt<2)
                {
                  Out_Load_Cnt++;
                }
                else
                {
                  Out_Load_Cnt = 0;
                  if(Out_Load)
                  {
                    Out_Load = 0;
                  }
                  else
                  {
                    Out_Load = 1;
                  }
                }
                if(Out_Mode == 1)
                {
                   if(Out_Load)
                   {
                     OutInfo.Set_Out_Volt1 = 3530;
                     MOS2_ON;
                     OutInfo.Out_Pwm_Duty1 = DUTY_MAX_VOLT;
                     OutInfo.Out_Pwm_Cycle = 0;
                   }
                   else
                   {
                     OutInfo.Set_Out_Volt = 3530;
                     MOS1_ON;
                     OutInfo.Out_Pwm_Duty  = DUTY_MAX_VOLT;
                     OutInfo.Out_Pwm_Cycle = 0;
                   }
                }
                else
                {
                   if(Out_Load)
                   {
                      OutInfo.Set_Out_Volt1 = 3480;
                      MOS2_ON;
                      OutInfo.Out_Pwm_Duty1 = DUTY_MAX_VOLT;
                      OutInfo.Out_Pwm_Cycle = 0;
                   }
                   else
                   {
                      OutInfo.Set_Out_Volt = 3480;
                      MOS1_ON;
                      OutInfo.Out_Pwm_Duty  = DUTY_MAX_VOLT;
                      OutInfo.Out_Pwm_Cycle = 0;
                   }
                }
               
          }
          
				  
		      
				  OutInfo.Smok_Time = 100;
				  OutInfo.Bat_Low_Cnt = 0;

			    OutInfo.Out_Mos_Interrup_Ctr_Flag = 1;
				  
				  SET_OUTLOAD;
//		      Dispinfo.Breath_En = 0;
			    OutInfo.No_Heat_Cnt = 0;
				  Dispinfo.Paoma_Time = 0;
          Dispinfo.Paoma_Cnt = 0;
          Dispinfo.Paoma_Cnt1 = 0;
//				  Dispinfo.Breath_En = 1;
//			    Dispinfo.Breath_Cycle = 0;
//  			  Dispinfo.Breath_Count = BREATH_CYCLE_MAX_VOLT;
//			    Dispinfo.Breath_LM    = 0;
//			    Dispinfo.Breath_Duty  = 0;
//				  Dispinfo.Breath_Num   = 0;
				  //Dispinfo.Disp_Data = BatInfo.Bat_Leve_Data;
				  OutInfo.Out_Short_Check_En = 1;  
			 }
		 }
	 }
  
	 if(OUTLOAD)
	 {  
//		   if(OutInfo.Out_Short_Check_En)
//	     {
//				OutInfo.Out_Short_Check_Error = 0;
//			  OutInfo.Out_Short_Check_Load = 1;
//        if(Out_Mode == 2 || (!Out_Load))
//        {  
//          OutInfo.Out_Adc_Volt = GetADCValue(OUT1_CHANNEL);
//        }
//        if(Out_Mode == 2 || Out_Load)
//        {  
//          OutInfo.Out_Adc_Volt = GetADCValue(OUT2_CHANNEL);
//        }     
//			  OutInfo.Out_Short_Check_Load = 0;
//			  
//				if(!OutInfo.Out_Short_Check_Error)
//				{
//				   
//				  if(OutInfo.Out_Adc_Volt < 3600)
//					{
//					  Disp_Short;
//					  return;
//					}
//				}
//			}
		 
		 
	   if(!OutInfo.Smok_Time)
     {  
        Disp_SmokOver;
        return;
     }
	   
		 if(OutInfo.Out_Duty_Main_Deal_Flag == 1)
		 {
		    OutInfo.Out_Duty_Main_Deal_Flag = 0;
			 
			  BatVoltage();
			 
			  if(BatInfo.Bat_Volt <= 2800)
        {
          OutInfo.Bat_Low_Cnt++;
        }
				if(OutInfo.Bat_Low_Cnt >= 3)
        {
          OutInfo.Bat_Low_Cnt = 0; 
          BatInfo.Bat_Leve = 0;
				  Get_Bat_Leve_Map(); 
          BatInfo.Bat_Out_Smok_Time = 0;  
          BatInfo.Bat_Down_En = 0;
				  BatInfo.Bat_Low_Lock = 1;
          Disp_Smok_Bat_Low;
          return;  
        }	
				
				Get_Out_Volt();
				
				
//				if(OutInfo.Out_Adc_Volt >= 4095)
//				{
//				   
//				  if(++OutInfo.No_Heat_Cnt >= 20)
//					{
//					   OutInfo.No_Heat_Cnt = 0;
//						 DIGA_IO;
//						 OutInfo.Out_Mos_Interrup_Ctr_Flag = 0;
//						 MOS_OFF;
//						
//						 delay_us(100);
//						
//						
//						 if(HEAT_IO)
//						 {
//							 Disp_No_Heat;
//						   CLR_HEATSTART;
//						   CLR_HEATIN;
//						   ScanInfo.PortScan_Old  = ScanInfo.PortScan_New;
//							 return;
//						 }else{   ATUO_IO; OutInfo.Out_Mos_Interrup_Ctr_Flag = 1; }
//						
//					
//					}
//				
//				
//				
//				}else{OutInfo.No_Heat_Cnt = 0;}
				
				if(Out_Mode == 2 || (!Out_Load))
        {
            OutInfo.Out_Pwm_Duty_Temp =  (u32)OutInfo.Set_Out_Volt*200ul/OutInfo.Out_Volt;

            if(OutInfo.Out_Pwm_Duty_Temp >= DUTY_MAX_VOLT)
            {  
              OutInfo.Out_Pwm_Duty = DUTY_MAX_VOLT;
            }
            else if(OutInfo.Out_Pwm_Duty_Temp <= DUTY_MIN_VOLT)
            {
              OutInfo.Out_Pwm_Duty  = DUTY_MIN_VOLT;
            }
            else
            {
            #if   OUT_RMS_EN					
                  OutInfo.Out_Pwm_Duty = OutInfo.Out_Pwm_Duty_Temp * OutInfo.Out_Pwm_Duty_Temp/DUTY_MAX_VOLT;
            #else
                  OutInfo.Out_Pwm_Duty = OutInfo.Out_Pwm_Duty_Temp;
            #endif	
            }
        }
        if(Out_Mode == 2 || Out_Load)
        {
            OutInfo.Out_Pwm_Duty_Temp =  (u32)OutInfo.Set_Out_Volt1*200ul/OutInfo.Out_Volt1;
				
            if(OutInfo.Out_Pwm_Duty_Temp >= DUTY_MAX_VOLT)
            {  
                OutInfo.Out_Pwm_Duty1 = DUTY_MAX_VOLT;
            }
            else if(OutInfo.Out_Pwm_Duty_Temp <= DUTY_MIN_VOLT)
            {
                OutInfo.Out_Pwm_Duty1  = DUTY_MIN_VOLT;
            }
            else
            {
            #if   OUT_RMS_EN					
                  OutInfo.Out_Pwm_Duty1 = OutInfo.Out_Pwm_Duty_Temp * OutInfo.Out_Pwm_Duty_Temp/DUTY_MAX_VOLT;
            #else
                  OutInfo.Out_Pwm_Duty1 = OutInfo.Out_Pwm_Duty_Temp;
            #endif					
            }
        }
				
		 }
		 
	 
	 }
	 else
	 {
	    OutOffDeal();
	 
	 }




}








