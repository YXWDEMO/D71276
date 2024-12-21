#include "main.h"


#define  DELAY_COEFFICIENT  1//延迟系数

#define F_CPU 24000000UL // 24 MHz


#define   LED_H          {GPIOA->BSRR |= LL_GPIO_PIN_0; }
#define   LED_L          {GPIOA->BRR |= LL_GPIO_PIN_0;  }            //  LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_3);} 

//一个高 360NS
#define    _0_CODE             {LED_H;LED_L;}
#define    _1_CODE             {LED_H;LED_H;LED_L;}

unsigned char  Smg_Paoma_En;
unsigned char Smg_Paoma_En_stop;
const u8 lights_0[] = {86, 91, 90, 68, 75, 74, 80, 81,105, 125, 139, 135,105, 125, 139, 135,103};
const u8 descending_lights_0[] = {94, 60, 106, 104, 138, 112, 113, 122, 118};
const u8 brightening_lights_0[] = {121, 42, 41, 40, 39, 43, 99, 119, 120, 116, 117, 115};
const u8 lights_25[] = {49, 87, 50, 53, 65, 85, 73, 76, 126, 130, 133, 134, 107, 102, 96, 100, 45, 93};
const u8 lights_50[] = {89, 56, 54, 51, 66, 64, 84, 83, 72, 70, 77, 109, 127, 128, 95, 101, 44, 92};
const u8 lights_75[] = {62, 63, 52, 59, 61, 58, 55, 82, 71, 69, 78, 79, 67, 57, 132, 131, 129, 110, 111, 108};
const u8 lights_0_h[] = {105,106,125,139,130,133,134,135};
const u8 descending_lights_0_h[] = {76,77,78,79,72,86,87,89,91,90,49,54,56,55,63,62,57,58,59,61,64,68,65,66,67}; 
const u8 brightening_lights_0_h[] = {82,83,84,85,81,80,75,74,72,71,70,69,50,51,52,53};
const u8 descending_star_0_h[] = {99,48,42,41,40,39,43,119,60}; 
const u8 brightening_star_0_h[] = {94,122,104,138,112,113,114,115,121,116,117,120,118};
const u8 lights_25_h[] = {125,107};
const u8 lights_50_h[] = {126,127,109};
const u8 lights_75_h[] = {108,110,111,128,131,132};
const u8 lights_all[] = {105,106,125,139,130,133,134,135,76,77,78,79,72,86,87,89,91,90,49,54,56,55,63,62,57,58,59,61,64,68,65,66,67,82,83,84,85,81,80,75,74,72,71,70,69,50,51,52,53,99,48,42,41,40,39,43,119,60,94,122,104,138,112,113,114,115,121,116,117,120,118,125,107,126,127,109,108,110,111,128,131,132};
const u8 descending_star[] = {99,48,42,41,40,39,43,119,60}; 
const u8 brightening_star[] = {94,122,104,138,112,113,114,115,121,116,117,120,118};
void   delay(u16 us)
{
  while(us--);//500ns
 
}
//电量百位
void display_bat_100(unsigned char pwm) {
    write_data(14, pwm);
}
//油量百位
void display_oil_100(unsigned char pwm) {
    write_data(24, pwm);
}
// 电量个位
void display_bat_bit0(unsigned char pwm) {
    write_data(7, pwm);
    write_data(8, pwm);
    write_data(9, pwm);
    write_data(10, pwm);
    write_data(11, pwm);
	write_data(12, pwm);
}

void display_bat_bit1(unsigned char pwm) {
    write_data(8, pwm);
    write_data(9, pwm);
}

void display_bat_bit2(unsigned char pwm) {
    write_data(7, pwm);
    write_data(8, pwm);
    write_data(10, pwm);
    write_data(11, pwm);
    write_data(13, pwm);
}

void display_bat_bit3(unsigned char pwm) {
    write_data(7, pwm);
    write_data(8, pwm);
    write_data(9, pwm);
    write_data(10, pwm);
    write_data(13, pwm);
}

void display_bat_bit4(unsigned char pwm) {
    write_data(8, pwm);
    write_data(9, pwm);
    write_data(12, pwm);
    write_data(13, pwm);
}

void display_bat_bit5(unsigned char pwm) {
	write_data(7, pwm);
	write_data(9, pwm);
	write_data(10, pwm);
	write_data(12, pwm);
	write_data(13, pwm);

}

void display_bat_bit6(unsigned char pwm) {
	write_data(7, pwm);
	write_data(9, pwm);
	write_data(11, pwm);
	write_data(10, pwm);
	write_data(12, pwm);
	write_data(13, pwm);
}

void display_bat_bit7(unsigned char pwm) {
	write_data(7, pwm);
	write_data(8, pwm);
	write_data(9, pwm);
}

void display_bat_bit8(unsigned char pwm) {
	write_data(7, pwm);
	write_data(8, pwm);
	write_data(9, pwm);
	write_data(10, pwm);
	write_data(11, pwm);
	write_data(12, pwm);
	write_data(13, pwm);
}

void display_bat_bit9(unsigned char pwm) {
   write_data(7, pwm);
	write_data(8, pwm);
	write_data(9, pwm);
	write_data(10, pwm);
	write_data(12, pwm);
	write_data(13, pwm);
}
//电量十位
void display_bat_ten0(unsigned char pwm) {
  	write_data(0, pwm);
	write_data(1, pwm);
	write_data(2, pwm);
	write_data(3, pwm);
	write_data(4, pwm);
	write_data(5, pwm);
}

void display_bat_ten1(unsigned char pwm) {
    write_data(1, pwm);
    write_data(2, pwm);
}

void display_bat_ten2(unsigned char pwm) {
    write_data(0, pwm);
    write_data(1, pwm);
	write_data(3, pwm);
    write_data(4, pwm);
	write_data(6, pwm);
}

void display_bat_ten3(unsigned char pwm) {
    write_data(0, pwm);
    write_data(1, pwm);
	write_data(2, pwm);
    write_data(3, pwm);
	write_data(6, pwm);
}

void display_bat_ten4(unsigned char pwm) {
     write_data(1, pwm);
    write_data(2, pwm);
    write_data(5, pwm);
	write_data(6, pwm);
}

void display_bat_ten5(unsigned char pwm) {
    write_data(0, pwm);
    write_data(2, pwm);
	write_data(3, pwm);
    write_data(5, pwm);
	write_data(6, pwm);
}

void display_bat_ten6(unsigned char pwm) {
    write_data(0, pwm);
    write_data(2, pwm);
	write_data(3, pwm);
    write_data(4, pwm);
	write_data(5, pwm);
	write_data(6, pwm);
}

void display_bat_ten7(unsigned char pwm) {
    write_data(0, pwm);
    write_data(1, pwm);
	write_data(2, pwm);
}

void display_bat_ten8(unsigned char pwm) {
    write_data(2, pwm);
	write_data(3, pwm);
    write_data(4, pwm);
	write_data(5, pwm);
	write_data(6, pwm);
	write_data(0, pwm);
	write_data(1, pwm);
}

