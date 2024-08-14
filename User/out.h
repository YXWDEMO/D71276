#ifndef _OUT_H
#define _OUT_H




#define      DUTY_MAX_VOLT              200
#define      DUTY_MIN_VOLT              20



#define     OUT_RMS_EN                  1


typedef  struct
{
  u8   Out_Mos_Interrup_Ctr_Flag;
	u16  Out_Pwm_Duty_Temp;
	u8   Out_Pwm_Duty;
  u8   Out_Pwm_Duty1;
	u8   Out_Pwm_Cycle;
	u8   No_Heat_Cnt;
	u8   Out_Duty_Main_Deal_Flag;
  u8   Bat_Low_Cnt;
	u16  Out_Adc_Volt;
  u16  Out_Adc_Volt1;
	u16  Out_Volt;
  u16  Out_Volt1;
  u16  Short_Volt;
	u8   Smok_Time;
	u16  Set_Out_Volt;
  u16  Set_Out_Volt1;
  u8   Oil_Leve;
	u8   Out_Gear_Leve;
  u8   Out_Gear_Leve_Last;
	u16  Out_Oil_Time;
	u32  Oil_Data_Map;
	
	
	u8   Out_Short_Check_En;      //���Լ���·
	u8   Out_Short_Check_Load;    //���ڼ���·
	u8   Out_Short_Check_Error;   //����Ƿ����

}OutInfoTypedef;

extern  OutInfoTypedef    OutInfo;


extern     u8    Out_Mode;//���ģʽ 0:����  1:������ǿ  2:˫��
extern     u8    Out_Load;//�������˿ѡ��
extern     u8    Out_Load_Cnt;//�������˿����


void    Get_Oil_Leve(void);
void    Out_Deal(void);
void    Short(void);
void    Interrup_Ctr_Mos_Deal(void);


#endif


