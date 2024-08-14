#include "main.h"






Dispinfotypedef    Dispinfo;




const u16 Horse_Run_List[]=
{
  0x07,
  0x0F,
  0x1F,
  0x3F,
  0x7F,
  0xFF,
  0x1FF,
  0x3FF,
  0x7FF,
  0xFFF,
  0x1FFF,
  0x3FFF,
};

const u16 Horse_Run_R_List[]=
{
  0x449,
  0xDDB,//0x992,
  0x3FFF,
};



const u8 _t_list_digit_list[]=
{
		0X3F ,
		0X6  ,
		0X5B ,
		0X4F ,
		0X66 ,
		0X6D ,
		0X7D ,
		0X7  ,
		0X7F ,
		0X6F ,
};



const u8 Out_Gear[]=
{   
	  0x10,
    0x10,
    0x20,
};

u16 Disp_Num[8];

void     Breath_Deal(void)
{

  if(Dispinfo.Breath_En)
	{
	  //Dispinfo.Breath_Count = 32;
		
	  if(Dispinfo.Breath_Cycle < Dispinfo.Breath_Count){ Dispinfo.Breath_Cycle++;}
	  else
		{
		   Dispinfo.Breath_Cycle = 0;
			
			 if(Dispinfo.Breath_LM == 0)
			 {
			    if(Dispinfo.Breath_Duty < Dispinfo.Breath_Count){Dispinfo.Breath_Duty++;}
			    else
					{
					    if(Dispinfo.Breath_Num)
							{
							  Dispinfo.Breath_LM = 1;
							}
							else
							{
							  Dispinfo.Breath_En = 0;
							}
					}
			 }
			 else
			 {
			     if(Dispinfo.Breath_Duty > 0){Dispinfo.Breath_Duty--;}
			     else
					 {
					    if(Dispinfo.Breath_Num&&Dispinfo.Breath_Num < 100){Dispinfo.Breath_Num--;}
					    
							if(Dispinfo.Breath_Num)
							{
							  Dispinfo.Breath_LM = 0;
							}
							else
							{
							  Dispinfo.Breath_En = 0;
							}
					 
					 }
			 
			 
			 }
		
	
		}
		  if(Dispinfo.Breath_Cycle < Dispinfo.Breath_Duty)
      {  
        //Dispinfo.Disp_Data |= DISP_LOG_MASKE; 
        Led_L_Icon |= 0x0040;//c_bit_6;
      }
	    else
      {   
        //Dispinfo.Disp_Data &= ~DISP_LOG_MASKE; 
        Led_L_Icon &= 0xFFBFul;
      }
      
		  Dispinfo.Disp_EN = 1;
		
	}
}






void   Set_Disp_Num(u8 num,u16 low,u16 high,u16 data1,u16 data2,u16 data3,u16 data4,u16 data5,u16 data6,u16 data7,u16 data8)
{
	DIGA_IO;
	CHRG_EN;
	Get_Bat_Leve_Map();
//	Dispinfo.Breath_En = 0;
//	Dispinfo.Breath_Duty = 0;
//	Dispinfo.Breath_Cycle = 0;
//	Dispinfo.Breath_Count = 0;
//	Dispinfo.Breath_LM    = 0;
	OutInfo.Out_Mos_Interrup_Ctr_Flag = 0;
  CLR_OUTLOAD;
  MOS_OFF;
  Dispinfo.Disp_Time = 0;
  Dispinfo.Disp_Num = num;
	Dispinfo.Disp_Low_Time = low;
  Dispinfo.Disp_High_Time = high;
  Led_Num[0] = data1;
  Led_Num[1] = data2;
  Led_Num[2] = data3;
  Led_Num[3] = data4;
  Led_Icon =   data5;
  Led_L_Icon = data6;
  Led_M_Icon = data7;
  Led_R_Icon = data8;
  //Dispinfo.Disp_Data  = data1;
	Clr_Data();
}






