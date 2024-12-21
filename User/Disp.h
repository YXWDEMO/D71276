#ifndef _DISP_H
#define _DISP_H




#include "py32c642_ll_gpio.h"








#define c_bit_0		0x01ul
#define c_bit_1		0x02ul
#define c_bit_2		0x04ul
#define c_bit_3		0x08ul
#define c_bit_4		0x10ul
#define c_bit_5		0x20ul
#define c_bit_6		0x40ul
#define c_bit_7		0x80ul
#define c_bit_8		0x100ul
#define c_bit_9		0x200ul
#define c_bit_10	0x400ul
#define c_bit_11	0x800ul
#define c_bit_12	0x1000ul
#define c_bit_13	0x2000ul
#define c_bit_14	0x4000ul
#define c_bit_15	0x8000ul
#define c_bit_16	0x10000ul
#define c_bit_17	0x20000ul
#define c_bit_18	0x40000ul
#define c_bit_19	0x80000ul
#define c_bit_20	0x100000ul
#define c_bit_21	0x200000ul
#define c_bit_22	0x400000ul
#define c_bit_23	0x800000ul
#define c_bit_24	0x1000000ul
#define c_bit_25	0x2000000ul
#define c_bit_26	0x4000000ul
#define c_bit_27	0x8000000ul
#define c_bit_28	0x10000000ul
#define c_bit_29	0x20000000ul
#define c_bit_30	0x40000000ul
#define c_bit_31	0x80000000ul



//PB2 PB3 PB4 PB5 共使用4个IO驱动段码屏

#define   PIN1_IN       {  LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_2, LL_GPIO_MODE_INPUT);   LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_2); }
#define   PIN2_IN       {  LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_3, LL_GPIO_MODE_INPUT);   LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_3); }
#define   PIN3_IN       {  LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_4, LL_GPIO_MODE_INPUT);   LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_4); }
#define   PIN4_IN       {  LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_5, LL_GPIO_MODE_INPUT);   LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_5); }

#define   PIN5_IN       {  LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_2, LL_GPIO_MODE_INPUT);   LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_2); }
#define   PIN6_IN       {  LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_3, LL_GPIO_MODE_INPUT);   LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_3); }
#define   PIN7_IN       {  LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_4, LL_GPIO_MODE_INPUT);   LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_4); }
#define   PIN8_IN       {  LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_5, LL_GPIO_MODE_INPUT);   LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_5); }


#define   PIN1_L         {LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_2);        LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_2, LL_GPIO_MODE_OUTPUT);   LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_2, LL_GPIO_OUTPUT_PUSHPULL);  }
#define   PIN2_L         {LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_3);        LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_3, LL_GPIO_MODE_OUTPUT);   LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_3, LL_GPIO_OUTPUT_PUSHPULL);  }
#define   PIN3_L         {LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_4);        LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_4, LL_GPIO_MODE_OUTPUT);   LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_4, LL_GPIO_OUTPUT_PUSHPULL);  }
#define   PIN4_L         {LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_5);        LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);   LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_5, LL_GPIO_OUTPUT_PUSHPULL);  }

#define   PIN5_L         {LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_2);        LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_2, LL_GPIO_MODE_OUTPUT);   LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_2, LL_GPIO_OUTPUT_PUSHPULL);  }
#define   PIN6_L         {LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_3);        LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_3, LL_GPIO_MODE_OUTPUT);   LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_3, LL_GPIO_OUTPUT_PUSHPULL);  }
#define   PIN7_L         {LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_4);        LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_4, LL_GPIO_MODE_OUTPUT);   LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_4, LL_GPIO_OUTPUT_PUSHPULL);  }
#define   PIN8_L         {LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_5);        LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);   LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_5, LL_GPIO_OUTPUT_PUSHPULL);  }


								 
#define   PIN1_H         { LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_2);        LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_2, LL_GPIO_MODE_OUTPUT);     LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_2, LL_GPIO_OUTPUT_PUSHPULL);    }
#define   PIN2_H         { LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_3);        LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_3, LL_GPIO_MODE_OUTPUT);     LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_3, LL_GPIO_OUTPUT_PUSHPULL);    }
#define   PIN3_H         { LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_4);        LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_4, LL_GPIO_MODE_OUTPUT);     LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_4, LL_GPIO_OUTPUT_PUSHPULL);    }
#define   PIN4_H         { LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_5);        LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);     LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_5, LL_GPIO_OUTPUT_PUSHPULL);    }