void display_bat_ten9(unsigned char pwm) {
	write_data(0, pwm);
	write_data(1, pwm);
    write_data(2, pwm);
	write_data(3, pwm);
	write_data(5, pwm);
	write_data(6, pwm);
	
	
}



// 油量个位
void display_oil_bit0(unsigned char pwm) {
    write_data(32, pwm);
	write_data(33, pwm);
	write_data(34, pwm);
	write_data(35, pwm);
	write_data(36, pwm);
	write_data(37, pwm);
}

void display_oil_bit1(unsigned char pwm) {
    write_data(33, pwm);
	write_data(34, pwm);
}

void display_oil_bit2(unsigned char pwm) {
    write_data(32, pwm);
	write_data(33, pwm);
	write_data(35, pwm);
	write_data(36, pwm);
	write_data(37, pwm);
}

void display_oil_bit3(unsigned char pwm) {
    write_data(32, pwm);
	write_data(33, pwm);
	write_data(34, pwm);
	write_data(35, pwm);
	write_data(38, pwm);
}

void display_oil_bit4(unsigned char pwm) {
    write_data(33, pwm);
	write_data(35, pwm);
	write_data(37, pwm);
	write_data(38, pwm);
}

void display_oil_bit5(unsigned char pwm) {
    write_data(32, pwm);
	write_data(34, pwm);
	write_data(35, pwm);
	write_data(37, pwm);
	write_data(38, pwm);
}

void display_oil_bit6(unsigned char pwm) {
    write_data(32, pwm);
	write_data(34, pwm);
	write_data(35, pwm);
	write_data(36, pwm);
	write_data(37, pwm);
	write_data(38, pwm);
}

void display_oil_bit7(unsigned char pwm) {
    write_data(32, pwm);
	write_data(33, pwm);
	write_data(34, pwm);
}

void display_oil_bit8(unsigned char pwm) {
    write_data(32, pwm);
	write_data(33, pwm);
	write_data(34, pwm);
	write_data(35, pwm);
	write_data(36, pwm);
	write_data(37, pwm);
	write_data(38, pwm);
}

void display_oil_bit9(unsigned char pwm) {
    write_data(32, pwm);
	write_data(33, pwm);
	write_data(34, pwm);
	write_data(35, pwm);
	write_data(37, pwm);
	write_data(38, pwm);
}
//油量十位
void display_oil_ten0(unsigned char pwm) {
    write_data(25, pwm);
	write_data(26, pwm);
	write_data(27, pwm);
	write_data(28, pwm);
	write_data(29, pwm);
	write_data(30, pwm);
}

void display_oil_ten1(unsigned char pwm) {
    write_data(26, pwm);
    write_data(27, pwm);
}

void display_oil_ten2(unsigned char pwm) {
    write_data(25, pwm);
	write_data(26, pwm);
	write_data(28, pwm);
	write_data(29, pwm);
	write_data(31, pwm);
}

void display_oil_ten3(unsigned char pwm) {
    write_data(25, pwm);
	write_data(26, pwm);
	write_data(27, pwm);
	write_data(28, pwm);
	write_data(31, pwm);
}

void display_oil_ten4(unsigned char pwm) {
    write_data(26, pwm);
	write_data(27, pwm);
	write_data(30, pwm);
	write_data(31, pwm);
}

void display_oil_ten5(unsigned char pwm) {
    write_data(25, pwm);
	write_data(27, pwm);
	write_data(28, pwm);
	write_data(30, pwm);
	write_data(31, pwm);
}

void display_oil_ten6(unsigned char pwm) {
    write_data(25, pwm);
	write_data(27, pwm);
	write_data(28, pwm);
	write_data(29, pwm);
	write_data(30, pwm);
	write_data(31, pwm);
}

void display_oil_ten7(unsigned char pwm) {
    write_data(25, pwm);
	write_data(26, pwm);
	write_data(27, pwm);
}

void display_oil_ten8(unsigned char pwm) {
	write_data(25, pwm);
	write_data(26, pwm);
	write_data(27, pwm);
	write_data(28, pwm);
	write_data(29, pwm);
	write_data(30, pwm);
	write_data(31, pwm);
}

void display_oil_ten9(unsigned char pwm) {
    write_data(25, pwm);
	write_data(26, pwm);
	write_data(27, pwm);
	write_data(28, pwm);
	write_data(30, pwm);
	write_data(31, pwm);
}

//电量
Dispinfotypedef    Dispinfo;

void (*display_bat_bit[10])(unsigned char) = {
    display_bat_bit0,
    display_bat_bit1,
    display_bat_bit2,
    display_bat_bit3,
    display_bat_bit4,
    display_bat_bit5,
    display_bat_bit6,
    display_bat_bit7,
    display_bat_bit8,
    display_bat_bit9
};

void (*display_bat_ten[10])(unsigned char) = {
    display_bat_ten0,
    display_bat_ten1,
    display_bat_ten2,
    display_bat_ten3,
    display_bat_ten4,
    display_bat_ten5,
    display_bat_ten6,
    display_bat_ten7,
    display_bat_ten8,
    display_bat_ten9
};

void (*display_oil_bit[10])(unsigned char) = {
    display_oil_bit0,
    display_oil_bit1,
    display_oil_bit2,
    display_oil_bit3,
    display_oil_bit4,
    display_oil_bit5,
    display_oil_bit6,
    display_oil_bit7,
    display_oil_bit8,
    display_oil_bit9
};

void (*display_oil_ten[10])(unsigned char) = {
    display_oil_ten0,
    display_oil_ten1,
    display_oil_ten2,
    display_oil_ten3,
    display_oil_ten4,
    display_oil_ten5,
    display_oil_ten6,
    display_oil_ten7,
    display_oil_ten8,
    display_oil_ten9
    
};

void display_bat(unsigned char batleve,unsigned char pwm,unsigned char all) {
	if(Dispinfo.Disp_old_bat!=batleve)
	{
		display_bat_100(0x00);
		display_bat_ten[8](0x00);
		display_bat_bit[8](0x00);
	}
	if(!all)
	{
		if (batleve < 100&&batleve>=10) {
			display_bat_ten[batleve/10](pwm);
			display_bat_bit[batleve%10](pwm);
		}
		else if(batleve==100) 
		{
			display_bat_100(pwm);
			display_bat_ten[0](pwm);
			display_bat_bit[0](pwm);
		}
		else if(batleve<10)
		{
				display_bat_ten[0](0);
				display_bat_bit[batleve%10](pwm);
		}
	}	
	else if(all)
	{
		// write_data(15, pwm);
		display_bat_100(pwm);
		display_bat_ten[8](pwm);
		display_bat_bit[8](pwm);
	}
	Dispinfo.Disp_old_bat = batleve;
}

