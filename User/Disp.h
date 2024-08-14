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

//防止出现阴影  输入后拉高数据位
//PA口输入
#define          PA0_IN               {  GPIOA->MODER &= 0XFFFFFFFCul;      GPIOA->BRR |= 0X00000001ul;  }
#define          PA1_IN               {  GPIOA->MODER &= 0XFFFFFFF3ul;      GPIOA->BRR |= 0X00000002ul;  } 
#define          PA2_IN               {  GPIOA->MODER &= 0XFFFFFFCFul;      GPIOA->BRR |= 0X00000004ul;  }
#define          PA3_IN               {  GPIOA->MODER &= 0XFFFFFF3Ful;      GPIOA->BRR |= 0X00000008ul;  }
#define          PA4_IN               {  GPIOA->MODER &= 0XFFFFFCFFul;      GPIOA->BRR |= 0X00000010ul;  }
#define          PA5_IN               {  GPIOA->MODER &= 0XFFFFF3FFul;      GPIOA->BRR |= 0X00000020ul;  }
#define          PA6_IN               {  GPIOA->MODER &= 0XFFFFCFFFul;      GPIOA->BRR |= 0X00000040ul;  }
#define          PA7_IN               {  GPIOA->MODER &= 0XFFFF3FFFul;      GPIOA->BRR |= 0X00000080ul;  }  
//PB口输入                                         
#define          PB0_IN               {  GPIOB->MODER &= 0XFFFFFFFCul;      GPIOB->BRR |= 0X00000001ul;  }
#define          PB1_IN               {  GPIOB->MODER &= 0XFFFFFFF3ul;      GPIOB->BRR |= 0X00000002ul;  } 
#define          PB2_IN               {  GPIOB->MODER &= 0XFFFFFFCFul;      GPIOB->BRR |= 0X00000004ul;  }
#define          PB3_IN               {  GPIOB->MODER &= 0XFFFFFF3Ful;      GPIOB->BRR |= 0X00000008ul;  }
#define          PB4_IN               {  GPIOB->MODER &= 0XFFFFFCFFul;      GPIOB->BRR |= 0X00000010ul;  }
#define          PB5_IN               {  GPIOB->MODER &= 0XFFFFF3FFul;      GPIOB->BRR |= 0X00000020ul;  }
#define          PB6_IN               {  GPIOB->MODER &= 0XFFFFCFFFul;      GPIOB->BRR |= 0X00000040ul;  }
#define          PB7_IN               {  GPIOB->MODER &= 0XFFFF3FFFul;      GPIOB->BRR |= 0X00000080ul;  }
//PC口输入                                         
#define          PC0_IN               {  GPIOC->MODER &= 0XFFFFFFFCul;      GPIOC->BRR |= 0X00000001ul;  }
#define          PC1_IN               {  GPIOC->MODER &= 0XFFFFFFF3ul;      GPIOC->BRR |= 0X00000002ul;  } 
#define          PC2_IN               {  GPIOC->MODER &= 0XFFFFFFCFul;      GPIOC->BRR |= 0X00000004ul;  }
#define          PC3_IN               {  GPIOC->MODER &= 0XFFFFFF3Ful;      GPIOC->BRR |= 0X00000008ul;  }
#define          PC4_IN               {  GPIOC->MODER &= 0XFFFFFCFFul;      GPIOC->BRR |= 0X00000010ul;  }
#define          PC5_IN               {  GPIOC->MODER &= 0XFFFFF3FFul;      GPIOC->BRR |= 0X00000020ul;  }
#define          PC6_IN               {  GPIOC->MODER &= 0XFFFFCFFFul;      GPIOC->BRR |= 0X00000040ul;  }
#define          PC7_IN               {  GPIOC->MODER &= 0XFFFF3FFFul;      GPIOC->BRR |= 0X00000080ul;  }






