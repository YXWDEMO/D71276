#include "main.h"



ScanInfoTypedef  ScanInfo;



void    Get_Usb_Ad(void)
{
	
   BatVoltage();
   BatInfo.Usb_Ad_Volt = GetADCValue(USB_CHANNEL);
	 
   BatInfo.Usb_Ad_Volt =  (u32)BatInfo.Bat_Volt*BatInfo.Usb_Ad_Volt>>12;
 


}

void   Out_Stop(void)
{

   if(OUTLOAD)
	 {
	       Disp_Smok_Stop;
		     DIGA_IO;
		     CHRG_EN;
		     OutInfo.Out_Mos_Interrup_Ctr_Flag = 0;
         CLR_OUTLOAD;
         MOS_OFF;
		     Clr_Data();
		     Dispinfo.Breath_En = 1;
			   Dispinfo.Breath_Cycle = 0;
  			 Dispinfo.Breath_Count = BREATH_CYCLE_MAX_VOLT;
			   Dispinfo.Breath_LM    = 1;
				 Dispinfo.Breath_Num   = 0;
				 Dispinfo.Disp_Data = BatInfo.Bat_Leve_Data;
		  
	 }

}



void   Power_Rest_Scan(void)
{

  	if(!CHRG_IO)
	  {
	      SysInfo.Power_Rest  = 0;
			  Get_Power_Rest_BatLeve();
	  }
    
		if(!HEAT1_IO)
		{
		  SET_HEATSTART;
			SET_HEATIN;
		}
    
    if(!HEAT2_IO)
		{
		  SET_HEATSTART;
			SET_HEATIN;
		}

   ScanInfo.PortScan_Old  = ScanInfo.PortScan_New;

}

u8 KEY3_IO_Last;

void    Port_Scan(void)
{
   
	  if(SysInfo.Power_Rest){return;}
    
	  if(KEY3_IO)
    {
        if(MIC_IO)
          SET_MICSTART;
        else
          CLR_MICSTART;
    }
    
    if(KEY3_IO_Last != KEY3_IO)
    {
        Out_Stop();
    }
    KEY3_IO_Last = KEY3_IO;
#if 1	
		if(!KEY_IO)
			SET_KEYSTART;
		else
			CLR_KEYSTART;
    
//    if(!KEY1_IO)
//    {
//      Out_Mode =0;
//    }
//    else if(!KEY2_IO)
//    {
//      Out_Mode =1;
//    }
//    else if(!KEY3_IO)
//    {
//      Out_Mode =2;
//    }
#endif
		
	if(!OUTLOAD)
	{
		#if 0	
    if(!HEAT_IO)
		  SET_HEATSTART;
		else
			CLR_HEATSTART;
		#endif
    
		#if 0		
    if(USB_IO)	
     SET_USBSTART;
    else
     CLR_USBSTART;			
#else
    
    Get_Usb_Ad();
//    BatInfo.Usb_Ad_Volt = 800;
		if(BatInfo.Usb_Ad_Volt >= 300)  
//		if(BatInfo.Usb_Ad_Volt >= 0)
     SET_USBSTART;
    else
     CLR_USBSTART;		

#endif
		
		
		
	} 
		
		if(ScanInfo.PortScan_New != ScanInfo.PortScan_Old)
		{
		   if(ScanInfo.PortScan_Cnt < 3){ScanInfo.PortScan_Cnt++;}
		   else
			 {
			  
			    if(MICSTART&&!MICSTART_OLD) 
          {
            SET_OUTSTART;  
          }
					if(!MICSTART&&MICSTART_OLD) 
          {
            CLR_OUTSTART; 
            Out_Stop(); 
          }
					
					#if 1
					if(KEYSTART&&!KEYSTART_OLD) 
          { 
            BatInfo.Bat_Leve = 100;
            ScanInfo.Clr_Key_Num_Cnt = 50;
            BatInfo.Usb_Disp_Full_Cnt = 1000; 
            BatInfo.Usb_Full_Flag = 1;
            
            if(ScanInfo.Key_Num < 10)
            {
              ScanInfo.Key_Num++; 
            }
          }
					if(!KEYSTART&&KEYSTART_OLD) 
          {  
            ScanInfo.Clr_Key_Num_Cnt = 30;
          }
					#endif
					
						
					if(USBSTART&&!USBSTART_OLD) 
          {
            SET_USBIN;
            Get_Bat_Leve_Map();
            BatInfo.Usb_Full_Flag = 0;
            BatInfo.Usb_Led_Twinkle_Cnt = 0;	
            BatInfo.Ovp_En = 0;
					}
					
					if(!USBSTART&&USBSTART_OLD) 
          {
					  CLR_USBIN;
						BatInfo.Usb_Full_Flag = 0;
						BatInfo.Usb_Led_Twinkle_Cnt = 0;		
					  BatInfo.Bat_Charge_Up_Cnt = 0;
					  if(BatInfo.Ovp_En == 0){ 
						if(!OUTLOAD&&!Dispinfo.Disp_Num)
						{
						  Disp_Usb_Out;
						 }
						}
					  BatInfo.Ovp_En = 0;
					}
				   
			    if(HEATSTART&&!HEATSTART_OLD) {SET_HEATIN;}
					if(!HEATSTART&&HEATSTART_OLD) {CLR_HEATIN;}
			     
			 
			   ScanInfo.PortScan_Cnt = 0;
			   ScanInfo.PortScan_Old  = ScanInfo.PortScan_New;
			 }
		}
		else{  ScanInfo.PortScan_Cnt = 0;}
	
#if 1
    if(ScanInfo.Clr_Key_Num_Cnt){ScanInfo.Clr_Key_Num_Cnt--;}
		else
		{
		   if(!KEYSTART_OLD)//松开的情况
			 {
			    if(ScanInfo.Key_Num == 1)
					{
             if(Dispinfo.Disp_EN)
             {
                if(Out_Mode == 0)
                {
                    Out_Mode = 1;  
                    //ScanInfo.Gear_Data_Map = DISP_OUT_GEAR2;
                }
                else if(Out_Mode == 1)
                {
                    Out_Mode = 2;
                }
                else if(Out_Mode == 2)
                {
                    Out_Mode = 0;
                }
             }
					   Disp_Gear;
					}
			 }
       ScanInfo.Key_Num = 0;
		}
#endif
		

}


