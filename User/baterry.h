#ifndef _BATERRY_H
#define _BATERRY_H

typedef  struct
{
  
	 u16   Bat_Volt;
	 u16   adc_value;
   u16   test_value_1v2;
   u8    Bat_Low_Lock;
	 u8    Bat_Leve; 
   u8    Oil_Leve;    
   u32   Bat_Leve_Data;	
	 u8    Bat_Leve_Delay_Cnt;
   u16   Bat_Charge_Up_Cnt;
   u16   Bat_Charge_Error_Up_Cnt;
	
	 u16   Bat_Out_Smok_Time;   
	 u8    Bat_Down_En;
	
	 u8    Ovp_En;
	 u8    OvpOn_Cnt;
	 u8    OvpOff_Cnt;
	 u16   Usb_Ad_Volt;
	
	
	 u8    Usb_Full_Flag;
	 u8    Usb_Led_Twinkle_Cnt;
	 u16   Usb_Disp_Long_Cnt;
	 
	u16   Usb_Disp_Full_Cnt;
	

}BatInfoTypedef;

extern u32 Oil_Time;
extern BatInfoTypedef   BatInfo;


void          BatVoltage(void);
void          Get_Bat_Leve_Map(void);
void          Get_Bat_Leve(void);
void          Smok_Start_Bat_Leve_Deal(void);
void  			  Get_Power_Rest_BatLeve(void);



extern const u32  Bat_Leve_List[];

extern const u16 _Bat_Leve_digit_List[];


extern const  u32 _t_list_digit_list_d1[];

extern const  u32 _t_list_digit_list_d0[];














#endif