#define   PIN5_H         { LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_2);        LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_2, LL_GPIO_MODE_OUTPUT);     LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_2, LL_GPIO_OUTPUT_PUSHPULL);    }
#define   PIN6_H         { LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_3);        LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_3, LL_GPIO_MODE_OUTPUT);     LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_3, LL_GPIO_OUTPUT_PUSHPULL);    }
#define   PIN7_H         { LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_4);        LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_4, LL_GPIO_MODE_OUTPUT);     LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_4, LL_GPIO_OUTPUT_PUSHPULL);    }
#define   PIN8_H         { LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_5);        LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);     LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_5, LL_GPIO_OUTPUT_PUSHPULL);    }
												 




//-------------------------- 运行事件枚举 -----------------------------------------
#if 1
typedef enum{
    Idle=0,         	//空闲
    PowerOnReset, 	//上电
    PowerOff,     	//关机
    PowerOn,      	//开机
    LowVol,       	//低电
	LowInVol,       	//低电
	  LowDeal=5,        //低电延时
    LowRes,       	//低阻或短路
    HighRes,      	//高阻或开路
    OverTime,     	//超时
    Rechg,        	//充电
    RechgFull=10,   	//充电满
    RechgFullEnd,   //充电满结束
    UsbIn,          //USB接入
    UsbOut,     	  //USB拔掉
    RL_In,     //接入负载
    RL_Out=15,    //移除负载
	  SMOK_RGB,  //多彩灯开关亮灯
  	OverStop,  //吸烟结束
  	OverStopSetup2,  //吸烟结束第二阶段显示
    VoutGearSet_Off, //档位
	VoutGearSet_Ch,
	VoutGearSet_L1, //
	VoutGearSet_L2, //
    SelectKeyOut,   //选择按键输出
//    PreHeat,
     SelectMiOut,    //选择咪头输出
	 Dis_Oil=22,
	 Dis_Bat,
	 Dis_Ovp,
   UsbFirstIn,          //USB首次接入

}EmRunEvent;
#endif


enum{
	CHANGE_GEARS_EFFECT_L1_L0,
	CHANGE_GEARS_EFFECT_L2_L0,
	CHANGE_GEARS_EFFECT_L1,
	CHANGE_GEARS_EFFECT_L2,
};

typedef   struct 
{
	u8    Disp_EN;
	u8    Disp_offset;
  u8    sys_led_display_isr_cnt;
  u32   Disp_Data;
	u32   Disp_Data1;

	u8    Disp_Task;
	u8    Disp_Num;
	u16   Disp_Smoke_Time;
	u16   Disp_Smoke_Effect_Cnt;
	u16   Disp_Smoke_Effect_Cnt1;
	u8    Disp_pwm;
	u8    Disp_pwm_star;
	u16   Disp_Time;
	u16   Disp_Low_Time;
	u16   Disp_High_Time;
    u16   Smg_Paoma_Time;
	u16   Smg_Paoma_Time_stop;
	u8    Smg_Paoma_Cnt;
	u8    Smg_Go_Ch;
	u8    Disp_Smok_Error_Flag;
	u8    Disp_Horse_Cnt;
	u8    Disp_Out_Delay;
	u8    Disp_Ic_Rgb_Digi_Syn_Flag;
	u8    Disp_Usb_Ic_Rgb_Off_Flag;
	u8		Dis_Change_Gears_Effect;
	u8   	Disp_Smoke_Stop_Effect_Flag;
	u32   Led_Disp_Data;
	u16   Disp_old_bat;
	u16   Disp_old_oil;
	u8    Disp_cl_bat;
	u8    Disp_go_ch;
	//软屏更新标志
	u8 Disp_Update_Bat;
	u8 Disp_Update_Oil;
	u8 Disp_Update_dolphin;
	u8 Disp_Update_contour;
	u8 Disp_Update_star;
	u8 Disp_Update_bigstar;
}Dispinfotypedef;




enum
{
  _0Yard = 0,
	_1Yard,
  _Other_Yard,

};

////REST码     全是0 最小200us
//#define      



////
//#define  



////1码       
//#define 



extern const u32 Horse_Run_List[];

