#ifndef _TYPEDEF_H
#define _TYPEDEF_H




#define    MOS1_PORT              GPIOB
#define    MOS1_PIN               LL_GPIO_PIN_2

#define    MOS2_PORT              GPIOB
#define    MOS2_PIN               LL_GPIO_PIN_3

#define    HEAT1_PORT             GPIOB
#define    HEAT1_PIN              LL_GPIO_PIN_1

#define    HEAT2_PORT             GPIOB
#define    HEAT2_PIN              LL_GPIO_PIN_0


#define   ATUO_IO               { LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_0,LL_GPIO_MODE_ANALOG); LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_1,LL_GPIO_MODE_ANALOG);__NOP();__NOP();__NOP(); }
#define   DIGA_IO               { LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_0,LL_GPIO_MODE_INPUT);  LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_1,LL_GPIO_MODE_INPUT);__NOP();__NOP();__NOP();}

//#define   DIGA_IO               {  LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_0, LL_GPIO_MODE_INPUT); __NOP();__NOP();__NOP();}

#define    KEY_PORT               GPIOB
#define    KEY_PIN                LL_GPIO_PIN_4

#define    KEY1_PORT              GPIOA
#define    KEY1_PIN               LL_GPIO_PIN_0

#define    KEY2_PORT              GPIOA
#define    KEY2_PIN               LL_GPIO_PIN_1

#define    KEY3_PORT              GPIOA
#define    KEY3_PIN               LL_GPIO_PIN_3

#define    USB_PORT               GPIOC
#define    USB_PIN                LL_GPIO_PIN_0

#define    CHRG_PORT              GPIOC
#define    CHRG_PIN               LL_GPIO_PIN_1

#define    MIC_PORT               GPIOA
#define    MIC_PIN                LL_GPIO_PIN_7

//充电使能控制脚位
#define    CHRGEN_PORT            GPIOB
#define    CHRGEN_PIN             LL_GPIO_PIN_7

//使能充电  
#define   CHRG_EN                 PB7_IN   
//关闭充电
#define   CHRG_DIS                PB7_H   


#define    SDA_PORT         GPIOA
#define    SDA_PIN          LL_GPIO_PIN_4

#define    SCL_PORT         GPIOA
#define    SCL_PIN          LL_GPIO_PIN_5


#define   SDA_OUT              //{ LL_GPIO_SetPinMode(SDA_PORT,SDA_PIN,LL_GPIO_MODE_OUTPUT); }
#define   SDA_IN               //{ LL_GPIO_SetPinMode(SDA_PORT,SDA_PIN,LL_GPIO_MODE_INPUT) ; }

#define   SDA_1                { LL_GPIO_SetOutputPin(SDA_PORT,SDA_PIN);  }
#define   SDA_0                { LL_GPIO_ResetOutputPin(SDA_PORT,SDA_PIN);}

#define   SCL_1                { LL_GPIO_SetOutputPin(SCL_PORT,SCL_PIN);  }
#define   SCL_0                { LL_GPIO_ResetOutputPin(SCL_PORT,SCL_PIN);}

#define   SDA_Value            LL_GPIO_IsInputPinSet(SDA_PORT,SDA_PIN)

#define    BAT_CHANNEL         9
#define    OUT1_CHANNEL        0
#define    OUT2_CHANNEL        7
#define    USB_CHANNEL         5

#define    HEAT1_IO            LL_GPIO_IsInputPinSet(HEAT1_PORT,HEAT1_PIN)
#define    HEAT2_IO            LL_GPIO_IsInputPinSet(HEAT2_PORT,HEAT2_PIN)


#define    KEY_IO              LL_GPIO_IsInputPinSet(KEY_PORT,KEY_PIN)
#define    KEY1_IO             LL_GPIO_IsInputPinSet(KEY1_PORT,KEY1_PIN)
#define    KEY2_IO             LL_GPIO_IsInputPinSet(KEY2_PORT,KEY2_PIN)
#define    KEY3_IO             LL_GPIO_IsInputPinSet(KEY3_PORT,KEY3_PIN)


#define    MIC_IO              LL_GPIO_IsInputPinSet(MIC_PORT,MIC_PIN)
#define    CHRG_IO             LL_GPIO_IsInputPinSet(CHRG_PORT,CHRG_PIN)
#define    USB_IO              LL_GPIO_IsInputPinSet(USB_PORT,USB_PIN)

#define   MOS_ON               {LL_GPIO_ResetOutputPin(MOS1_PORT,MOS1_PIN);  LL_GPIO_ResetOutputPin(MOS2_PORT,MOS2_PIN); }
#define   MOS_OFF              {LL_GPIO_SetOutputPin(MOS1_PORT,MOS1_PIN);    LL_GPIO_SetOutputPin(MOS2_PORT,MOS2_PIN);   }

#define   MOS1_ON              {LL_GPIO_ResetOutputPin(MOS1_PORT,MOS1_PIN);  }
#define   MOS1_OFF             {LL_GPIO_SetOutputPin(MOS1_PORT,MOS1_PIN);    }

#define   MOS2_ON              {LL_GPIO_ResetOutputPin(MOS2_PORT,MOS2_PIN);  }
#define   MOS2_OFF             {LL_GPIO_SetOutputPin(MOS2_PORT,MOS2_PIN);    }


//#define   MOS_ON              { __NOP();__NOP();__NOP();  }
//#define   MOS_OFF             { __NOP();__NOP();__NOP();    }

void   Sys_Init(void);
#endif

