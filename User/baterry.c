#include "main.h"

u8 Smok_Down_EN;
const u16 _Bat_Leve_digit_List[] = 
{
3350,3400,3433,3458,3475,3490,3503,3515,3526,3537,//+11
3549,3559,3569,3579,3589,3599,3609,3619,3628,3637,//+10
3646,3654,3661,3669,3676,3683,3690,3696,3701,3705,//+87654
3709,3712,3715,3718,3721,3724,3727,3730,3733,3736,//+43
3739,3742,3745,3748,3751,3752,3754,3757,3760,3763,3766,//+3
3768,3771,3774,3777,3780,3784,3788,3793,3798,3803,//+345
3808,3813,3819,3825,3831,3837,3843,3849,3856,3863,//+567
3870,3877,3884,3891,3898,3905,3912,3920,3928,3936,//+78
3944,3952,3960,3968,3976,3985,3994,4004,4014,4024,//+8910
4034,4043,4052,4060,4065,4070,4075,4090,4120,//+910
};
const u16 _Bat_Charge_Leve_digit_List[] = 
{
	3610,3820,3880,3920,4030,
};

const u32  Oil_Leve_List[]=
{
		0X20,
		0X21,
		0X23,
		0X27,
		0X2F,
		0X3F,
};



const u32  Bat_Leve_List[]=
{   
	  0X800,
	  0X840,
		0X8C0,
		0X9C0,
		0XBC0,
		0XFC0,

};


BatInfoTypedef   BatInfo;


void     BatVoltage(void)
{
  
  BatInfo.adc_value= GetADCValue(BAT_CHANNEL);//sample vfent
	BatInfo.test_value_1v2 = Adc_CalBatRef();
  

  BatInfo.Bat_Volt =  (u32)BatInfo.test_value_1v2*4095ul/BatInfo.adc_value;

}



u8  Get_Bat_Leve_Map(u8 Get_Bat_Leve)
{

//  BatInfo.Bat_Leve_Data = Bat_Leve_List[Bat_Leve];
// //Low_Bat_Flag = 0;
	u32 Bat_Map = 0x00;
// 	u8 temp = 0;
// 	temp = Get_Bat_Leve;	

// 	if(temp >= 100)
// 	{
// 		Bat_Map = (_t_list_digit_list_d1[0]|_t_list_digit_list_d0[0]);
// 	} 
// 	else if(temp < 100)
// 	{
// 		if(temp < 10)
// 		{
// 			Bat_Map = _t_list_digit_list_d0[temp];
// 		} 
// 		else 
// 		{
// 			Bat_Map = _t_list_digit_list_d0[temp%10]|_t_list_digit_list_d1[temp/10];
// 		}
// 	}
// 	// Bat_Map |= DISP_light_mask;
 	return Bat_Map;     
}


void   Get_Power_Rest_BatLeve(void)
{
  u8 i = 0;
	
  BatVoltage();
  BatVoltage();
  BatVoltage();
  BatInfo.Bat_Low_Lock = 0;

	if(BatInfo.Bat_Volt <= _Bat_Leve_digit_List[0]){Bat_Leve = 0;BatInfo.Bat_Low_Lock = 1;}
	else if(BatInfo.Bat_Volt > _Bat_Leve_digit_List[99]){Bat_Leve = 100;}
	else
	{

	   for(i = 1;i < 100;i++)
		{
	    if(BatInfo.Bat_Volt < _Bat_Leve_digit_List[i])
		  {
			   
			  Bat_Leve = i;
			  break;
			}
		}
	
	
	}

  BatInfo.Bat_Leve_Data = Get_Bat_Leve_Map(Bat_Leve);
  Dispinfo.Disp_old_bat = Bat_Leve;

}


void  Smok_Start_Bat_Leve_Deal(void)
{

u8  temp;
	if(!BatInfo.Bat_Leve_Delay_Cnt)//é˜²æ?¢å¿«å?
	{   
	   
	   if(Bat_Leve <= 1)
	   {
	     Bat_Leve = 1;
	   }
	   else
	   {  
		  temp = (Bat_Leve-1); 
		  
	      if(BatInfo.Bat_Volt < _Bat_Leve_digit_List[temp])
	      {  
			BatInfo.Smok_Time_Down_Max_Cnt = 0;
			Bat_Leve--;
			Smok_Down_EN = 0;
	      }
	   }
	}
   BatInfo.Bat_Leve_Data=Get_Bat_Leve_Map(Bat_Leve);
}


void   Get_Bat_Leve(void)
{

	// u8 temp;
	if(OUTLOAD)
	{
		BatInfo.Bat_Leve_Delay_Cnt = 25;  
		BatInfo.Bat_Charge_Up_Cnt = 0;
		if(++BatInfo.Smok_Time_Down_Max_Cnt > 86)//5.0S
		{
			BatInfo.Smok_Time_Down_Max_Cnt = 0;
			Smok_Down_EN = 1;
		}
	
		return;
	}
  
	if(Smok_Down_EN)
	{
		Smok_Down_EN = 0;
//		if(!Bat_Need_Charge_Flag)
//		{
			if(Bat_Leve)
			{
				Bat_Leve--;
			}
			else
			{
				Bat_Leve = 0;
			}
//		}
	}
  
	if(BatInfo.Bat_Leve_Delay_Cnt){BatInfo.Bat_Leve_Delay_Cnt--;}
	else
	{   
	    BatVoltage();  
		if(USBIN)
		{   
				   
			if(Bat_Leve <= 99)
			{
				if(BatInfo.Bat_Volt > (_Bat_Leve_digit_List[Bat_Leve]))
				{
					if(BatInfo.Bat_Charge_Up_Cnt < 450){BatInfo.Bat_Charge_Up_Cnt++;}//45S
					else
					{
						BatInfo.Bat_Charge_Up_Cnt = 0;
						if(Bat_Leve == 99)
						{
							if(BatInfo.Bat_Charge_Up_Cnt_full < 6000){BatInfo.Bat_Charge_Up_Cnt_full++;}//45S
							else
							{
								Bat_Leve++;
							}
						}
						else{
							Bat_Leve++;
						}	
						BatInfo.Bat_Low_Lock = 0;
						BatInfo.Smok_Time_Down_Max_Cnt = 0;
						Smok_Down_EN = 0;
			   		}
		     	}
		   	}
		   	else
		   	{ 	   	
					BatInfo.Bat_Charge_Up_Cnt = 0;	 
					Bat_Leve = 100;
					BatInfo.Usb_Full_Flag = 1;
					BatInfo.Smok_Time_Down_Max_Cnt = 0;
					Smok_Down_EN = 0;
				
		   	}
			if(Bat_Leve >= 100)
			{
				Bat_Leve = 100;
				BatInfo.Usb_Full_Flag = 1;
			}
			if(BatInfo.Usb_Full_Flag&&(BatInfo.Bat_Volt < 4050))
			{
				Smg_Paoma_En=1;
				BatInfo.Usb_re_ch=1;
				Bat_Leve = 97;
				CHRG_ENABLE;
				BatInfo.Usb_Full_Flag = 0;
			}
	 	}   
		BatInfo.Bat_Leve_Data = Get_Bat_Leve_Map(Bat_Leve);
		
  	}   
}

