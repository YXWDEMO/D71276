#define __SWITCH_DIP_C__
#include "main.h"

// u8	keyChangCnt=0;
// u8	keyHoldCnt=0;		//滤波次数
// u16	keyReleaseCnt=0;		//拨码释放时间
// u8	last_mode=10;
// u8  key=0;
// u8  key1=0;

//  static u16  Get_Switch_Ad(void)
//  {
// // 	u16  switchAdcValue = 0;

// //   switchAdcValue = GetADCValue(SWITCH_CHANNEL);

// // 	return switchAdcValue;
// return 0;
//  }

 void 	Switch_Init(void)
 {
//     key1 = SWITCH_IO;
// 	key = SWITCH1_IO;
	
//   if(!key&&key1)
// 	{
// 		swInfo.swGeras = SW_GERAS_L2;
// 		SysInfo.systemState = SYSTEM_DILE;
// 	}
// 	else if(!key1&&key)
// 	{
// 		swInfo.swGeras = SW_GERAS_L1;
// 		SysInfo.systemState = SYSTEM_DILE;
// 	}
// 	else
// 	{
// 		swInfo.swGeras = SW_GERAS_L0;
// 		SysInfo.systemState = SYSTEM_OFF;
// 	}

// 	swInfo.swGerasOld=swInfo.swGeras;
return;
 }

 void Switch_Scan(void)
 {

// 	if(OUTLOAD)
// 	{
// 		keyHoldCnt = 0;
// 		keyReleaseCnt = 0;
// 		keyChangCnt = 0;
// 		swInfo.swGerasOld=swInfo.swGeras;
// 		return;
// 	}
// 	if(++keyHoldCnt >= 10)
// 	{
// 		keyHoldCnt=0;
// 		key1 = SWITCH_IO;
// 		key = SWITCH1_IO;

// 		if(!key)
// 		{
// 			swInfo.swGeras = SW_GERAS_L2;
// 		}
// 		else if(!key1)
// 		{
// 			swInfo.swGeras = SW_GERAS_L1;
// 		}
// 		else
// 		{
// 			swInfo.swGeras = SW_GERAS_L0;
// 		}

// 		if (swInfo.swGeras!=swInfo.swGerasOld)
// 		{
// 			keyChangCnt++;
// 			if(keyChangCnt >= 3)
// 			{
// 				if(swInfo.swGeras == SW_GERAS_L0)
// 				{
// 					SysInfo.systemState = SYSTEM_OFF;
// 					// SysInfo.Sleep_Time = 30;
// 					// dis_Wakeup();
// 					// Ram_Clear();
// 					Disp_Gear_Off;
// 				}else if(swInfo.swGeras == SW_GERAS_L1)
// 				{
// 					SysInfo.systemState = SYSTEM_DILE;
// 					Dispinfo.Disp_Task = VoutGearSet_L1;
// 					// 显示L1彩灯效果
// 					// SysInfo.Sleep_Time = 30;
// 				    // dis_Wakeup();
// 					// Ram_Clear();
// 					Disp_Gear_L1;
// 				}else if(swInfo.swGeras == SW_GERAS_L2)
// 				{
// 					SysInfo.systemState = SYSTEM_DILE;
// 					Dispinfo.Disp_Task = VoutGearSet_L2;
// 					// 显示L2彩灯效果
// 					// SysInfo.Sleep_Time = 30;
// 					// dis_Wakeup();
// 					// Ram_Clear();
// 					Disp_Gear_L2;
// 				}
// 				// Ram_Clear();
// 				// 	dis_Wakeup();
// 				// 	display_contour(1);
// 				// // 显示换挡
// 				// Disp_Gear;

// 				swInfo.swGerasOld=swInfo.swGeras;
// 			}
// 		}else
// 		{
// 			keyChangCnt = 0;
// 		}
// 	}

 }	