//PA输出高  先给电平  再配输出
#define          PA0_H               { GPIOA->BSRR |= 0X00000001ul; GPIOA->MODER &= 0XFFFFFFFCul; GPIOA->MODER |= 0X00000001ul;     }
#define          PA1_H               { GPIOA->BSRR |= 0X00000002ul; GPIOA->MODER &= 0XFFFFFFF3ul; GPIOA->MODER |= 0X00000004ul;     } 
#define          PA2_H               { GPIOA->BSRR |= 0X00000004ul; GPIOA->MODER &= 0XFFFFFFCFul; GPIOA->MODER |= 0X00000010ul;     }
#define          PA3_H               { GPIOA->BSRR |= 0X00000008ul; GPIOA->MODER &= 0XFFFFFF3Ful; GPIOA->MODER |= 0X00000040ul;     }
#define          PA4_H               { GPIOA->BSRR |= 0X00000010ul; GPIOA->MODER &= 0XFFFFFCFFul; GPIOA->MODER |= 0X00000100ul;     }
#define          PA5_H               { GPIOA->BSRR |= 0X00000020ul; GPIOA->MODER &= 0XFFFFF3FFul; GPIOA->MODER |= 0X00000400ul;     }
#define          PA6_H               { GPIOA->BSRR |= 0X00000040ul; GPIOA->MODER &= 0XFFFFCFFFul; GPIOA->MODER |= 0X00001000ul;     }
#define          PA7_H               { GPIOA->BSRR |= 0X00000080ul; GPIOA->MODER &= 0XFFFF3FFFul; GPIOA->MODER |= 0X00004000ul;     }
//PB输出高  先给电平  再配输出           
#define          PB0_H               { GPIOB->BSRR |= 0X00000001ul; GPIOB->MODER &= 0XFFFFFFFCul; GPIOB->MODER |= 0X00000001ul;     }
#define          PB1_H               { GPIOB->BSRR |= 0X00000002ul; GPIOB->MODER &= 0XFFFFFFF3ul; GPIOB->MODER |= 0X00000004ul;     } 
#define          PB2_H               { GPIOB->BSRR |= 0X00000004ul; GPIOB->MODER &= 0XFFFFFFCFul; GPIOB->MODER |= 0X00000010ul;     }
#define          PB3_H               { GPIOB->BSRR |= 0X00000008ul; GPIOB->MODER &= 0XFFFFFF3Ful; GPIOB->MODER |= 0X00000040ul;     }
#define          PB4_H               { GPIOB->BSRR |= 0X00000010ul; GPIOB->MODER &= 0XFFFFFCFFul; GPIOB->MODER |= 0X00000100ul;     }
#define          PB5_H               { GPIOB->BSRR |= 0X00000020ul; GPIOB->MODER &= 0XFFFFF3FFul; GPIOB->MODER |= 0X00000400ul;     }
#define          PB6_H               { GPIOB->BSRR |= 0X00000040ul; GPIOB->MODER &= 0XFFFFCFFFul; GPIOB->MODER |= 0X00001000ul;     }
#define          PB7_H               { GPIOB->BSRR |= 0X00000080ul; GPIOB->MODER &= 0XFFFF3FFFul; GPIOB->MODER |= 0X00004000ul;     }
//PC输出高  先给电平  再配输出           
#define          PC0_H               { GPIOC->BSRR |= 0X00000001ul; GPIOC->MODER &= 0XFFFFFFFCul; GPIOC->MODER |= 0X00000001ul;     }
#define          PC1_H               { GPIOC->BSRR |= 0X00000002ul; GPIOC->MODER &= 0XFFFFFFF3ul; GPIOC->MODER |= 0X00000004ul;     } 
#define          PC2_H               { GPIOC->BSRR |= 0X00000004ul; GPIOC->MODER &= 0XFFFFFFCFul; GPIOC->MODER |= 0X00000010ul;     }
#define          PC3_H               { GPIOC->BSRR |= 0X00000008ul; GPIOC->MODER &= 0XFFFFFF3Ful; GPIOC->MODER |= 0X00000040ul;     }
#define          PC4_H               { GPIOC->BSRR |= 0X00000010ul; GPIOC->MODER &= 0XFFFFFCFFul; GPIOC->MODER |= 0X00000100ul;     }
#define          PC5_H               { GPIOC->BSRR |= 0X00000020ul; GPIOC->MODER &= 0XFFFFF3FFul; GPIOC->MODER |= 0X00000400ul;     }
#define          PC6_H               { GPIOC->BSRR |= 0X00000040ul; GPIOC->MODER &= 0XFFFFCFFFul; GPIOC->MODER |= 0X00001000ul;     }
#define          PC7_H               { GPIOC->BSRR |= 0X00000080ul; GPIOC->MODER &= 0XFFFF3FFFul; GPIOC->MODER |= 0X00004000ul;     }