extern Dispinfotypedef    Dispinfo;

extern void   Set_Disp_Num(u8 num,u16 low,u16 high,u32 data1,u32 data2);
extern void   Disp_Drive(void);
extern void   DISP_Deal(void);
extern void    Horse_Run_Deal(void);
extern void    Set_Yard_Data(u8 low,u8 hig,u8 Yard_mode);
extern void   Led_Test(u32 Data);
extern void     Led_Deal(u32 data);
extern void   Clr_Led(void);

void display_bat(unsigned char batleve,unsigned char pwm,unsigned char all);
void display_oil(unsigned char oilleve,unsigned char pwm,unsigned char all);
void display_bigstar(unsigned char eye,unsigned char pwm);
void display_contour_in(unsigned char pwm);
void display_geras(unsigned char pwm);
void display_star(char pwm);
void display_version(void);
void display_logo(unsigned char pwm);
void display_bat_L0(unsigned char pwm);
void display_oil_L0(unsigned char pwm);
void display_Oil_logo(unsigned char pwm);
void display_Bat_logo(unsigned char pwm);
void Smok_Disp_Deal(void);
void display_yellow(char pwm);
void low_run(u16 Disp_Time);
extern unsigned char Smg_Paoma_En;
extern unsigned char Smg_Paoma_En_stop;
extern const u16 _t_list_digit_list_d1[];
extern const u32 _t_list_digit_list_d0[];
extern const u16 _t_list_digit_list_d3[];
extern const u32 _t_list_digit_list_d2[];
//全亮
#define     DISP_ALL               0XFFFFFFFFul
//火箭
#define     DISP_ROCKET_MASK       0X380000ul
//一档
#define     DISP_OUT_GEAR1         0X7F800ul|0XC0000000ul|DISP_ROCKET_MASK
//二档
#define     DISP_OUT_GEAR2         DISP_OUT_GEAR1|0X3FC00000ul|DISP_ROCKET_MASK
//LOG
#define     DISP_LOG_MASKE         0X1Ful

//油量图标
#define    OIL_DISP_MASK           0X20ul
//电量图标
#define    BAT_DISP_MASK           0X800ul

						
//上电
#define    Disp_Power_Rest         { Dispinfo.Disp_Task = PowerOnReset;   Dispinfo.Disp_Smok_Error_Flag = 1; Dispinfo.Disp_Ic_Rgb_Digi_Syn_Flag = 0;    			sysinit();Set_Disp_Num(1,0,200,DISP_ALL,0x00);}
//低电
#define    Disp_Bat_Low            { Dispinfo.Disp_Task = LowVol;        Smg_Paoma_En_stop=0;Dispinfo.Smg_Paoma_Cnt=0; Dispinfo.Disp_Smok_Error_Flag = 1; Dispinfo.Disp_Ic_Rgb_Digi_Syn_Flag = 1;Smg_Paoma_En_stop=0;Dispinfo.Smg_Paoma_Time_stop=0;Smg_Paoma_En = 0;Set_Disp_Num(10,25,50,0x00,0x00);}  
#define    Disp_Bat_In_Low            { Dispinfo.Disp_Task = LowInVol;        Smg_Paoma_En_stop=0;Dispinfo.Smg_Paoma_Cnt=0; Dispinfo.Disp_Smok_Error_Flag = 1; Dispinfo.Disp_Ic_Rgb_Digi_Syn_Flag = 1;Smg_Paoma_En_stop=0;Dispinfo.Smg_Paoma_Time_stop=0;Smg_Paoma_En = 0;Set_Disp_Num(4,25,50,0x00,0x00);}  
//高阻
#define    Disp_High               { Dispinfo.Disp_Task = HighRes;        Smg_Paoma_En_stop=0;Dispinfo.Smg_Paoma_Cnt=0;Dispinfo.Disp_Smok_Error_Flag = 1; Dispinfo.Disp_Ic_Rgb_Digi_Syn_Flag = 0;Smg_Paoma_En_stop=0;Dispinfo.Smg_Paoma_Time_stop=0;Dispinfo.Disp_cl_bat=0; sysinit();Set_Disp_Num(5,25,50,0x00,0x00);}  
//短路
#define    Disp_Short              { Dispinfo.Disp_Task = LowRes;        Smg_Paoma_En_stop=0;Dispinfo.Smg_Paoma_Cnt=0;Dispinfo.Disp_Smok_Error_Flag = 1; Dispinfo.Disp_Ic_Rgb_Digi_Syn_Flag = 0;Smg_Paoma_En_stop=0;Dispinfo.Smg_Paoma_Time_stop=0;Dispinfo.Disp_cl_bat=0; sysinit();Set_Disp_Num(3,25,50,0x00,0x00);}  
//超时
#define    Disp_SmokOver           { Dispinfo.Disp_Task = OverTime;    		Smg_Paoma_En_stop=0;Dispinfo.Smg_Paoma_Cnt=0;Dispinfo.Disp_Smok_Error_Flag = 1;   Dispinfo.Disp_Ic_Rgb_Digi_Syn_Flag = 1;  Smg_Paoma_En_stop=0;Dispinfo.Smg_Paoma_Time_stop=0;Smg_Paoma_En = 0;Dispinfo.Disp_cl_bat=0;  			sysinit();Set_Disp_Num(6,25,50,0x00,0x00);}    

