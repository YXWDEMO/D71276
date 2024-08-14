#ifndef _SYS_H
#define _SYS_H



typedef   struct
{

  u8   Sleep_Time;
	u8   Time_100us;
  u8   Time_1200us;
  u8   Time_500us;
  u8   Time_1ms;
	u8   Time_10ms;
	u8   Time_100ms;
	
	u8   _1ms_Flag;
	u8   _10ms_Flag;
	u8   _100ms_Flag;

  u8   Power_Rest;


}SysInfoTypedef;




extern SysInfoTypedef  SysInfo;
















#endif