//PA输出低  先给电平  再配输出
#define          PA0_L               { GPIOA->BRR |= 0X00000001ul; GPIOA->MODER &= 0XFFFFFFFCul; GPIOA->MODER |= 0X00000001ul;      }
#define          PA1_L               { GPIOA->BRR |= 0X00000002ul; GPIOA->MODER &= 0XFFFFFFF3ul; GPIOA->MODER |= 0X00000004ul;      } 
#define          PA2_L               { GPIOA->BRR |= 0X00000004ul; GPIOA->MODER &= 0XFFFFFFCFul; GPIOA->MODER |= 0X00000010ul;      }
#define          PA3_L               { GPIOA->BRR |= 0X00000008ul; GPIOA->MODER &= 0XFFFFFF3Ful; GPIOA->MODER |= 0X00000040ul;      }
#define          PA4_L               { GPIOA->BRR |= 0X00000010ul; GPIOA->MODER &= 0XFFFFFCFFul; GPIOA->MODER |= 0X00000100ul;      }
#define          PA5_L               { GPIOA->BRR |= 0X00000020ul; GPIOA->MODER &= 0XFFFFF3FFul; GPIOA->MODER |= 0X00000400ul;      }
#define          PA6_L               { GPIOA->BRR |= 0X00000040ul; GPIOA->MODER &= 0XFFFFCFFFul; GPIOA->MODER |= 0X00001000ul;      }
#define          PA7_L               { GPIOA->BRR |= 0X00000080ul; GPIOA->MODER &= 0XFFFF3FFFul; GPIOA->MODER |= 0X00004000ul;      }
//PB输出低  先给电平  再配输出            
#define          PB0_L               { GPIOB->BRR |= 0X00000001ul; GPIOB->MODER &= 0XFFFFFFFCul; GPIOB->MODER |= 0X00000001ul;      }
#define          PB1_L               { GPIOB->BRR |= 0X00000002ul; GPIOB->MODER &= 0XFFFFFFF3ul; GPIOB->MODER |= 0X00000004ul;      } 
#define          PB2_L               { GPIOB->BRR |= 0X00000004ul; GPIOB->MODER &= 0XFFFFFFCFul; GPIOB->MODER |= 0X00000010ul;      }
#define          PB3_L               { GPIOB->BRR |= 0X00000008ul; GPIOB->MODER &= 0XFFFFFF3Ful; GPIOB->MODER |= 0X00000040ul;      }
#define          PB4_L               { GPIOB->BRR |= 0X00000010ul; GPIOB->MODER &= 0XFFFFFCFFul; GPIOB->MODER |= 0X00000100ul;      }
#define          PB5_L               { GPIOB->BRR |= 0X00000020ul; GPIOB->MODER &= 0XFFFFF3FFul; GPIOB->MODER |= 0X00000400ul;      }
#define          PB6_L               { GPIOB->BRR |= 0X00000040ul; GPIOB->MODER &= 0XFFFFCFFFul; GPIOB->MODER |= 0X00001000ul;      }
#define          PB7_L               { GPIOB->BRR |= 0X00000080ul; GPIOB->MODER &= 0XFFFF3FFFul; GPIOB->MODER |= 0X00004000ul;      }
//PC输出低  先给电平  再配输出            
#define          PC0_L               { GPIOC->BRR |= 0X00000001ul; GPIOC->MODER &= 0XFFFFFFFCul; GPIOC->MODER |= 0X00000001ul;      }
#define          PC1_L               { GPIOC->BRR |= 0X00000002ul; GPIOC->MODER &= 0XFFFFFFF3ul; GPIOC->MODER |= 0X00000004ul;      } 
#define          PC2_L               { GPIOC->BRR |= 0X00000004ul; GPIOC->MODER &= 0XFFFFFFCFul; GPIOC->MODER |= 0X00000010ul;      }
#define          PC3_L               { GPIOC->BRR |= 0X00000008ul; GPIOC->MODER &= 0XFFFFFF3Ful; GPIOC->MODER |= 0X00000040ul;      }
#define          PC4_L               { GPIOC->BRR |= 0X00000010ul; GPIOC->MODER &= 0XFFFFFCFFul; GPIOC->MODER |= 0X00000100ul;      }
#define          PC5_L               { GPIOC->BRR |= 0X00000020ul; GPIOC->MODER &= 0XFFFFF3FFul; GPIOC->MODER |= 0X00000400ul;      }
#define          PC6_L               { GPIOC->BRR |= 0X00000040ul; GPIOC->MODER &= 0XFFFFCFFFul; GPIOC->MODER |= 0X00001000ul;      }
#define          PC7_L               { GPIOC->BRR |= 0X00000080ul; GPIOC->MODER &= 0XFFFF3FFFul; GPIOC->MODER |= 0X00004000ul;      }