void   DISP_Deal(void)
{

  if(Dispinfo.Disp_Num)
  {
	   if(++Dispinfo.Disp_Time < Dispinfo.Disp_Low_Time) 
     {
        Dispinfo.Disp_EN = 0;
     }
		 else if(Dispinfo.Disp_Time > Dispinfo.Disp_High_Time)
		 {
		   Dispinfo.Disp_Time = 0;
			 Dispinfo.Disp_Num--;
			 if(!Dispinfo.Disp_Num)
		   {
			   
				  if(Dispinfo.Disp_Task == PowerOnReset)
			    {
					  SysInfo.Sleep_Time = 5;
						Dispinfo.Disp_Task = Idle;
					
					}
					else
					{
					  Dispinfo.Disp_Task = Idle;
					}
			    Dispinfo.Disp_EN = 0;
			 }
		 }
		 else
     {
        Dispinfo.Disp_EN = 1;
     }	
	}
 
	else if(OUTLOAD)
	{
//	    if(!Dispinfo.Breath_En)
//			{
//			   Dispinfo.Breath_En = 1;
//			   Dispinfo.Breath_Cycle = 0;
//  			 Dispinfo.Breath_Count = 70;
//			   Dispinfo.Breath_LM    = 0;
//			   Dispinfo.Breath_Duty  = 0;
//				 Dispinfo.Breath_Num   = 0;
//				 Dispinfo.Disp_Data = BatInfo.Bat_Leve_Data;
//			}

          if(Dispinfo.Paoma_Time < 15){Dispinfo.Paoma_Time++;}
          else
          {
              Dispinfo.Paoma_Time = 0;
              if(Dispinfo.Paoma_Cnt < 11)
              {
                Dispinfo.Paoma_Cnt++;
              }
              else
              {
                Dispinfo.Paoma_Cnt = 0;
              }

              if(Dispinfo.Paoma_Cnt1 < 2)
              {
                Dispinfo.Paoma_Cnt1++;
              }  
          }
        Get_Bat_Leve_Map();
        Led_Num[0] = Disp_Num[0];
        Led_Num[1] = Disp_Num[1];
        Led_Num[2] = Disp_Num[2];
        Led_Num[3] = Disp_Num[3];
        Led_Icon =   Disp_Num[4];
        Led_L_Icon = 0xffff;
        Led_M_Icon = Horse_Run_List[Dispinfo.Paoma_Cnt];
        Led_R_Icon = Horse_Run_R_List[Dispinfo.Paoma_Cnt1];
	      Dispinfo.Disp_EN = 1;
	
	}
  else if(USBIN)
	{
//	  if(!BatInfo.Ovp_En)
//    {
//       if(BatInfo.Usb_Ad_Volt >= 1150)
//       {
//          if(CHRG_IO)
//          {
//            if(++BatInfo.OvpOn_Cnt >= 50)
//            {
//                BatInfo.OvpOn_Cnt = 0;
//                BatInfo.Ovp_En = 1;
//                Disp_Ovp_EN;
//              
//            }
//            return;
//          }
//        }
//    }
//    else
//    {
//      if(BatInfo.Usb_Ad_Volt <= 1000)
//      {
//          if(!CHRG_IO)
//          {
//            if(++BatInfo.OvpOff_Cnt >= 50)
//            {
//                BatInfo.OvpOff_Cnt = 0;
//                BatInfo.Ovp_En = 0;
//            }
//          }
//          Dispinfo.Disp_EN = 0;	
//        
//      }
//      return;
//    }

   Get_Bat_Leve_Map();
   
   if(!BatInfo.Usb_Full_Flag)
	 {   
		  
		    if(BatInfo.Bat_Leve >= 100)
        { 
            BatInfo.Usb_Disp_Full_Cnt = 1000; 
            BatInfo.Usb_Full_Flag = 1;
            return;  
        }
		 
		 
	      if(BatInfo.Usb_Led_Twinkle_Cnt < 100){BatInfo.Usb_Led_Twinkle_Cnt++;}
	      else{ BatInfo.Usb_Led_Twinkle_Cnt = 0;}
        
        
        if(BatInfo.Usb_Led_Twinkle_Cnt < 50)
        {
             Led_Icon = DISP_OIL_MASK|Out_Gear[Out_Mode];
        }
        else
        {
             Led_Icon = DISP_BAT_MASK|DISP_OIL_MASK|Out_Gear[Out_Mode];
        }
			  
    
        if(BatInfo.Bat_Leve >= 10)
        {
            if(BatInfo.Bat_Leve == 100)
            {
               Led_Num[0] = _t_list_digit_list[0];
               Led_Num[1] = _t_list_digit_list[0];
               Led_Icon  |= c_bit_0;
            }
            else
            {
               Led_Num[0] = _t_list_digit_list[BatInfo.Bat_Leve/10];
               Led_Num[1] = _t_list_digit_list[BatInfo.Bat_Leve%10];
            }
        }
        else
        {
            Led_Num[0] = 0;
            Led_Num[1] = _t_list_digit_list[BatInfo.Bat_Leve%10];
        }

        if(BatInfo.Oil_Leve >= 10)
        {
            if(BatInfo.Oil_Leve == 100)
            {
              Led_Num[2] = _t_list_digit_list[0];
              Led_Num[3] = _t_list_digit_list[0];
              Led_Icon  |= c_bit_2;
            }
            else
            {
              Led_Num[2] = _t_list_digit_list[BatInfo.Oil_Leve/10];
              Led_Num[3] = _t_list_digit_list[BatInfo.Oil_Leve%10];
            }
        }
        else
        {
            Led_Num[2] = 0;
            Led_Num[3] = _t_list_digit_list[BatInfo.Oil_Leve%10];
        }
//        if(Dispinfo.Paoma_Cnt < 2)
//        {
//          if(Dispinfo.Paoma_Time < 50){Dispinfo.Paoma_Time++;}
//          else
//          {
//              Dispinfo.Paoma_Time = 0;
//              if(Dispinfo.Paoma_Cnt < 2)
//              {
//                Dispinfo.Paoma_Cnt++;
//              }
//              else
//              {
//                Dispinfo.Paoma_Cnt = 0;
//              }
//          }
//        }
        
        Led_L_Icon = 0xffff;
        Led_M_Icon = 0xffff;
        Led_R_Icon = 0xffff;

			  Dispinfo.Disp_EN = 1;
			 
	 
	 }
	 else
	 {
      if(BatInfo.Usb_Disp_Full_Cnt)
      {
          BatInfo.Usb_Disp_Full_Cnt--; 
          Led_Icon = DISP_BAT_MASK|DISP_OIL_MASK|Out_Gear[Out_Mode];
          if(BatInfo.Bat_Leve == 100)
          {
             Led_Num[0] = _t_list_digit_list[0];
             Led_Num[1] = _t_list_digit_list[0];
             Led_Icon  |= c_bit_0;
          }
          else
          {
             Led_Num[0] = _t_list_digit_list[BatInfo.Bat_Leve/10];
             Led_Num[1] = _t_list_digit_list[BatInfo.Bat_Leve%10];
          }

          if(BatInfo.Oil_Leve >= 10)
          {
             if(BatInfo.Oil_Leve == 100)
             {
               Led_Num[2] = _t_list_digit_list[0];
               Led_Num[3] = _t_list_digit_list[0];
               Led_Icon  |= c_bit_2;
             }
             else
             {
               Led_Num[2] = _t_list_digit_list[BatInfo.Oil_Leve/10];
               Led_Num[3] = _t_list_digit_list[BatInfo.Oil_Leve%10];
             }
          }
          else
          {
              Led_Num[2] = 0;
              Led_Num[3] = _t_list_digit_list[BatInfo.Oil_Leve%10];
          }

          Led_L_Icon = 0xffff;
          Led_M_Icon = 0xffff;
          Led_R_Icon = 0xffff;
          Dispinfo.Disp_EN = 1;
      }
			else
			{
        Dispinfo.Disp_EN = 0;
			}	
	 
	 }
	}		
	
}