//油量显示
void display_oil(unsigned char oilleve,unsigned char pwm,unsigned char all) {
	oilleve = ((oilleve+9) / 10) * 10;
	if(Dispinfo.Disp_old_oil !=oilleve)
	{
		// write_data(23, 0x00);	
		display_oil_100(0x00);
        display_oil_ten[8](0x00);
        display_oil_bit[8](0x00);
	}
	if(!all)
	{
		if (oilleve < 100&&oilleve>=10) 
		{
			display_oil_ten[oilleve/10](pwm);
			display_oil_bit[oilleve%10](pwm);
			// write_data(23, pwm);
			}
			else if(oilleve==100) 
			{
			// write_data(23, pwm);
			display_oil_100(pwm);
			display_oil_ten[0](pwm);
			display_oil_bit[0](pwm);
			}
			else if(oilleve<10) {
			{	
				// if(oilleve<=5&&oilleve>0&&SysInfo.Power_Rest == 0&&CHRG_IO)
				// {
				// 	write_data(83, pwm);
				// 	display_oil_L0(0xff);
				// }
				// else if((OUTLOAD&&oilleve==0)||(oilleve==0&&Smg_Paoma_En_stop==1)&&CHRG_IO)
				// {
				// 	display_oil_L0(0xff);
				// }
				// else if(oilleve>5||!CHRG_IO||Dispinfo.Disp_Task == UsbOut)
				// {
				// 	write_data(31, pwm);
				// 	write_data(83, pwm);
				// 	display_oil_bit[oilleve%10](pwm);
				// }
				// else if (SysInfo.Power_Rest == 1)
				// {
					// write_data(23, pwm);
					display_oil_bit[oilleve%10](pwm);
				// }
				
			}
		}
	}
	else if(all)
	{
	   	// write_data(23, pwm);
		display_oil_100(pwm);
        display_oil_ten[8](pwm);
        display_oil_bit[8](pwm);
	}
	Dispinfo.Disp_old_oil = oilleve;
}

//挡位
void display_geras(unsigned char pwm)
{
	if(swInfo.swGeras == SW_GERAS_L1)
	{
		write_data(16, 0xff);
		write_data(21, pwm);
		write_data(17, 0);
		write_data(18, 0);
		write_data(19, 0);
		write_data(20, 0);
		write_data(22, 0);
	}
	else if(swInfo.swGeras == SW_GERAS_L2)
	{
		write_data(16, 0);
		write_data(21, 0xff);
		write_data(17, pwm);
		write_data(18, pwm);
		write_data(19, pwm);
		write_data(20, pwm);
		write_data(22, 0xff);
	}
}

// //电池L0
// void display_bat_L0(unsigned char pwm)
// {
//     write_data(3, pwm);
// 	write_data(4, pwm);
// 	write_data(5, pwm);
// 	display_bat_bit0(pwm);
// }
// //油量L0
// void display_oil_L0(unsigned char pwm)
// {
//     write_data(19, pwm);
// 	write_data(20, pwm);
// 	write_data(21, pwm);
// 	display_oil_bit0(pwm);
// }
//油量符号
void display_Oil_logo(unsigned char pwm)
{
    write_data(23, pwm);
}
//电量符号
void display_Bat_logo(unsigned char pwm)
{
    write_data(15, pwm);
    write_data(15, pwm);
}
//六边形LOGO
void display_logo(unsigned char pwm)
{
	write_data(88, pwm);
}

void   Set_Disp_Num(u8 num,u16 low,u16 high,u32 data1,u32 data2)
{
	
	// 开充电电流
	CHRG_ENABLE;
	Get_Bat_Leve_Map(Bat_Leve);
	OutInfo.Out_Mos_Interrup_Ctr_Flag = 0;
	OutInfo.Out_Mos_Interrup_Ctr_Flag1 = 0;
    CLR_OUTSTART;CLR_OUTLOAD;
	MOS_OFF;MOS1_OFF;
    Dispinfo.Disp_Time = 0;
    Dispinfo.Disp_Num = num;
	Dispinfo.Disp_Low_Time = low;
    Dispinfo.Disp_High_Time = high;
    Dispinfo.Disp_Data  = data1;
    Dispinfo.Disp_Data1 = data2; 	
//   Smg_Paoma_En = 0;
	ClrShortData();

}



void update_pwm_and_write(unsigned int disp_time, unsigned int base_time, unsigned int max_time, unsigned char addr)
{
    // 保证 PWM 最大值是 255，线性插值计算
	if(max_time-disp_time==1)
	{
		disp_time=disp_time+1;
	}
    unsigned char pwm = (unsigned char)((disp_time - base_time) * 255.0 / (max_time - base_time));
    if (pwm > 253) pwm = 255; // 限制最大值，防止越界
    write_data(addr, pwm);
}
void update_pwm_and_write_descending(unsigned int disp_time, unsigned int base_time, unsigned int max_time, unsigned char addr)
{
    // 计算 PWM 从 255 减少到 0 的线性插值
	if(max_time-disp_time==1)
	{
		disp_time=disp_time+1;
	}
    unsigned char pwm = 255 - (unsigned char)((disp_time - base_time) * 255.0 / (max_time - base_time));
    write_data(addr, pwm);                        
}