//PA0  PA1  PA3  PA4  PC0 PC1  PB7

//#define   PIN1_IN         PA0_IN
//#define   PIN2_IN         PA1_IN
//#define   PIN3_IN         PA3_IN
//#define   PIN4_IN         PA4_IN
//#define   PIN5_IN         PC0_IN
//#define   PIN6_IN         PC1_IN
//#define   PIN7_IN         PB7_IN
//   

//  
//#define   PIN1_L          PA0_L
//#define   PIN2_L          PA1_L
//#define   PIN3_L          PA3_L
//#define   PIN4_L          PA4_L
//#define   PIN5_L          PC0_L
//#define   PIN6_L          PC1_L
//#define   PIN7_L          PB7_L
//     
//								 
//#define   PIN1_H         PA0_H
//#define   PIN2_H         PA1_H
//#define   PIN3_H         PA3_H
//#define   PIN4_H         PA4_H
//#define   PIN5_H         PC0_H
//#define   PIN6_H         PC1_H
//#define   PIN7_H         PB7_H




#define   PIN1_IN         { LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_0,LL_GPIO_MODE_INPUT); LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_0); }  
#define   PIN2_IN         { LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_1,LL_GPIO_MODE_INPUT); LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_1); }
#define   PIN3_IN         { LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_3,LL_GPIO_MODE_INPUT); LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_3); }
#define   PIN4_IN         { LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_4,LL_GPIO_MODE_INPUT); LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_4); }
#define   PIN5_IN         { LL_GPIO_SetPinMode(GPIOC,LL_GPIO_PIN_0,LL_GPIO_MODE_INPUT); LL_GPIO_ResetOutputPin(GPIOC,LL_GPIO_PIN_0); }
#define   PIN6_IN         { LL_GPIO_SetPinMode(GPIOC,LL_GPIO_PIN_1,LL_GPIO_MODE_INPUT); LL_GPIO_ResetOutputPin(GPIOC,LL_GPIO_PIN_1); }
#define   PIN7_IN         { LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_7,LL_GPIO_MODE_INPUT); LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_7); }
													

  
#define   PIN1_L         { LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_0);	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_0,LL_GPIO_MODE_OUTPUT); } 
#define   PIN2_L         { LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_1);	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_1,LL_GPIO_MODE_OUTPUT); }
#define   PIN3_L         { LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_3);	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_3,LL_GPIO_MODE_OUTPUT); }
#define   PIN4_L         { LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_4);	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_4,LL_GPIO_MODE_OUTPUT); }
#define   PIN5_L         { LL_GPIO_ResetOutputPin(GPIOC,LL_GPIO_PIN_0);	LL_GPIO_SetPinMode(GPIOC,LL_GPIO_PIN_0,LL_GPIO_MODE_OUTPUT); }
#define   PIN6_L         { LL_GPIO_ResetOutputPin(GPIOC,LL_GPIO_PIN_1);	LL_GPIO_SetPinMode(GPIOC,LL_GPIO_PIN_1,LL_GPIO_MODE_OUTPUT); }
#define   PIN7_L         { LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_7);	LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_7,LL_GPIO_MODE_OUTPUT); }
     
								 
#define   PIN1_H        { LL_GPIO_SetOutputPin(GPIOA,LL_GPIO_PIN_0);	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_0,LL_GPIO_MODE_OUTPUT);  }
#define   PIN2_H        { LL_GPIO_SetOutputPin(GPIOA,LL_GPIO_PIN_1);	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_1,LL_GPIO_MODE_OUTPUT);  }
#define   PIN3_H        { LL_GPIO_SetOutputPin(GPIOA,LL_GPIO_PIN_3);	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_3,LL_GPIO_MODE_OUTPUT);  }
#define   PIN4_H        { LL_GPIO_SetOutputPin(GPIOA,LL_GPIO_PIN_4);	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_4,LL_GPIO_MODE_OUTPUT);  }
#define   PIN5_H        { LL_GPIO_SetOutputPin(GPIOC,LL_GPIO_PIN_0);	LL_GPIO_SetPinMode(GPIOC,LL_GPIO_PIN_0,LL_GPIO_MODE_OUTPUT);  }
#define   PIN6_H        { LL_GPIO_SetOutputPin(GPIOC,LL_GPIO_PIN_1);	LL_GPIO_SetPinMode(GPIOC,LL_GPIO_PIN_1,LL_GPIO_MODE_OUTPUT);  }
#define   PIN7_H        { LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_7);	LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_7,LL_GPIO_MODE_OUTPUT);  }
        
												 




