#include "main.h"



ScanInfoTypedef  ScanInfo;



void    Get_Usb_Ad(void)
{
	
   BatVoltage();
   BatInfo.Usb_Ad_Volt = GetADCValue(USB_CHANNEL);
	 
   BatInfo.Usb_Ad_Volt =  (u32)BatInfo.Bat_Volt*BatInfo.Usb_Ad_Volt>>12;

}
u8 Key_Out_EN;
u16 Key_Long_Time_Cnt;
void   Out_Stop(void)
{

   if(OUTLOAD)
	 {
		MOS_OFF;
		MOS1_OFF;
		ClrShortData();
		OutInfo.Out_Mos_Interrup_Ctr_Flag = 0;
		OutInfo.Out_Mos_Interrup_Ctr_Flag1 = 0;
		CLR_OUTSTART;CLR_OUTLOAD;
		CHRG_ENABLE;
		Smg_Paoma_En_stop=1;
	 }

}

void Power_Reset_Port_Scan(void)
{
    if(MIC_IO)
      SET_MICSTART;

   Get_Usb_Ad();
	
		if(BatInfo.Usb_Ad_Volt >= 350)	
    SET_USBSTART;
   else
    CLR_USBSTART;
	if(!KEY_IO)
			SET_KEYSTART;
		else
			CLR_KEYSTART;
	Key_Out_EN=0;
		ScanInfo.PortScan_Old  = ScanInfo.PortScan_New;
}

void    Port_Scan(void)
{

//	  if(SysInfo.Power_Rest){return;}

    if(MIC_IO)
      SET_MICSTART;
    else
      CLR_MICSTART;

#if 0
    if(USB_IO)
     SET_USBSTART;
    else
     CLR_USBSTART;			
#else
   Get_Usb_Ad();
	
		if(BatInfo.Usb_Ad_Volt >= 350)	
     SET_USBSTART;
    else
     CLR_USBSTART;		

#endif


#ifdef KEY_USE
		if(!KEY_IO)
			SET_KEYSTART;
		else
			CLR_KEYSTART;
#endif

		if(ScanInfo.PortScan_New != ScanInfo.PortScan_Old)
		{
		   if(ScanInfo.PortScan_Cnt < 3){ScanInfo.PortScan_Cnt++;}
		   else
			 {

			    if(MICSTART&&!MICSTART_OLD)
					{
						SysInfo.Power=1;
						SET_OUTSTART;
					}
					if(!MICSTART&&MICSTART_OLD) 
					{
						CLR_OUTSTART;
						Out_Stop(); 
					}
				#ifdef KEY_USE	
					if(KEYSTART&&!KEYSTART_OLD) { ScanInfo.Clr_Key_Num_Cnt = 50;Key_Out_EN = 1;if(ScanInfo.Key_Num < 10){ScanInfo.Key_Num++;}}
					if(!KEYSTART&&KEYSTART_OLD) {  ScanInfo.Clr_Key_Num_Cnt = 30;Key_Out_EN = 0;}
				#endif

					if(USBSTART&&!USBSTART_OLD)
					{
						Smg_Paoma_En_stop=0;
						Dispinfo.Smg_Paoma_Cnt=0;
						sysinit();
						Dispinfo.Disp_Task = Rechg;
						// 开充电电流
						CHRG_ENABLE;
						Ram_Clear();
						SET_USBIN;
					}

					if(!USBSTART&&USBSTART_OLD) 
					{
						sysinit();
						Ram_Clear();
						CLR_USBIN;
					}

			    if(HEATSTART&&!HEATSTART_OLD) {SET_HEATIN;}
					if(!HEATSTART&&HEATSTART_OLD) {CLR_HEATIN;}

			   ScanInfo.PortScan_Cnt = 0;
			   ScanInfo.PortScan_Old  = ScanInfo.PortScan_New;
			 }
		}
		else{  ScanInfo.PortScan_Cnt = 0;}

	#ifdef KEY_USE
	if (Key_Out_EN)
	{
		++Key_Long_Time_Cnt; 
		if(!SysInfo.Power&&Key_Long_Time_Cnt>= 300&&Key_Long_Time_Cnt <=1000)
		{
			// Dispinfo.Disp_Task = VoutGearSet_Ch;
			Disp_Poweron;
			SysInfo.Power=1;
			// Key_Out_EN = 0;
		}
		else if(Key_Long_Time_Cnt >= 3000)
		{
			SysInfo.Power=0;
			// Key_Out_EN = 0;
			LL_EXTI_DisableRisingTrig(KEY_1_Exti);
			LL_EXTI_DisableFallingTrig(KEY_1_Exti);
			SysInfo.Sleep_Time = 0;
		}
	}
	else
	{
		Key_Long_Time_Cnt = 0;
	}
    if(ScanInfo.Clr_Key_Num_Cnt){ScanInfo.Clr_Key_Num_Cnt--;}
		else
		{
			if(ScanInfo.Key_Num == 1)
			{
		//    if(!KEYSTART_OLD)//松开的情况
		// 	 {
				if(swInfo.swGeras == SW_GERAS_L1)
				{
					swInfo.swGeras = SW_GERAS_L2;
				}
				else{
					swInfo.swGeras = SW_GERAS_L1;
				}
				if(!SysInfo.Power)
				{
					Disp_Poweron;
				}
			     
			//  }
			}
		ScanInfo.Key_Num = 0;
		}
	#endif


}