void low_run(u16 Disp_Time)
{
	u8 is_ram_cleared = 0;  // 静态变量，用于标记是否已经执行过 Ram_Clear()
    // 每次从头开始时，判断 Disp_Time 是否从 0 开始
    if (Disp_Time == 0 && !is_ram_cleared)
    {
        Ram_Clear();  // 只会在 Disp_Time 为 0 且还没有清除过时执行
        is_ram_cleared = 1;  // 设置标志，防止后续重复执行
    }
	if (Disp_Time <25)
	{
		unsigned char a = ((Disp_Time - 0) * 255.0 / (25 - 0));
		display_geras(a);
		//todo 左边灯 0-25		
		//todo 星系链接
		// 左边灯 0-25
		//todo 流星
		for(u8 i = 0;i<sizeof(lights_0) / sizeof(lights_0[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 0, 25, lights_0[i]);
		}
		//todo 呼吸群星
		//todo 开始灭的
		for(u8 i=0;i<sizeof(descending_lights_0) / sizeof(descending_lights_0[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 0, 25, descending_lights_0[i]);
		}
		for(u8 i=0;i<sizeof(brightening_lights_0) / sizeof(brightening_lights_0[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 0, 25, brightening_lights_0[i]);
		}
	}
	else if (Disp_Time >= 25 && Disp_Time < 50)
	{
		unsigned char a =255-((Disp_Time - 25) * 255.0 / (50 - 25));
		display_geras(a);
		// //todo 星系链接
		for(u8 i=0;i<sizeof(lights_25) / sizeof(lights_25[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 25, 50, lights_25[i]);
		}
		//todo 呼吸群星
		//todo 开始灭的
		for(u8 i=0;i<sizeof(descending_lights_0) / sizeof(descending_lights_0[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 25, 50, descending_lights_0[i]);
		}
		for(u8 i=0;i<sizeof(brightening_lights_0) / sizeof(brightening_lights_0[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 25, 50, brightening_lights_0[i]);
		}
	}
	else if (Disp_Time >= 50 && Disp_Time < 75)
	{
		unsigned char a = ((Disp_Time - 50) * 255.0 / (75 - 50));
		display_geras(a);
		//todo 星系链接
		for(u8 i=0;i<sizeof(lights_50) / sizeof(lights_50[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 50, 75, lights_50[i]);
		}
		update_pwm_and_write_descending(Disp_Time, 50, 75, 103);
		
		if(Disp_Time >= 50 && Disp_Time < 62)
		{
			update_pwm_and_write(Disp_Time, 50, 62, 124);
		}
		else if (Disp_Time >= 62 && Disp_Time < 75)
		{
			update_pwm_and_write(Disp_Time, 62, 75, 123);
		}
		//todo 呼吸群星
		//todo 开始灭的
		for(u8 i=0;i<sizeof(descending_lights_0) / sizeof(descending_lights_0[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 50, 75, descending_lights_0[i]);
		}
		for(u8 i=0;i<sizeof(brightening_lights_0) / sizeof(brightening_lights_0[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 50, 75, brightening_lights_0[i]);
		}
	}
	else if (Disp_Time >= 75 && Disp_Time < 100)
	{
		unsigned char a =255-((Disp_Time - 75) * 255.0 / (100 - 75));
		display_geras(a);
		//todo 星系链接
		for(u8 i=0;i<sizeof(lights_75) / sizeof(lights_75[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 75, 100, lights_75[i]);
		}
		//todo 流星
		update_pwm_and_write_descending(Disp_Time, 75, 100, 102);
		update_pwm_and_write_descending(Disp_Time, 75, 100, 96);
		update_pwm_and_write_descending(Disp_Time, 75, 100, 100);
		update_pwm_and_write_descending(Disp_Time, 75, 100, 45);
		update_pwm_and_write_descending(Disp_Time, 75, 100, 93);
		
		if(Disp_Time >= 75 && Disp_Time < 87)
		{
			update_pwm_and_write_descending(Disp_Time, 75, 87, 124);
		}
		else if (Disp_Time >= 87 && Disp_Time < 100)
		{
			update_pwm_and_write_descending(Disp_Time, 87, 100, 123);
		}
		//todo 呼吸群星	
		for(u8 i=0;i<sizeof(descending_lights_0) / sizeof(descending_lights_0[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 75, 100, descending_lights_0[i]);
		}
		for(u8 i=0;i<sizeof(brightening_lights_0) / sizeof(brightening_lights_0[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 75, 100, brightening_lights_0[i]);
		}
	}
	else if (Disp_Time >= 100 && Disp_Time < 125)
	{
		unsigned char a = ((Disp_Time - 100) * 255.0 / (125 - 100));
		display_geras(a);
		//todo 流星
		update_pwm_and_write_descending(Disp_Time, 100, 125, 95);
		update_pwm_and_write_descending(Disp_Time, 100, 125, 101);
		update_pwm_and_write_descending(Disp_Time, 100, 125, 44);
		update_pwm_and_write_descending(Disp_Time, 100, 125, 92);
		update_pwm_and_write(Disp_Time, 100, 125, 47);
		update_pwm_and_write(Disp_Time, 100, 125, 98);
		update_pwm_and_write(Disp_Time, 100, 125, 137);
		//todo 呼吸群星
		//todo 开始灭的
		for(u8 i=0;i<sizeof(descending_lights_0) / sizeof(descending_lights_0[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 100, 125, descending_lights_0[i]);
		}
		for(u8 i=0;i<sizeof(brightening_lights_0) / sizeof(brightening_lights_0[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 100, 125, brightening_lights_0[i]);
		}
	}
	else if (Disp_Time >= 125 && Disp_Time < 150)
	{
		unsigned char a =255-((Disp_Time - 125) * 255.0 / (150 - 125));
		display_geras(a);
		//todo 流星
		update_pwm_and_write(Disp_Time, 125, 150, 46);
		update_pwm_and_write(Disp_Time, 125, 150, 136);
		update_pwm_and_write(Disp_Time, 125, 150, 97);
		//todo 呼吸群星
		for(u8 i=0;i<sizeof(descending_lights_0) / sizeof(descending_lights_0[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 125, 150, descending_lights_0[i]);
		}
		for(u8 i=0;i<sizeof(brightening_lights_0) / sizeof(brightening_lights_0[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 125, 150, brightening_lights_0[i]);
		}
	}
	else if (Disp_Time >= 150 && Disp_Time < 175)
	{
		unsigned char a = ((Disp_Time - 150) * 255.0 / (175 - 150));
		display_geras(a);
		//todo 流星
		update_pwm_and_write_descending(Disp_Time, 150, 175, 47);
		update_pwm_and_write_descending(Disp_Time, 150, 175, 137);
		update_pwm_and_write_descending(Disp_Time, 150, 175, 98);
		//todo 呼吸群星
		//todo 开始灭的
		for(u8 i=0;i<sizeof(descending_lights_0) / sizeof(descending_lights_0[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 150, 175, descending_lights_0[i]);
		}
		for(u8 i=0;i<sizeof(brightening_lights_0) / sizeof(brightening_lights_0[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 150, 175, brightening_lights_0[i]);
		}
	}
	else if (Disp_Time >= 175 && Disp_Time < 200)
	{
		unsigned char a =255-((Disp_Time - 175) * 255.0 / (200 - 175));
		display_geras(a);
		//todo 流星
		update_pwm_and_write_descending(Disp_Time, 175, 200, 46);
		update_pwm_and_write_descending(Disp_Time, 175, 200, 136);
		update_pwm_and_write_descending(Disp_Time, 175, 200, 97);
		//todo 呼吸群星
		for(u8 i=0;i<sizeof(descending_lights_0) / sizeof(descending_lights_0[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 175, 200, descending_lights_0[i]);
		}
		for(u8 i=0;i<sizeof(brightening_lights_0) / sizeof(brightening_lights_0[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 175, 200, brightening_lights_0[i]);
		}
	}
}

void high_run(u16 Disp_Time)
{
	u8 ram_cleared = 0;  
    if (Disp_Time == 0 && !ram_cleared)
    {
        Ram_Clear();  
        ram_cleared = 1; 
    }
	if (Disp_Time <25)
	{
		unsigned char a = ((Disp_Time - 0) * 255.0 / (25 - 0));
		display_geras(a);
		for(u8 i=0;i<sizeof(descending_star_0_h) / sizeof(descending_star_0_h[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 0, 25, descending_star_0_h[i]);
		}
		for(u8 i=0;i<sizeof(brightening_star_0_h) / sizeof(brightening_star_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 0, 25, brightening_star_0_h[i]);
		}
		for(u8 i = 0;i<sizeof(lights_0_h) / sizeof(lights_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 0, 25, lights_0_h[i]);
		}
		for(u8 i=0;i<sizeof(descending_lights_0_h) / sizeof(descending_lights_0_h[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 0, 25, descending_lights_0_h[i]);
		}
		for(u8 i=0;i<sizeof(brightening_lights_0_h) / sizeof(brightening_lights_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 0, 25, brightening_lights_0_h[i]);
		}
	}
	else if (Disp_Time >= 25 && Disp_Time < 50)
	{
		unsigned char a =255-((Disp_Time - 25) * 255.0 / (50 - 25));
		display_geras(a);
		for(u8 i=0;i<sizeof(brightening_star_0_h) / sizeof(brightening_star_0_h[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 25, 50, brightening_star_0_h[i]);
		}
		for(u8 i=0;i<sizeof(descending_star_0_h) / sizeof(descending_star_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 25, 50, descending_star_0_h[i]);
		}
		// //todo 星系链接
		for(u8 i=0;i<sizeof(lights_25_h) / sizeof(lights_25_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 25, 50, lights_25_h[i]);
		}
		for(u8 i=0;i<sizeof(descending_lights_0_h) / sizeof(descending_lights_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 25, 50, descending_lights_0_h[i]);
		}
		for(u8 i=0;i<sizeof(brightening_lights_0_h) / sizeof(brightening_lights_0_h[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 25, 50, brightening_lights_0_h[i]);
		}
	}
	else if (Disp_Time >= 50 && Disp_Time < 75)
	{
		unsigned char a = ((Disp_Time - 50) * 255.0 / (75 - 50));
		display_geras(a);
	for(u8 i=0;i<sizeof(descending_star_0_h) / sizeof(descending_star_0_h[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 50, 75, descending_star_0_h[i]);
		}
		for(u8 i=0;i<sizeof(brightening_star_0_h) / sizeof(brightening_star_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 50, 75, brightening_star_0_h[i]);
		}
		//todo 星系链接
		for(u8 i=0;i<sizeof(lights_50_h) / sizeof(lights_50_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 50, 75, lights_50_h[i]);
		}
		//todo 呼吸群星
		//todo 开始灭的
		for(u8 i=0;i<sizeof(descending_lights_0_h) / sizeof(descending_lights_0_h[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 50, 75, descending_lights_0_h[i]);
		}
		for(u8 i=0;i<sizeof(brightening_lights_0_h) / sizeof(brightening_lights_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 50, 75, brightening_lights_0_h[i]);
		}
	}
	else if (Disp_Time >= 75 && Disp_Time < 100)
	{
		unsigned char a =255-((Disp_Time - 75) * 255.0 / (100 - 75));
		display_geras(a);
		for(u8 i=0;i<sizeof(brightening_star_0_h) / sizeof(brightening_star_0_h[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 75, 100, brightening_star_0_h[i]);
		}
		for(u8 i=0;i<sizeof(descending_star_0_h) / sizeof(descending_star_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 75, 100, descending_star_0_h[i]);
		}
		for(u8 i=0;i<sizeof(lights_75_h) / sizeof(lights_75_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 75, 100, lights_75_h[i]);
		}
		//todo 呼吸群星	
		for(u8 i=0;i<sizeof(descending_lights_0_h) / sizeof(descending_lights_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 75, 100, descending_lights_0_h[i]);
		}
		for(u8 i=0;i<sizeof(brightening_lights_0_h) / sizeof(brightening_lights_0_h[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 75, 100, brightening_lights_0_h[i]);
		}
	}
	else if (Disp_Time >= 100 && Disp_Time < 125)
	{
		unsigned char a = ((Disp_Time - 100) * 255.0 / (125 - 100));
		display_geras(a);
		for(u8 i=0;i<sizeof(descending_star_0_h) / sizeof(descending_star_0_h[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 100, 125, descending_star_0_h[i]);
		}
		for(u8 i=0;i<sizeof(brightening_star_0_h) / sizeof(brightening_star_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 100, 125, brightening_star_0_h[i]);
		}
		//todo 呼吸群星
		//todo 开始灭的
		for(u8 i=0;i<sizeof(descending_lights_0_h) / sizeof(descending_lights_0_h[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 100, 125, descending_lights_0_h[i]);
		}
		for(u8 i=0;i<sizeof(brightening_lights_0_h) / sizeof(brightening_lights_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 100, 125, brightening_lights_0_h[i]);
		}
	}
	else if (Disp_Time >= 125 && Disp_Time < 150)
	{
		unsigned char a =255-((Disp_Time - 125) * 255.0 / (150 - 125));
		display_geras(a);
		for(u8 i=0;i<sizeof(brightening_star_0_h) / sizeof(brightening_star_0_h[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 125, 150, brightening_star_0_h[i]);
		}
		for(u8 i=0;i<sizeof(descending_star_0_h) / sizeof(descending_star_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 125, 150, descending_star_0_h[i]);
		}
		for(u8 i=0;i<sizeof(descending_lights_0_h) / sizeof(descending_lights_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 125, 150, descending_lights_0_h[i]);
		}
		for(u8 i=0;i<sizeof(brightening_lights_0_h) / sizeof(brightening_lights_0_h[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 125, 150, brightening_lights_0_h[i]);
		}
	}
	else if (Disp_Time >= 150 && Disp_Time < 175)
	{
		unsigned char a = ((Disp_Time - 150) * 255.0 / (175 - 150));
		display_geras(a);
		for(u8 i=0;i<sizeof(descending_star_0_h) / sizeof(descending_star_0_h[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 150, 175, descending_star_0_h[i]);
		}
		for(u8 i=0;i<sizeof(brightening_star_0_h) / sizeof(brightening_star_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 150, 175, brightening_star_0_h[i]);
		}
		//todo 呼吸群星
		//todo 开始灭的
		for(u8 i=0;i<sizeof(descending_lights_0_h) / sizeof(descending_lights_0_h[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 150, 175, descending_lights_0_h[i]);
		}
		for(u8 i=0;i<sizeof(brightening_lights_0_h) / sizeof(brightening_lights_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 150, 175, brightening_lights_0_h[i]);
		}
	}
	else if (Disp_Time >= 175 && Disp_Time < 200)
	{
		unsigned char a =255-((Disp_Time - 175) * 255.0 / (200 - 175));
		display_geras(a);
		for(u8 i=0;i<sizeof(brightening_star_0_h) / sizeof(brightening_star_0_h[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 175, 200, brightening_star_0_h[i]);
		}
		for(u8 i=0;i<sizeof(descending_star_0_h) / sizeof(descending_star_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 175, 200, descending_star_0_h[i]);
		}
		//todo 呼吸群星
		for(u8 i=0;i<sizeof(descending_lights_0_h) / sizeof(descending_lights_0_h[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 175, 200, descending_lights_0_h[i]);
		}
		for(u8 i=0;i<sizeof(brightening_lights_0_h) / sizeof(brightening_lights_0_h[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 175, 200, brightening_lights_0_h[i]);
		}
	}
}

void Power_on_run(u16 Disp_Time)
{
	u8 ram_cleared = 0;  
    if (Disp_Time == 0 && !ram_cleared)
    {
        Ram_Clear();  
        ram_cleared = 1; 
    }
	if (Disp_Time <25)
	{
		unsigned char a = ((Disp_Time - 0) * 255.0 / (25 - 0));
		display_oil(Oil_Leve,a,0);
		display_bat(Bat_Leve,a,0);
		display_logo(a);
		display_Oil_logo(a);
		display_Bat_logo(a);
		display_geras(a);
		for(u8 i=0;i<sizeof(lights_all) / sizeof(lights_all[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 0, 25, lights_all[i]);
		}
		if(Disp_Time < 11)
		{
			update_pwm_and_write(Disp_Time, 0, 11, 96);
			update_pwm_and_write(Disp_Time, 0, 11, 98);
			update_pwm_and_write(Disp_Time, 0, 11, 45);
			update_pwm_and_write(Disp_Time, 0, 11, 103);
			update_pwm_and_write(Disp_Time, 0, 11, 122);
		}
		else if (Disp_Time >= 12 && Disp_Time < 25)
		{
			update_pwm_and_write(Disp_Time, 12, 25, 95);
			update_pwm_and_write(Disp_Time, 12, 25, 97);
			update_pwm_and_write(Disp_Time, 12, 25, 44);
			update_pwm_and_write(Disp_Time, 12, 25, 102);
			update_pwm_and_write(Disp_Time, 12, 25, 123);
		}
	}
	else if (Disp_Time >= 25 && Disp_Time < 50)
	{
		for(u8 i=0;i<sizeof(brightening_star) / sizeof(brightening_star[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 25, 50, brightening_star[i]);
		}
		unsigned char a =255-((Disp_Time - 25) * 255.0 / (50 - 25));
		display_geras(a);
		if(Disp_Time >= 25 && Disp_Time < 36)
		{
			update_pwm_and_write(Disp_Time, 25, 36, 137);
			update_pwm_and_write(Disp_Time, 25, 36, 47);

			update_pwm_and_write_descending(Disp_Time, 25, 36, 96);
			update_pwm_and_write_descending(Disp_Time, 25, 36, 98);
			update_pwm_and_write_descending(Disp_Time, 25, 36, 45);
			update_pwm_and_write_descending(Disp_Time, 25, 36, 103);
			update_pwm_and_write_descending(Disp_Time, 25, 36, 122);
		}
		else if (Disp_Time >= 37 && Disp_Time < 50)
		{
			update_pwm_and_write(Disp_Time, 37, 50, 136);
			update_pwm_and_write(Disp_Time, 37, 50, 46);

			update_pwm_and_write_descending(Disp_Time, 37, 50, 95);
			update_pwm_and_write_descending(Disp_Time, 37, 50, 97);
			update_pwm_and_write_descending(Disp_Time, 37, 50, 44);
			update_pwm_and_write_descending(Disp_Time, 37, 50, 102);
			update_pwm_and_write_descending(Disp_Time, 37, 50, 123);
		}
	}
	else if (Disp_Time >= 50 && Disp_Time < 75)
	{
		for(u8 i=0;i<sizeof(brightening_star) / sizeof(brightening_star[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 50, 75, brightening_star[i]);
		}
		for(u8 i=0;i<sizeof(descending_star) / sizeof(descending_star[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 50, 75, descending_star[i]);
		}
		unsigned char a = ((Disp_Time - 50) * 255.0 / (75 - 50));
		display_geras(a);
		if(Disp_Time >= 50 && Disp_Time < 61)
		{
			update_pwm_and_write_descending(Disp_Time, 50, 61, 137);
			update_pwm_and_write_descending(Disp_Time, 50, 61, 47);
		}
		else if (Disp_Time >= 62 && Disp_Time < 75)
		{
			update_pwm_and_write_descending(Disp_Time, 62, 75, 136);
			update_pwm_and_write_descending(Disp_Time, 62, 75, 46);
		}
	
	}
	else if (Disp_Time >= 75 && Disp_Time < 100)
	{
		for(u8 i=0;i<sizeof(brightening_star) / sizeof(brightening_star[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 75, 100, brightening_star[i]);
		}
		for(u8 i=0;i<sizeof(descending_star) / sizeof(descending_star[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 75, 100, descending_star[i]);
		}
		unsigned char a =255-((Disp_Time - 75) * 255.0 / (100 - 75));
		display_geras(a);
		
	}
	else if (Disp_Time >= 100 && Disp_Time < 125)
	{
		for(u8 i=0;i<sizeof(brightening_star) / sizeof(brightening_star[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 100, 125, brightening_star[i]);
		}
		for(u8 i=0;i<sizeof(descending_star) / sizeof(descending_star[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 100, 125, descending_star[i]);
		}
		unsigned char a = ((Disp_Time - 100) * 255.0 / (125 - 100));
		display_geras(a);
		
	}
	else if (Disp_Time >= 125 && Disp_Time < 150)
	{
		for(u8 i=0;i<sizeof(brightening_star) / sizeof(brightening_star[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 125, 150, brightening_star[i]);
		}
		for(u8 i=0;i<sizeof(descending_star) / sizeof(descending_star[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 125, 150, descending_star[i]);
		}
		unsigned char a =255-((Disp_Time - 125) * 255.0 / (150 - 125));
		display_geras(a);
		
	}
	else if (Disp_Time >= 150 && Disp_Time < 175)
	{
		for(u8 i=0;i<sizeof(brightening_star) / sizeof(brightening_star[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 150, 175, brightening_star[i]);
		}
		for(u8 i=0;i<sizeof(descending_star) / sizeof(descending_star[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 150, 175, descending_star[i]);
		}
		unsigned char a = ((Disp_Time - 150) * 255.0 / (175 - 150));
		display_geras(a);
		
	}
	else if (Disp_Time >= 175 && Disp_Time < 200)
	{
		for(u8 i=0;i<sizeof(brightening_star) / sizeof(brightening_star[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 175, 200, brightening_star[i]);
		}
		for(u8 i=0;i<sizeof(descending_star) / sizeof(descending_star[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 175, 200, descending_star[i]);
		}
		unsigned char a =255-((Disp_Time - 175) * 255.0 / (200 - 175));
		display_geras(a);
		
	}
	else if (Disp_Time >= 200 && Disp_Time < 225)
	{
		for(u8 i=0;i<sizeof(brightening_star) / sizeof(brightening_star[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 200, 225, brightening_star[i]);
		}
		for(u8 i=0;i<sizeof(descending_star) / sizeof(descending_star[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 200, 225, descending_star[i]);
		}
		unsigned char a =((Disp_Time - 200) * 255.0 / (225 - 200));
		display_geras(a);
		
	}
	else if (Disp_Time >= 225 && Disp_Time < 250)
	{
		for(u8 i=0;i<sizeof(brightening_star) / sizeof(brightening_star[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 225, 250, brightening_star[i]);
		}
		for(u8 i=0;i<sizeof(descending_star) / sizeof(descending_star[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 225, 250, descending_star[i]);
		}
		unsigned char a =255-((Disp_Time - 225) * 255.0 / (250 - 225));
		display_geras(a);
		
	}
	else if (Disp_Time >= 250 && Disp_Time < 275)
	{
		for(u8 i=0;i<sizeof(brightening_star) / sizeof(brightening_star[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 250, 275, brightening_star[i]);
		}
		for(u8 i=0;i<sizeof(descending_star) / sizeof(descending_star[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 250, 275, descending_star[i]);
		}
		unsigned char a =((Disp_Time - 250) * 255.0 / (275 - 250));
		display_geras(a);
		
	}
	else if (Disp_Time >= 275 && Disp_Time < 300)
	{
		for(u8 i=0;i<sizeof(brightening_star) / sizeof(brightening_star[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 275, 300, brightening_star[i]);
		}
		for(u8 i=0;i<sizeof(descending_star) / sizeof(descending_star[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 275, 300, descending_star[i]);
		}
		unsigned char a =255-((Disp_Time - 275) * 255.0 / (300 - 275));
		display_geras(a);
		
	}
	else if (Disp_Time >= 300 && Disp_Time < 325)
	{
		for(u8 i=0;i<sizeof(brightening_star) / sizeof(brightening_star[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 300, 325, brightening_star[i]);
		}
		for(u8 i=0;i<sizeof(descending_star) / sizeof(descending_star[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 300, 325, descending_star[i]);
		}
		unsigned char a =((Disp_Time - 300) * 255.0 / (325 - 300));
		display_geras(a);
		
	}
	else if (Disp_Time >= 325 && Disp_Time < 350)
	{
		for(u8 i=0;i<sizeof(brightening_star) / sizeof(brightening_star[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 325, 350, brightening_star[i]);
		}
		for(u8 i=0;i<sizeof(descending_star) / sizeof(descending_star[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 325, 350, descending_star[i]);
		}
		unsigned char a =255-((Disp_Time - 325) * 255.0 / (350 - 325));
		display_geras(a);
		
	}
	else if (Disp_Time >= 350 && Disp_Time < 375)
	{
		for(u8 i=0;i<sizeof(brightening_star) / sizeof(brightening_star[0]);i++)
		{
			update_pwm_and_write(Disp_Time, 350, 375, brightening_star[i]);
		}
		for(u8 i=0;i<sizeof(descending_star) / sizeof(descending_star[0]);i++)
		{
			update_pwm_and_write_descending(Disp_Time, 350, 375, descending_star[i]);
		}
		unsigned char a =((Disp_Time - 350) * 255.0 / (375 - 350));
		display_geras(a);
		
	}
	else if (Disp_Time >= 375 && Disp_Time < 400)
	{
		for(u8 i=0;i<sizeof(descending_star) / sizeof(descending_star[0]);i++)
		{
			display_geras(0xff);
			update_pwm_and_write(Disp_Time, 375, 400, descending_star[i]);
		}
	}
}
void   DISP_Deal(void)
{
  if(Dispinfo.Disp_Num)
  {
	   if(++Dispinfo.Disp_Time < Dispinfo.Disp_Low_Time) {Dispinfo.Disp_EN = 0;if(!OUTLOAD){Ram_Clear();}}
		 else if(Dispinfo.Disp_Time > Dispinfo.Disp_High_Time)
		 {
			 Dispinfo.Disp_Time = 0;
			 Dispinfo.Disp_Num--;

			 if(!Dispinfo.Disp_Num)
		   {
				  if(Dispinfo.Disp_Task == PowerOnReset)
			    {
					  SysInfo.Sleep_Time = 5;
						Dispinfo.Disp_Task = Idle;
					}
					else
					{
						Dispinfo.Disp_Task = Idle;
					}
					Dispinfo.Disp_Smok_Error_Flag = 0;
					if(!OUTLOAD){Ram_Clear();}
					Dispinfo.Disp_EN = 0;
			}
			}
			else
			{
			Dispinfo.Disp_EN = 1;
			if(Dispinfo.Disp_Task == PowerOnReset)// 上电
			{
				// Power_on_run(Dispinfo.Disp_Time);
				// high_run(Dispinfo.Disp_Time);
				// low_run(Dispinfo.Disp_Time);
				display();
			}
			else if(Dispinfo.Disp_Task == PowerOn)//低电
			{
				Power_on_run(Dispinfo.Disp_Time);
				if(Dispinfo.Disp_Num==1)
				{
					Dispinfo.Disp_go_ch=1;
				}
			} 
			else if(Dispinfo.Disp_Task == LowVol)//低电
			{
				display_oil(Oil_Leve,0xff,0);
				display_bat(Bat_Leve,0xff,0);
				display_geras(0xff);
				display_Oil_logo(0xff);
				display_Bat_logo(0xff);
				if(Dispinfo.Disp_Num==1)
				{
					Dispinfo.Disp_go_ch=1;
				}
			} 
			else if(Dispinfo.Disp_Task == LowInVol)//低电
			{
				display_oil(Oil_Leve,0xff,0);
				display_bat(Bat_Leve,0xff,0);
				display_geras(0xff);
				display_Oil_logo(0xff);
				display_Bat_logo(0xff);
				if(Dispinfo.Disp_Num==1)
				{
					Dispinfo.Disp_go_ch=1;
				}
			} 
			else if(Dispinfo.Disp_Task == OverTime)//超时
			{
				display_oil(Oil_Leve,0xff,1);
				display_bat(Bat_Leve,0xff,1);
				display_geras(0xff);
				display_Oil_logo(0xff);
				display_Bat_logo(0xff);
				if(Dispinfo.Disp_Num==1)
				{
					Dispinfo.Disp_go_ch=1;
				}
			}
			else if(Dispinfo.Disp_Task == LowRes)//低阻
			{
				display_oil(Oil_Leve,0xff,1);
				display_bat(Bat_Leve,0xff,1);
				display_geras(0xff);
				display_Oil_logo(0xff);
				display_Bat_logo(0xff);
				if(Dispinfo.Disp_Num==1)
				{
					Dispinfo.Disp_go_ch=1;
				}
			}
			else if(Dispinfo.Disp_Task == HighRes)//低阻
			{
				display_oil(Oil_Leve,0xff,1);
				display_bat(Bat_Leve,0xff,1);
				display_geras(0xff);
				display_Oil_logo(0xff);
				display_Bat_logo(0xff);
				if(Dispinfo.Disp_Num==1)
				{
					Dispinfo.Disp_go_ch=1;
				}
			}
		}

	}
	else if(Dispinfo.Disp_Num==0&&Dispinfo.Disp_go_ch==1&&BatInfo.Ovp_En == 0)
	{
		Smg_Paoma_En=1;
		sysinit();
		CHRG_ENABLE;
		Dispinfo.Disp_go_ch=0;
	}	
	else if(OUTLOAD)
	{
	    Dispinfo.Disp_EN = 1;
	}
  else if(USBIN)
	{
	  if(!BatInfo.Ovp_En)
    {
      if(BatInfo.Usb_Ad_Volt >= 1150)
     {
			 
			// 	if(CHRG_IO)
			{
				 if(++BatInfo.OvpOn_Cnt >= 50)
				 {		
					    CHRG_DISABLE;
						BatInfo.OvpOn_Cnt = 0;
						BatInfo.Ovp_En = 1;
						Disp_Ovp_EN;
						Smg_Paoma_En_stop=0;
						Dispinfo.Smg_Paoma_Time_stop=0;
						Smg_Paoma_En = 0;
						Dispinfo.Disp_cl_bat=0;
						Ram_Clear();
						Dis_Ic_OFF;

				 }
				 return;
		 
				}
			}
		}
		else
		{
			 if(BatInfo.Usb_Ad_Volt <= 1000)
			 {
					
					// if(!CHRG_IO)
					{
						CHRG_ENABLE;
						 if(++BatInfo.OvpOff_Cnt >= 50)
						 {
							Smg_Paoma_En = 1;
							Dis_Ic_ON;
							sysinit();
							BatInfo.OvpOff_Cnt = 0;
							BatInfo.Ovp_En = 0;
						 }

					}
					Dispinfo.Disp_EN = 0;	
				
			 }
			 return;
		}

		// 充满后插入USB,立即显示充满
		if(BatInfo.Usb_In_Flag)
		{
			BatVoltage();
			// 插入USB,检测是否给出充满信号或电压高于4.16V
			if(BatInfo.Bat_Volt >= 4160)
			{
				// 
				if(++BatInfo.Usb_Full_Cnt >= 20) // 200ms
				{
					Dis_Ic_ON;
					sysinit();
				    CHRG_DISABLE;
					Ram_Clear();
					Smg_Paoma_En = 0;
					BatInfo.Usb_In_Flag = 0;
					Bat_Leve = 100;
					BatInfo.Usb_Full_Flag = 1;
					BatInfo.Usb_Disp_Long_Cnt = 600;// 充满后60s所有灯熄灭
				}
			}else
			{
				BatInfo.Usb_Full_Cnt = 0;
				BatInfo.Usb_In_Flag = 0;
			}
		}
		 if(!BatInfo.Usb_Full_Flag)
		 {
				 BatVoltage();
				 if((BatInfo.Bat_Volt >= 4164&&Bat_Leve>=99)||Bat_Leve == 100)
				 {
					 if(++BatInfo.Usb_Full_Cnt >= 60) // 3s
					  {
					    // CHRG_DISABLE;
					    Ram_Clear();
					 	Bat_Leve = 100;
						BatInfo.Usb_Full_Flag = 1;
						BatInfo.Usb_Rech_Flag=0;
						Dispinfo.Disp_Task=RechgFull;
						BatInfo.Usb_Disp_Long_Cnt = 600;// 充满后60s所有灯熄灭
					}

				}
			//  Smg_Paoma_En=1;
				Dispinfo.Disp_EN = 1;
				if (++BatInfo.Usb_Led_Twinkle_Cnt < 50)
				{
					if(BatInfo.Usb_Led_Twinkle_Cnt>25)
					{
						display_bat(Bat_Leve,0xff,0);
						display_Bat_logo(0xff);
					}
					else if(BatInfo.Usb_Led_Twinkle_Cnt<=25)
					{
						display_bat(Bat_Leve,0xff,0);
						display_Bat_logo(0);
					}
					
				}
				else
				{
					BatInfo.Usb_Led_Twinkle_Cnt = 0;
				}
			}
		else
		{
				if(BatInfo.Usb_Disp_Long_Cnt)
				{
					BatInfo.Usb_Disp_Long_Cnt--;
					display_oil(Oil_Leve,0xff,0);
					display_bat(Bat_Leve,0xff,0);
					Dispinfo.Disp_EN = 1;
				}
				else
				{   
					Ram_Clear();
					BatInfo.Usb_Rech_Flag=0;
					Smg_Paoma_En = 0;
					Dispinfo.Disp_EN = 0;		
				}
		}

	}

}

void    Smok_Disp_Deal(void)
{	
	if(Smg_Paoma_En)
	{
		if(OUTLOAD)
		{
			sysinit();
			BatVoltage();
			Dispinfo.Smg_Paoma_Time_stop=0;
			if(Dispinfo.Smg_Paoma_Cnt==0)
			{
				
				Ram_Clear();
			}
				if(++Dispinfo.Smg_Paoma_Time>=199)
			{
				Dispinfo.Smg_Paoma_Time=0;
			}
			Dispinfo.Smg_Paoma_Cnt=1;
				if(swInfo.swGeras == SW_GERAS_L1)
				{
					low_run(Dispinfo.Smg_Paoma_Time);
					display_oil(Oil_Leve,0xff,0);
					display_bat(Bat_Leve,0xff,0);
					display_Oil_logo(0xff);
					display_Bat_logo(0xff);
					display_logo(0xff);
					swInfo.swGerasOld=SW_GERAS_L1;
				}
				else if(swInfo.swGeras == SW_GERAS_L2)
				{
					high_run(Dispinfo.Smg_Paoma_Time);
					display_oil(Oil_Leve,0xff,0);
					display_bat(Bat_Leve,0xff,0);
					display_Oil_logo(0xff);
					display_Bat_logo(0xff);
					display_logo(0xff);
					swInfo.swGerasOld=SW_GERAS_L2;
				}
		}
		else if(Smg_Paoma_En_stop==1)
		{
			Dispinfo.Smg_Paoma_Time_stop++;
				if(++Dispinfo.Smg_Paoma_Time>=199)
			{
				Dispinfo.Smg_Paoma_Time=0;
			}
				if(swInfo.swGerasOld == SW_GERAS_L1)
				{
					low_run(Dispinfo.Smg_Paoma_Time);
					display_oil(Oil_Leve,0xff,0);
					display_bat(Bat_Leve,0xff,0);
					display_Oil_logo(0xff);
					display_Bat_logo(0xff);
					display_logo(0xff);
				}
				else if(swInfo.swGerasOld == SW_GERAS_L2)
				{
					high_run(Dispinfo.Smg_Paoma_Time);
					display_oil(Oil_Leve,0xff,0);
					display_bat(Bat_Leve,0xff,0);
					display_Oil_logo(0xff);
					display_Bat_logo(0xff);
					display_logo(0xff);
				}
				if(Dispinfo.Smg_Paoma_Time_stop>200)
			{
				Smg_Paoma_En_stop=0;
				Dispinfo.Smg_Paoma_Time_stop=0;
				Dispinfo.Smg_Paoma_Cnt=0;
				Ram_Clear();
			}
		}
		else 
		{
			
			Dispinfo.Smg_Paoma_Cnt = 0;
			Dispinfo.Smg_Paoma_Time = 0;		 
		}
		
	}
	
}



