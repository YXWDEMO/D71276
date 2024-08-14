#include "main.h"


u32 Oil_Time;


const u16 _Bat_Leve_digit_List[] = 
{
  3200,//0
  3520,//5					
	3595,//10
	3625,//15
	3655,//20	
	3675,//25			
	3685,//30	
	3690,//35		
	3705,//40	
	3735,//45			
	3755,//50					
	3785,//55
	3805,//60
	3835,//65	
	3865,//70			
	3895,//75	
	3935,//80		
	3975,//85	
	4025,//90			
	4065,//95
  4120,//100
};


//const  u32 _t_list_digit_list_d1[]=
//{
//		0X3F ,
//		0X6  ,
//		0X5B ,
//		0X4F ,
//		0X66 ,
//		0X6D ,
//		0X7D ,
//		0X7  ,
//		0X7F ,
//		0X6F ,



//};

//const  u32 _t_list_digit_list_d0[]=
//{
//		0X1F80 ,
//		0X300  ,
//		0X2D80 ,
//		0X2780 ,
//		0X3300 ,
//		0X3680 ,
//		0X3E80 ,
//		0X380  ,
//		0X3F80 ,
//		0X3780 ,
//};





//const u32  Bat_Leve_List[]=
//{   
//	  0         ,
//		0X40000   ,
//		0XC0000   ,
//		0X1C0000  ,
//		0X3C0000  ,
//		0X7C0000  ,
//		0XFC0000  ,
//		0X1FC0000 ,
//		0X3FC0000 ,
//		0X7FC0000 ,
//		0XFFC0000 ,

//};







BatInfoTypedef   BatInfo;






void     BatVoltage(void)
{
  
  BatInfo.adc_value= GetADCValue(BAT_CHANNEL);//sample vfent
	BatInfo.test_value_1v2 = Adc_CalBatRef();
  BatInfo.Bat_Volt =  (u32)BatInfo.test_value_1v2*4095ul/BatInfo.adc_value;

}



void    Get_Bat_Leve_Map(void)
{
    Disp_Num[4] = DISP_BAT_MASK|DISP_OIL_MASK|Out_Gear[Out_Mode];
    if(BatInfo.Bat_Leve >= 10)
        {
            if(BatInfo.Bat_Leve == 100)
            {
               Disp_Num[0] = _t_list_digit_list[0];
               Disp_Num[1] = _t_list_digit_list[0];
               Disp_Num[4] |= c_bit_0;
            }
            else
            {
               Disp_Num[0] = _t_list_digit_list[BatInfo.Bat_Leve/10];
               Disp_Num[1] = _t_list_digit_list[BatInfo.Bat_Leve%10];
            }
        }
        else
        {
            Disp_Num[0] = 0;
            Disp_Num[1] = _t_list_digit_list[BatInfo.Bat_Leve%10];
        }

        if(BatInfo.Oil_Leve >= 10)
        {
            
            if(BatInfo.Oil_Leve == 100)
            {
              Disp_Num[2] = _t_list_digit_list[0];
              Disp_Num[3] = _t_list_digit_list[0];
              Disp_Num[4] |= c_bit_2;
            }
            else
            {
              Disp_Num[2] = _t_list_digit_list[BatInfo.Oil_Leve/10];
              Disp_Num[3] = _t_list_digit_list[BatInfo.Oil_Leve%10];
            }
        }
        else
        {
            Disp_Num[2] = 0;
            Disp_Num[3] = _t_list_digit_list[BatInfo.Oil_Leve%10];
        }

  //u8  Temp = BatInfo.Bat_Leve;
	   
	
//	   if(Temp >= 100){  BatInfo.Bat_Leve_Data = DISP_100_MASK; }
//	   else 
//		 {  
//			  BatInfo.Bat_Leve_Data = _t_list_digit_list_d0[Temp%10];
//			 
//		    if(Temp >= 10)
//				{
//				    BatInfo.Bat_Leve_Data |= _t_list_digit_list_d1[Temp/10];
//				   
//				}
//		     
//		 
//		 
//		 }
//	   BatInfo.Bat_Leve_Data |= DISP_PER_MASK;
//		 
//		 BatInfo.Bat_Leve_Data  |= Bat_Leve_List[Temp/10];
		 
}