//OVP保护
#define    Disp_Ovp_EN             { Dispinfo.Disp_Task = Dis_Ovp;        Smg_Paoma_En_stop=0;Dispinfo.Smg_Paoma_Cnt=0;Dispinfo.Disp_Smok_Error_Flag = 1;  Dispinfo.Disp_Ic_Rgb_Digi_Syn_Flag = 0;   			sysinit(); Set_Disp_Num(1,0,1000,0x00,0x00);}

//首次插入USB
#define    Disp_Power_Usb_In       { Dispinfo.Disp_Task = UsbFirstIn;     Smg_Paoma_En_stop=0;Dispinfo.Smg_Paoma_Cnt=0;Dispinfo.Disp_Smok_Error_Flag = 0;  Dispinfo.Disp_Ic_Rgb_Digi_Syn_Flag = 0;    			sysinit();Set_Disp_Num(1,0,200,DISP_ALL,0x00);}    


//USB拔出
#define    Disp_Usb_Out            { Dispinfo.Disp_Task = UsbOut;        Smg_Paoma_En_stop=0;Dispinfo.Smg_Paoma_Cnt=0; Dispinfo.Disp_Smok_Error_Flag = 0;  Dispinfo.Disp_Ic_Rgb_Digi_Syn_Flag = 0;    			sysinit();Set_Disp_Num(3,25,50,0x00,0x00);}    

//关机
#define    Disp_Gear_Off               { Dispinfo.Disp_Task = VoutGearSet_Off;    Dispinfo.Disp_Smok_Error_Flag = 0;  Dispinfo.Disp_Ic_Rgb_Digi_Syn_Flag = 0;  			sysinit();Set_Disp_Num(1,0,250,0x00,0x00);}
//1档
#define    Disp_Gear_L1               { Dispinfo.Disp_Task = VoutGearSet_L1;    Dispinfo.Disp_Smok_Error_Flag = 0;  Dispinfo.Disp_Ic_Rgb_Digi_Syn_Flag = 0;    			sysinit();Set_Disp_Num(1,0,275,0x00,0x00);}
//2档
#define    Disp_Gear_L2               { Dispinfo.Disp_Task = VoutGearSet_L2;    Dispinfo.Disp_Smok_Error_Flag = 0;  Dispinfo.Disp_Ic_Rgb_Digi_Syn_Flag = 0;    			sysinit();Set_Disp_Num(1,0,275,0x00,0x00);}
//吸烟结束
#define    Disp_Smok_Stop          { Dispinfo.Disp_Task = OverStop;   			Set_Disp_Num(1,0,600,0x00,0x00);}   
#define    Disp_Smok_Stop_Setup2   { Dispinfo.Disp_Task = OverStopSetup2;   Dispinfo.Disp_Smok_Error_Flag = 0; Dispinfo.Disp_Ic_Rgb_Digi_Syn_Flag = 0;     Set_Disp_Num(24,0,25,OutInfo.Oil_Data_Map|BatInfo.Bat_Leve_Data,0x00);}

#define    Disp_Poweron          { Dispinfo.Disp_Task = PowerOn;   	Smg_Paoma_En_stop=0;Dispinfo.Smg_Paoma_Cnt=0;		sysinit();Set_Disp_Num(1,0,450,0x00,0x00);}  
#endif