//-------------------------- 运行事件枚举 -----------------------------------------
#if 1
typedef enum{
    Idle=0,         	//空闲
    PowerOnReset, 	//上电
    PowerOff,     	//关机
    PowerOn,      	//开机	
    LowVol,       	//低电
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
    VoutGearSet, //档位
    SelectKeyOut,   //选择按键输出
//    PreHeat,
     SelectMiOut,    //选择咪头输出
	 Dis_Oil=21,
	 Dis_Bat,
	 Dis_Ovp,
	 
}EmRunEvent;
#endif




typedef   struct 
{
	u8    Disp_EN;
	u8    Disp_Dis;   //关闭显示  为了采集时候保证AD值是对的
	u8    Disp_offset;
  u8    sys_led_display_isr_cnt;
  u32   Disp_Data;
//	u32   Disp_Data1;
	
	u8    Disp_Task;
	u8    Disp_Num;
	u16   Disp_Time;
	u16   Disp_Low_Time;
	u16   Disp_High_Time;
	
  u8    Paoma_Time;
  u8    Paoma_Cnt;
  u8    Paoma_Cnt1;
  
	u8    Breath_En;
	u8    Breath_Count;
	u8    Breath_Cycle;
	u8    Breath_Duty;
	u8    Breath_LM;
	u8    Breath_Num;
	
}Dispinfotypedef;




enum
{
  _0Yard = 0,
	_1Yard,
  _Other_Yard,

};

#define      BREATH_CYCLE_MAX_VOLT         70


extern const u16 Horse_Run_List[];
extern const u16 Horse_Run_R_List[];
extern const u8 _t_list_digit_list[];
extern const u8 Out_Gear[];

extern u16 Disp_Num[];

extern Dispinfotypedef    Dispinfo;