void   Get_Power_Rest_BatLeve(void)
{
  u8 i = 0;
	
  BatVoltage();
  BatInfo.Bat_Low_Lock = 0;
  
	if(BatInfo.Bat_Volt > _Bat_Leve_digit_List[20])
  {
    BatInfo.Bat_Leve = 100;
  }
	else if(BatInfo.Bat_Volt <= _Bat_Leve_digit_List[0])
  {
    BatInfo.Bat_Leve = 0;
    BatInfo.Bat_Low_Lock = 1;
  }
	else
	{
	
	   for(i = 1;i<= 19;i++)
		{
	    if(BatInfo.Bat_Volt <= _Bat_Leve_digit_List[i])	
		  {
			  BatInfo.Bat_Leve = i*5;
				break;
			}
		}
	}

 Get_Bat_Leve_Map();

}




void     Smok_Start_Bat_Leve_Deal(void)
{

   if(!BatInfo.Bat_Leve_Delay_Cnt)//回复一下电量  最小时间为2.5S
   {  

		   if(BatInfo.Bat_Leve >= 10)
			 {				
				if(BatInfo.Bat_Down_En)
			  {
		
	        if(BatInfo.Bat_Volt <=_Bat_Leve_digit_List[BatInfo.Bat_Leve/5-1])
			    {
            BatInfo.Bat_Leve-=5;
						BatInfo.Bat_Down_En = 0;
            BatInfo.Usb_Full_Flag = 0;
		     }
			 }
		 }
     else
		 {
		    BatInfo.Bat_Leve = 5;
		 
		 }			 
	 }


   Get_Bat_Leve_Map();


}







void   Get_Bat_Leve(void)
{
   u16 temp;
   if(OUTLOAD)
   {    
      BatInfo.Bat_Leve_Delay_Cnt = 25;   
      if(BatInfo.Bat_Out_Smok_Time <= 120)//12S
      {
          BatInfo.Bat_Out_Smok_Time++;
      }
      else
      {  
          BatInfo.Bat_Out_Smok_Time = 0;  
          BatInfo.Bat_Down_En = 1; 
      }
      return; 
   }
	 
	 if(BatInfo.Bat_Leve_Delay_Cnt){BatInfo.Bat_Leve_Delay_Cnt--;}
   else
	 {
	    BatVoltage();
      temp = (Oil_Time+1999)/2000;
      BatInfo.Oil_Leve = temp*5;
      if(BatInfo.Oil_Leve >= 100)
      {
          BatInfo.Oil_Leve = 100;
      }
		  if(USBIN)
			{
			   Get_Bat_Leve_Map();
				
          if(!BatInfo.Usb_Full_Flag)
          {
              if(BatInfo.Bat_Leve <= 95)	
              {
                //3分钟
                if(++BatInfo.Bat_Charge_Up_Cnt >= 1000)//2000
                {  
                    BatInfo.Bat_Volt+=110; //补偿一下有压降
                  
                    if(BatInfo.Bat_Volt >= _Bat_Leve_digit_List[BatInfo.Bat_Leve/5+1])//大于
                    {
                      BatInfo.Bat_Charge_Up_Cnt = 0;
                      BatInfo.Bat_Leve += 5;
                      BatInfo.Bat_Out_Smok_Time = 0;  
                      BatInfo.Bat_Down_En = 0; 
                      BatInfo.Bat_Low_Lock = 0;
                      BatInfo.Bat_Charge_Error_Up_Cnt = 0;
                    } 		
                }
              }


              if(BatInfo.Bat_Leve >= 100)
              {
                BatInfo.Bat_Leve = 100;
              }
              else
              {
                if(BatInfo.Bat_Leve >= 95)
                {
                  if(++BatInfo.Bat_Charge_Error_Up_Cnt >= 3000)//10分钟强制加一格3000
                  {
                      BatInfo.Bat_Charge_Error_Up_Cnt = 0;
                      BatInfo.Bat_Leve+= 5;
                  }
                }
              }

          }
			}
      else
      {  
          BatInfo.Bat_Charge_Up_Cnt = 0;  
          BatInfo.Bat_Charge_Error_Up_Cnt = 0;       
      }
	
	 }
}