void   Set_Disp_Num(u8 num,u16 low,u16 high,u16 data1,u16 data2,u16 data3,u16 data4,u16 data5,u16 data6,u16 data7,u16 data8);
void   Disp_Drive(void);
void   DISP_Deal(void);
void   Set_Yard_Data(u8 low,u8 hig,u8 Yard_mode);
void   Led_Test(u32 Data);
void   Led_Deal(u32 data);
void   Clr_Led(void);
void   Breath_Deal(void);

//全亮
#define     DISP_ALL                  0XFFFFFFFFul

//电量图标  
#define     DISP_BAT_MASK              0x02
//油量图标  
#define     DISP_OIL_MASK              0x08

////百分号
//#define     DISP_PER_MASK              0X20000ul


//上电 
#define    Disp_Power_Rest         { Dispinfo.Disp_Task = PowerOnReset;   Get_Bat_Leve_Map();      Set_Disp_Num(1,0,200,0xff,0xff,0xff,0xff,0xff,0xffff,0xffff,0xffff);}
//低电
#define    Disp_Bat_Low            { Dispinfo.Disp_Task = LowVol;         Get_Bat_Leve_Map();      Set_Disp_Num(10,25,50,Disp_Num[0],Disp_Num[1],Disp_Num[2],Disp_Num[3],Disp_Num[4],0xffff,0xffff,0xffff);}  
//吸烟中低电
#define    Disp_Smok_Bat_Low       { Dispinfo.Disp_Task = LowVol;         Get_Bat_Leve_Map();      Set_Disp_Num(4,25,50,Disp_Num[0],Disp_Num[1],Disp_Num[2],Disp_Num[3],Disp_Num[4],0xffff,0xffff,0xffff);}  

//空载
#define    Disp_No_Heat            { Dispinfo.Disp_Task = HighRes;       Get_Bat_Leve_Map();       Set_Disp_Num(5,25,50,Disp_Num[0],Disp_Num[1],Disp_Num[2],Disp_Num[3],Disp_Num[4],0xffff,0xffff,0xffff); }

//短路
#define    Disp_Short              { Dispinfo.Disp_Task = LowRes;     Get_Bat_Leve_Map();      Set_Disp_Num(3,25,50,Disp_Num[0],Disp_Num[1],Disp_Num[2],Disp_Num[3],Disp_Num[4],0xffff,0xffff,0xffff);}  
//超时
#define    Disp_SmokOver           { Dispinfo.Disp_Task = OverTime;   Get_Bat_Leve_Map();       Set_Disp_Num(3,0,100,Disp_Num[0],Disp_Num[1],Disp_Num[2],Disp_Num[3],Disp_Num[4],0xffff,0xffff,0xffff);}    

//OVP保护
#define    Disp_Ovp_EN             { Dispinfo.Disp_Task = Dis_Ovp;   Get_Bat_Leve_Map();        Set_Disp_Num(1,0,100,0xff,0xff,0xff,0xff,0xff,0xffff,0xffff,0xffff);}    

//USB拔出
#define    Disp_Usb_Out            { Dispinfo.Disp_Task = UsbOut;    Get_Bat_Leve_Map();          Set_Disp_Num(1,0,100,Disp_Num[0],Disp_Num[1],Disp_Num[2],Disp_Num[3],Disp_Num[4],0xffff,0xffff,0xffff);}    

//换挡
#define    Disp_Gear               { Dispinfo.Disp_Task = VoutGearSet;Get_Bat_Leve_Map();         Set_Disp_Num(3,0,100,Disp_Num[0],Disp_Num[1],Disp_Num[2],Disp_Num[3],Disp_Num[4],0xffff,0xffff,0xffff);}   

//吸烟结束
#define    Disp_Smok_Stop          { Dispinfo.Disp_Task = OverStop;  Get_Bat_Leve_Map();          Set_Disp_Num(3,0,100,Disp_Num[0],Disp_Num[1],Disp_Num[2],Disp_Num[3],Disp_Num[4],0xffff,0xffff,0xffff);}   


#endif




