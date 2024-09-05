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
void   delay(u16 us)
{
  while(us--);//500ns
 
}
//电量百位
void display_bat_100(unsigned char pwm) {
    write_data(7, pwm);
}
//油量百位
void display_oil_100(unsigned char pwm) {
    write_data(23, pwm);
}
// 电量个位
void display_bat_bit0(unsigned char pwm) {
    write_data(8, pwm);
    write_data(9, pwm);
    write_data(10, pwm);
    write_data(11, pwm);
    write_data(12, pwm);
	write_data(13, pwm);
}

void display_bat_bit1(unsigned char pwm) {
    write_data(9, pwm);
    write_data(10, pwm);
}

void display_bat_bit2(unsigned char pwm) {
    write_data(8, pwm);
    write_data(9, pwm);
    write_data(11, pwm);
    write_data(12, pwm);
    write_data(14, pwm);
}

void display_bat_bit3(unsigned char pwm) {
    write_data(8, pwm);
    write_data(9, pwm);
    write_data(10, pwm);
    write_data(11, pwm);
    write_data(14, pwm);
}

void display_bat_bit4(unsigned char pwm) {
    write_data(9, pwm);
    write_data(10, pwm);
    write_data(13, pwm);
    write_data(14, pwm);
}

void display_bat_bit5(unsigned char pwm) {
	write_data(8, pwm);
	write_data(10, pwm);
	write_data(11, pwm);
	write_data(13, pwm);
	write_data(14, pwm);

}

void display_bat_bit6(unsigned char pwm) {
	write_data(8, pwm);
	write_data(10, pwm);
	write_data(12, pwm);
	write_data(11, pwm);
	write_data(13, pwm);
	write_data(14, pwm);
}

void display_bat_bit7(unsigned char pwm) {
	write_data(8, pwm);
	write_data(9, pwm);
	write_data(10, pwm);
}

void display_bat_bit8(unsigned char pwm) {
	write_data(8, pwm);
	write_data(9, pwm);
	write_data(10, pwm);
	write_data(11, pwm);
	write_data(12, pwm);
	write_data(13, pwm);
	write_data(14, pwm);
}

void display_bat_bit9(unsigned char pwm) {
   write_data(8, pwm);
	write_data(9, pwm);
	write_data(10, pwm);
	write_data(11, pwm);
	write_data(13, pwm);
	write_data(14, pwm);
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
    write_data(24, pwm);
	write_data(25, pwm);
	write_data(26, pwm);
	write_data(27, pwm);
	write_data(28, pwm);
	write_data(29, pwm);
}

void display_oil_bit1(unsigned char pwm) {
    write_data(25, pwm);
	write_data(26, pwm);
}

void display_oil_bit2(unsigned char pwm) {
    write_data(24, pwm);
	write_data(25, pwm);
	write_data(27, pwm);
	write_data(28, pwm);
	write_data(30, pwm);
}

void display_oil_bit3(unsigned char pwm) {
    write_data(24, pwm);
	write_data(25, pwm);
	write_data(27, pwm);
	write_data(26, pwm);
	write_data(30, pwm);
}

void display_oil_bit4(unsigned char pwm) {
    write_data(25, pwm);
	write_data(26, pwm);
	write_data(29, pwm);
	write_data(30, pwm);
}

void display_oil_bit5(unsigned char pwm) {
    write_data(24, pwm);
	write_data(26, pwm);
	write_data(27, pwm);
	write_data(29, pwm);
	write_data(30, pwm);
}

void display_oil_bit6(unsigned char pwm) {
    write_data(24, pwm);
	write_data(26, pwm);
	write_data(27, pwm);
	write_data(29, pwm);
	write_data(28, pwm);
	write_data(30, pwm);
}

void display_oil_bit7(unsigned char pwm) {
    write_data(24, pwm);
	write_data(25, pwm);
	write_data(26, pwm);
}

void display_oil_bit8(unsigned char pwm) {
    write_data(24, pwm);
	write_data(25, pwm);
	write_data(26, pwm);
	write_data(27, pwm);
	write_data(28, pwm);
	write_data(29, pwm);
	write_data(30, pwm);
}

void display_oil_bit9(unsigned char pwm) {
    write_data(24, pwm);
	write_data(25, pwm);
	write_data(26, pwm);
	write_data(27, pwm);
	write_data(29, pwm);
	write_data(30, pwm);
}
//油量十位
void display_oil_ten0(unsigned char pwm) {
    write_data(16, pwm);
	write_data(17, pwm);
	write_data(18, pwm);
	write_data(19, pwm);
	write_data(20, pwm);
	write_data(21, pwm);
}

void display_oil_ten1(unsigned char pwm) {
    write_data(17, pwm);
    write_data(18, pwm);
}

void display_oil_ten2(unsigned char pwm) {
    write_data(16, pwm);
	write_data(17, pwm);
	write_data(19, pwm);
	write_data(20, pwm);
	write_data(22, pwm);
}

void display_oil_ten3(unsigned char pwm) {
    write_data(16, pwm);
	write_data(17, pwm);
	write_data(18, pwm);
	write_data(19, pwm);
	write_data(22, pwm);
}

void display_oil_ten4(unsigned char pwm) {
    write_data(17, pwm);
	write_data(18, pwm);
	write_data(21, pwm);
	write_data(22, pwm);
}

void display_oil_ten5(unsigned char pwm) {
    write_data(16, pwm);
	write_data(18, pwm);
	write_data(19, pwm);
	write_data(21, pwm);
	write_data(22, pwm);
}

void display_oil_ten6(unsigned char pwm) {
     write_data(16, pwm);
	write_data(18, pwm);
	write_data(19, pwm);
	write_data(21, pwm);
	write_data(20, pwm);
	write_data(22, pwm);
}

void display_oil_ten7(unsigned char pwm) {
    write_data(16, pwm);
	write_data(17, pwm);
	write_data(18, pwm);
}

void display_oil_ten8(unsigned char pwm) {
	write_data(16, pwm);
	write_data(17, pwm);
	write_data(18, pwm);
	write_data(19, pwm);
	write_data(21, pwm);
	write_data(20, pwm);
	write_data(22, pwm);
}

void display_oil_ten9(unsigned char pwm) {
    write_data(16, pwm);
	write_data(17, pwm);
	write_data(18, pwm);
	write_data(19, pwm);
	write_data(21, pwm);
	write_data(22, pwm);
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
	if(Dispinfo.Disp_old_bat!=batleve&&batleve>5)
	{
		
		write_data(15, 0x00);
		write_data(32, 0x00);
		write_data(33, 0x00);
		display_bat_100(0x00);
		display_bat_ten[8](0x00);
		display_bat_bit[8](0x00);
	}
	if(Dispinfo.Disp_old_bat!=batleve&&batleve<=5&&batleve>0)
	{
		write_data(15, 0x00);
		write_data(32, 0x00);
		write_data(33, 0x00);
		display_bat_100(0x00);
		display_bat_ten[8](0x00);
		display_bat_bit[8](0x00);
	}
	if(!all)
	{
		// batleve=Bat_Leve;
		if (batleve < 100&&batleve>=10) {
			if(CHRG_IO)
			{
				write_data(15, pwm);
				write_data(32, pwm);
				write_data(33, pwm);
			}
			write_data(15, pwm);
			display_bat_ten[batleve/10](pwm);
			display_bat_bit[batleve%10](pwm);
		}
		else if(batleve==100) 
		{
			if(CHRG_IO)
			{
				write_data(15, pwm);
				write_data(32, pwm);
				write_data(33, pwm);
			}
			display_bat_100(pwm);
			display_bat_ten[0](pwm);
			display_bat_bit[0](pwm);
			write_data(15, pwm);
		}
		else if(batleve<10)
		{
			if(batleve<=5&&batleve>0)
			{
					if(OUTLOAD&&CHRG_IO||Smg_Paoma_En_stop==1||Dispinfo.Disp_Task == UsbOut)
				{
					if(Dispinfo.Disp_cl_bat==0)
					{
						display_bat_100(0);
						display_bat_ten[8](0);
						display_bat_bit[8](0);
						Dispinfo.Disp_cl_bat=1;
					}
					if(Dispinfo.Disp_Task == UsbOut)
					{
						write_data(32, pwm);
						write_data(33, pwm);
					}
					display_bat_L0(0xFF);
				}
					else
				{
					display_bat_ten[0](0);
					display_bat_bit[batleve%10](pwm);
					if(CHRG_IO)
					{
					write_data(32, pwm);
					write_data(33, pwm);
					}
					write_data(15, pwm);
				}
			}
			else
			{
				display_bat_ten[0](0);
				display_bat_bit[batleve%10](pwm);
				if(CHRG_IO)
					{
					write_data(32, pwm);
					write_data(33, pwm);
					}
				write_data(15, pwm);
			}
		}
	}	
	else if(all)
	{
		write_data(15, pwm);
		write_data(32, pwm);
		write_data(33, pwm);
		display_bat_100(pwm);
		display_bat_ten[8](pwm);
		display_bat_bit[8](pwm);
	}
	Dispinfo.Disp_old_bat = batleve;
}
//油量显示
void display_oil(unsigned char oilleve,unsigned char pwm,unsigned char all) {
	if(Dispinfo.Disp_old_oil !=oilleve)
	{
		write_data(31, 0x00);
		write_data(83, 0x00);	
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
			write_data(31, pwm);
			write_data(83, pwm);
			}
			else if(oilleve==100) 
			{
			write_data(31, pwm);
			write_data(83, pwm);
			display_oil_100(pwm);
			display_oil_ten[0](pwm);
			display_oil_bit[0](pwm);
			}
			else if(oilleve<10) {
			{	
				if(oilleve<=5&&oilleve>0&&SysInfo.Power_Rest == 0&&CHRG_IO)
				{
					write_data(83, pwm);
					display_oil_L0(0xff);
				}
				else if((OUTLOAD&&oilleve==0)||(oilleve==0&&Smg_Paoma_En_stop==1)&&CHRG_IO)
				{
					display_oil_L0(0xff);
				}
				else if(oilleve>5||!CHRG_IO||Dispinfo.Disp_Task == UsbOut)
				{
					write_data(31, pwm);
					write_data(83, pwm);
					display_oil_bit[oilleve%10](pwm);
				}
				else if (SysInfo.Power_Rest == 1)
				{
					write_data(31, pwm);
					write_data(83, pwm);
					display_oil_bit[oilleve%10](pwm);
				}
				
			}
		}
	}
	else if(all)
	{
	    write_data(31, pwm);
		write_data(83, pwm);
		display_oil_100(pwm);
        display_oil_ten[8](pwm);
        display_oil_bit[8](pwm);
	}
	Dispinfo.Disp_old_oil = oilleve;
}
//大星星
void display_bigstar(unsigned char eye,unsigned char pwm) {
	
	unsigned char i;
	for(i=72;i<82;i++) {
		write_data(i, pwm);
	}
	write_data(114, eye);
}
//中间内
void display_contour_in(unsigned char pwm)
{
	unsigned char i;
	for(i=34;i<44;i++) {
    write_data(i, pwm);
	}
    
}
//中间外
void display_contour_out(unsigned char pwm)
{
	unsigned char i;
	if(swInfo.swGeras == SW_GERAS_L1)
	{
		for(i=44;i<52;i++) 
		{
		write_data(i, pwm);
		}
		for(i=52;i<61;i++) 
		{
		write_data(i, 0);
		}
	}
	else if(swInfo.swGeras == SW_GERAS_L2)
	{
		for(i=44;i<52;i++) 
		{
		write_data(i, 0);
		}
		for(i=52;i<61;i++) 
		{
		write_data(i, pwm);
		}
	}
	else
	{
		for(i=44;i<61;i++) {
		write_data(i, pwm);
	}
	}
}
//小星星
void display_star(char pwm) {
	write_data(97, pwm);
	write_data(62, pwm);
	write_data(63, pwm);
	write_data(65, pwm);
	write_data(61, pwm);
	unsigned char i,x,y;
	for(i=88;i<91;i++) {
		write_data(i, pwm);
	}
	for (x = 84; x < 86; x++)
	{
		write_data(x, pwm);
	}
	for(y = 64; y <68; y++) 
	{
		write_data(y, pwm);
	}
}
void display_yellow(char pwm)
{
	unsigned char i,x,y;
	for(i=91;i<97;i++) {
		write_data(i, pwm);
	}
	for (x = 98; x < 110; x++)
	{
		write_data(x, pwm);
	}
	for(y = 68; y <72; y++) 
	{
		write_data(y, pwm);
	}
}
//版本号
void display_version()
{
    write_data(2, 0xFF);
    write_data(4, 0xFF);
	write_data(5, 0xFF);
	write_data(6, 0xFF);
	write_data(0, 0xFF);
	write_data(1, 0xFF);
	display_bat_bit0(0xFF);
}
//电池L0
void display_bat_L0(unsigned char pwm)
{
    write_data(3, pwm);
	write_data(4, pwm);
	write_data(5, pwm);
	display_bat_bit0(pwm);
}
//油量L0
void display_oil_L0(unsigned char pwm)
{
    write_data(19, pwm);
	write_data(20, pwm);
	write_data(21, pwm);
	display_oil_bit0(pwm);
}
//油量符号
void display_Oil_logo(unsigned char pwm)
{
    write_data(83, pwm);
}
//电量符号
void display_Bat_logo(unsigned char pwm)
{
    write_data(32, pwm);
    write_data(33, pwm);
}
//海豚
void display_dolphin(unsigned char eye,unsigned char pwm)
{
	unsigned char i,x;
	write_data(87, pwm);
	for(x=115;x<135;x++)
	{
		write_data(x, pwm);
	}
	for(i=110;i<114;i++) 
	{
	write_data(i, pwm);
	}	
	write_data(114, eye);
}


//个位
const u32 _t_list_digit_list_d0[]=
{
	c_bit_7|c_bit_8|c_bit_9|c_bit_10|c_bit_11|c_bit_12|c_bit_12,
	c_bit_11|c_bit_12,
	c_bit_7|c_bit_12|c_bit_13|c_bit_10|c_bit_9,
	c_bit_7|c_bit_12|c_bit_13|c_bit_11|c_bit_10,
	c_bit_8|c_bit_13|c_bit_12|c_bit_11,
	c_bit_7|c_bit_8|c_bit_13|c_bit_11|c_bit_10,
	c_bit_7|c_bit_8|c_bit_9|c_bit_10|c_bit_11|c_bit_13,
	c_bit_7|c_bit_12|c_bit_11,
	c_bit_7|c_bit_8|c_bit_9|c_bit_10|c_bit_11|c_bit_12|c_bit_12|c_bit_13,
	c_bit_7|c_bit_8|c_bit_10|c_bit_11|c_bit_12|c_bit_12|c_bit_13,
	0,
};
//十位
const u16 _t_list_digit_list_d1[]=
{
	c_bit_0|c_bit_1|c_bit_2|c_bit_3|c_bit_4|c_bit_5|c_bit_5,
	c_bit_4|c_bit_5,
	c_bit_0|c_bit_5|c_bit_6|c_bit_3|c_bit_2,
	c_bit_0|c_bit_5|c_bit_6|c_bit_4|c_bit_3,
	c_bit_1|c_bit_6|c_bit_5|c_bit_4,
	c_bit_0|c_bit_1|c_bit_6|c_bit_4|c_bit_3,
	c_bit_0|c_bit_1|c_bit_2|c_bit_3|c_bit_4|c_bit_6,
	c_bit_0|c_bit_5|c_bit_4,
	c_bit_0|c_bit_1|c_bit_2|c_bit_3|c_bit_4|c_bit_5|c_bit_5|c_bit_6,
	c_bit_0|c_bit_1|c_bit_3|c_bit_4|c_bit_5|c_bit_5|c_bit_6,
	0,
};
//油量
//个位
const u32 _t_list_digit_list_d2[]=
{
	c_bit_7|c_bit_8|c_bit_9|c_bit_10|c_bit_11|c_bit_12|c_bit_12,
	c_bit_11|c_bit_12,
	c_bit_7|c_bit_12|c_bit_13|c_bit_10|c_bit_9,
	c_bit_7|c_bit_12|c_bit_13|c_bit_11|c_bit_10,
	c_bit_8|c_bit_13|c_bit_12|c_bit_11,
	c_bit_7|c_bit_8|c_bit_13|c_bit_11|c_bit_10,
	c_bit_7|c_bit_8|c_bit_9|c_bit_10|c_bit_11|c_bit_13,
	c_bit_7|c_bit_12|c_bit_11,
	c_bit_7|c_bit_8|c_bit_9|c_bit_10|c_bit_11|c_bit_12|c_bit_12|c_bit_13,
	c_bit_7|c_bit_8|c_bit_10|c_bit_11|c_bit_12|c_bit_12|c_bit_13,
	0,
};
//十位
const u16 _t_list_digit_list_d3[]=
{
	c_bit_0|c_bit_1|c_bit_2|c_bit_3|c_bit_4|c_bit_5|c_bit_5,
	c_bit_4|c_bit_5,
	c_bit_0|c_bit_5|c_bit_6|c_bit_3|c_bit_2,
	c_bit_0|c_bit_5|c_bit_6|c_bit_4|c_bit_3,
	c_bit_1|c_bit_6|c_bit_5|c_bit_4,
	c_bit_0|c_bit_1|c_bit_6|c_bit_4|c_bit_3,
	c_bit_0|c_bit_1|c_bit_2|c_bit_3|c_bit_4|c_bit_6,
	c_bit_0|c_bit_5|c_bit_4,
	c_bit_0|c_bit_1|c_bit_2|c_bit_3|c_bit_4|c_bit_5|c_bit_5|c_bit_6,
	c_bit_0|c_bit_1|c_bit_3|c_bit_4|c_bit_5|c_bit_5|c_bit_6,
	0,
};

void   Set_Disp_Num(u8 num,u16 low,u16 high,u32 data1,u32 data2)
{
	
	// 开充电电流
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
			//dis_Wakeup();
			if(Dispinfo.Disp_Task == PowerOnReset)// 上电
			{
				if(Dispinfo.Disp_Time == 1)
				{
          Ram_Clear();
          sysinit();
					display();
				}
        // else if(Dispinfo.Disp_Time == 200)
				// {
				// 	Ram_Clear();
				// 	display_version();
				// }else if(Dispinfo.Disp_Time ==300)
				// {
				// 	Ram_Clear();
				// 	display_contour_in(0xFF);
				// 	display_contour_out(0xFF);
				// 	display_bat(Bat_Leve,0xFF,0);
				// 	display_oil(Oil_Leve,0xFF,0);
				// }else if(Dispinfo.Disp_Time >= 400)
				// {
				// 	Ram_Clear();
				// }
			}
			else if(Dispinfo.Disp_Task == LowVol)//低电
			{
				if(Dispinfo.Disp_Time==0)
				{
					sysinit();
					Ram_Clear();
				}
				if (Dispinfo.Disp_Time==1||Dispinfo.Disp_Time % 50 == 0) {
					display_oil(Oil_Leve,0xff,0);
					display_bat(Bat_Leve,0xff,0);	
					display_bigstar(0xff,0xff);
					display_contour_in(0xff);
					display_contour_out(0xff);
					display_star(0xff);
					display_dolphin(0xff,0xff);
					display_yellow(0xff);
				} else if (Dispinfo.Disp_Time % 50 == 25) {
					display_bat(0,0x00,1);
				}
			} 
			else if(Dispinfo.Disp_Task == VoutGearSet_Off)//关机动画
			{
				if(!CHRG_IO||USBSTART&&!USBSTART_OLD)
				{
					return;
				}
				if(Dispinfo.Disp_Time == 0)
				{
					Ram_Clear();
					display_oil(Oil_Leve,0xff,0);
					display_bat(Bat_Leve,0xff,0);	
					display_bigstar(0xff,0xff);
					display_contour_in(0xff);
					display_contour_out(0xff);
					display_star(0xff);
					display_dolphin(0xff,0xff);
					display_yellow(0xff);
				}
				if(Dispinfo.Disp_Time == 1)
				{
					display_oil(Oil_Leve,0xff,0);
					display_bat(Bat_Leve,0xff,0);	
					display_bigstar(0xff,0xff);
					display_contour_in(0xff);
					display_contour_out(0xff);
					display_star(0xff);
					display_dolphin(0xff,0xff);
					display_yellow(0xff);
				}
				else if(Dispinfo.Disp_Time >= 40&&Dispinfo.Disp_Time<=70)
				{
					display_star(0);
					unsigned char i = 255 - (unsigned char)((Dispinfo.Disp_Time - 40) * 255.0 / 30.0);
    				display_yellow(i);
				}
				else if(Dispinfo.Disp_Time >= 10&&Dispinfo.Disp_Time<=40)
				{
					unsigned char i = 255 - (unsigned char)((Dispinfo.Disp_Time - 10) * 255.0 / 30.0);
    				display_star(i);
				}
				else if(Dispinfo.Disp_Time >= 70&&Dispinfo.Disp_Time<=100)
				{
					display_yellow(0);
					unsigned char i = 255 - (unsigned char)((Dispinfo.Disp_Time - 70) * 255.0 / 30.0);
    				display_dolphin(1,i);
					display_bigstar(i,i);
				}
				else if(Dispinfo.Disp_Time >= 100&&Dispinfo.Disp_Time<=150)
				{
					display_dolphin(0,0);
					display_bigstar(0,0);
					unsigned char i = 255 - (unsigned char)((Dispinfo.Disp_Time - 100) * 255.0 / 50.0);
    				display_bat(Bat_Leve,i,0);
					display_oil(Oil_Leve,i,0);
				}
				else if(Dispinfo.Disp_Time >= 150&&Dispinfo.Disp_Time<=200)
				{
					display_bat(Bat_Leve,0,0);
					display_oil(Oil_Leve,0,0);
					unsigned char i = 255 - (unsigned char)((Dispinfo.Disp_Time - 150) * 255.0 / 50.0);
    				display_contour_out(i);
				}
				else if(Dispinfo.Disp_Time >= 200&&Dispinfo.Disp_Time<=250)
				{
					display_contour_out(0);
					unsigned char i = 255 - (unsigned char)((Dispinfo.Disp_Time - 200) * 255.0 / 50.0);
    				display_contour_in(i);
				}
				else if(Dispinfo.Disp_Time ==250)
				{
					Ram_Clear();
				}
			}
			else if(Dispinfo.Disp_Task == OverTime)//超时
			{
				display();
				if(Dispinfo.Disp_Num==1)
				{
					Dispinfo.Disp_go_ch=1;
				}
			}
			else if(Dispinfo.Disp_Task == Dis_Ovp)//OVP
			{
				display();
				if(Dispinfo.Disp_Num==1)
				{
					Dispinfo.Disp_go_ch=1;
				}
			}
			else if(Dispinfo.Disp_Task == LowRes)//低阻
			{
				display();
				if(Dispinfo.Disp_Num==1)
				{
					Dispinfo.Disp_go_ch=1;
				}
			}
			else if(Dispinfo.Disp_Task == UsbOut)//拔出
			{
				display_contour_in(0xff);
				display_contour_out(0xff);
				display_dolphin(0xff,0xff);
				display_star(0xff);
				display_bigstar(0xff,0xff);
				display_oil(Oil_Leve,0xff,0);
				display_bat(Bat_Leve,0xff,0);
			}
			else if(Dispinfo.Disp_Task==VoutGearSet_L1)
			{
				if(!CHRG_IO||USBSTART&&!USBSTART_OLD)
				{
					return;
				}
				if(Dispinfo.Disp_Time==0)
				{
					Ram_Clear();
				}
				if (Dispinfo.Disp_Time % 50 == 0||Dispinfo.Disp_Time==1) {
					display_oil(Oil_Leve,0xff,0);
					display_bat(Bat_Leve,0xff,0);	
					display_bigstar(0xff,0xff);
					display_contour_in(0xff);
					display_contour_out(0xff);
					display_star(0xff);
					display_dolphin(0xff,0xff);
					display_yellow(0xff);
				} else if (Dispinfo.Disp_Time % 50 == 25) {
					display_star(0x00);
				}
			}
			else if(Dispinfo.Disp_Task==VoutGearSet_L2)
			{
				if(!CHRG_IO||USBSTART&&!USBSTART_OLD)
				{
					return;
				}
				if(Dispinfo.Disp_Time==0)
				{
					Ram_Clear();
				}
				if (Dispinfo.Disp_Time % 50 == 0||Dispinfo.Disp_Time==1) {
					display_oil(Oil_Leve,0xff,0);
					display_bat(Bat_Leve,0xff,0);	
					display_bigstar(0xff,0xff);
					display_contour_in(0xff);
					display_contour_out(0xff);
					display_star(0xff);
					display_dolphin(0xff,0xff);
					display_yellow(0xff);
				} else if (Dispinfo.Disp_Time % 50 == 25) {
					display_star(0x00);
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
			if(Dispinfo.Disp_Out_Delay)
			{
					Dispinfo.Disp_Out_Delay--;

				  if(Dispinfo.Disp_Out_Delay >= 1)
					{
//					Dispinfo.Disp_Task = Idle;
						Dispinfo.Disp_Smoke_Effect_Cnt = 0;
						Dispinfo.Disp_Smoke_Effect_Cnt1 = 0;
						Dispinfo.Disp_Smoke_Time = 0;
						Dispinfo.Disp_Smok_Error_Flag = 0;
						Dispinfo.Disp_Ic_Rgb_Digi_Syn_Flag = 0;
						
					}

					return;
			}

			Get_Bat_Leve_Map(Bat_Leve);Get_Oil_Leve_Map(Oil_Leve);
	    Dispinfo.Disp_EN = 1;

		if(USBIN)
			Dispinfo.Disp_Usb_Ic_Rgb_Off_Flag = 1;
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
				 if(BatInfo.Bat_Volt >= 4190)
				 {
					 if(++BatInfo.Usb_Full_Cnt >= 60) // 3s
					  {
					    CHRG_DISABLE;
					    Ram_Clear();
					 	Bat_Leve = 100;
						// display_bat(Bat_Leve,0xff,0);
						BatInfo.Usb_Full_Flag = 1;
						BatInfo.Usb_Rech_Flag=0;
						Dispinfo.Disp_Task=RechgFull;
						BatInfo.Usb_Disp_Long_Cnt = 600;// 充满后60s所有灯熄灭
					 }

				 }
				//  Smg_Paoma_En=1;
				 Dispinfo.Disp_EN = 1;

		 }
		 else
		 {
				if(BatInfo.Usb_Disp_Long_Cnt)
				{
					BatInfo.Usb_Disp_Long_Cnt--;
					display_contour_in(0xff);
					display_contour_out(0xff);
					display_dolphin(0xff,0xff);
					display_star(0xff);
					display_bigstar(0xff,0xff);
					display_yellow(0xff);
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
			BatVoltage();
			CHRG_DISABLE;
			Dispinfo.Smg_Paoma_Time_stop=0;
			if(Dispinfo.Smg_Paoma_Cnt==0)
			{
				sysinit();
				Ram_Clear();
			}
			Dispinfo.Smg_Paoma_Cnt=1;
			display_bat(Bat_Leve,0xff,0);
			display_oil(Oil_Leve,0xff,0);
			display_contour_out(0xff);
			if(++Dispinfo.Smg_Paoma_Time >=34)
				{
					Dispinfo.Smg_Paoma_Time = 0;
				}
				if((Dispinfo.Smg_Paoma_Time==0||Dispinfo.Smg_Paoma_Time==16))
				{
					if (Dispinfo.Disp_Smoke_Effect_Cnt1%2==0) {
						if (Bat_Leve<=5)
						{
							display_Bat_logo(0xff);
							write_data(15, 0);
						}
						if(Oil_Leve==0)
						{
							write_data(31, 0);
							display_Oil_logo(0xff);
						}
					}
					if (Dispinfo.Disp_Smoke_Effect_Cnt1%2==1) {
						if (Bat_Leve<=5)
						{
							display_Bat_logo(0x00);
							write_data(15, 0);
						}
						if(Oil_Leve==0)
						{
							display_Oil_logo(0x00);
							write_data(31, 0);
						}
					}
					Dispinfo.Disp_Smoke_Effect_Cnt1 = (Dispinfo.Disp_Smoke_Effect_Cnt1 + 1) % 2;
				}
				if(Dispinfo.Smg_Paoma_Time==0)
				{
					
					if (Dispinfo.Disp_Smoke_Effect_Cnt%2==0) {
						display_contour_in(0xff);
						
					}
					if (Dispinfo.Disp_Smoke_Effect_Cnt%2==1) {
						display_contour_in(0x00);
					}
					
					Dispinfo.Disp_Smoke_Effect_Cnt = (Dispinfo.Disp_Smoke_Effect_Cnt + 1) % 2;
				}
				if(Dispinfo.Smg_Paoma_Time%1==0) {
				Dispinfo.Disp_pwm_star++;
				}
				if(Dispinfo.Disp_pwm_star<25)
				{
					unsigned char u = (unsigned char)((Dispinfo.Disp_pwm_star) * 255.0 / 25);
					unsigned char d = 255-(unsigned char)((Dispinfo.Disp_pwm_star) * 255.0 / 25);
					display_yellow(u);
					display_star(d);
					display_bigstar(u, u);
				}
				else if(Dispinfo.Disp_pwm_star>=25&&Dispinfo.Disp_pwm_star<=50)
				{
					unsigned char u = (unsigned char)((Dispinfo.Disp_pwm_star-25) * 255.0 / 25);
					unsigned char d = 255-(unsigned char)((Dispinfo.Disp_pwm_star-25) * 255.0 / 25);
					display_yellow(d);
					display_star(u);
					display_bigstar(d, d);
					
				}
				else if(Dispinfo.Disp_pwm_star>50)
				{
					Dispinfo.Disp_pwm_star=0;
				}
				if(Dispinfo.Smg_Paoma_Time%5==0) {
					Dispinfo.Disp_pwm++;
				}
				if(Dispinfo.Disp_pwm<25)
				{
					unsigned char i = (unsigned char)((Dispinfo.Disp_pwm) * 255.0 / 25);
					display_dolphin(i, 0xff);
				}
				else if(Dispinfo.Disp_pwm>=25&&Dispinfo.Disp_pwm<=50)
				{
					unsigned char i = 255-(unsigned char)((Dispinfo.Disp_pwm-25) * 255.0 / 25);
					display_dolphin(i, 0xff);
				}
				else if(Dispinfo.Disp_pwm>50)
				{
					display_dolphin(0, 0xff);
					Dispinfo.Disp_pwm=0;
				}
				
		}
		else if(Smg_Paoma_En_stop==1)
		{
				if(!CHRG_IO)
				{
					sysinit();
					Smg_Paoma_En_stop=0;
				}
				// BatVoltage();
				CHRG_ENABLE;
				display_bat(Bat_Leve,0xff,0);
				display_oil(Oil_Leve,0xff,0);
				display_contour_out(0xff);
				if(++Dispinfo.Smg_Paoma_Time >=34)
				{
					Dispinfo.Smg_Paoma_Time = 0;
				}
				if((Dispinfo.Smg_Paoma_Time==0||Dispinfo.Smg_Paoma_Time==16))
				{
					if (Dispinfo.Disp_Smoke_Effect_Cnt1%2==0) {
						if (Bat_Leve<=5)
						{
							display_Bat_logo(0xff);
							write_data(15, 0);
						}
						if(Oil_Leve==0)
						{
							write_data(31, 0);
							display_Oil_logo(0xff);
						}
					}
					if (Dispinfo.Disp_Smoke_Effect_Cnt1%2==1) {
						if (Bat_Leve<=5)
						{
							display_Bat_logo(0x00);
							write_data(15, 0);
						}
						if(Oil_Leve==0)
						{
							write_data(31, 0);
							display_Oil_logo(0x00);
						}
					}
					Dispinfo.Disp_Smoke_Effect_Cnt1 = (Dispinfo.Disp_Smoke_Effect_Cnt1 + 1) % 2;
				}
				if(Dispinfo.Smg_Paoma_Time==0)
				{
					
					if (Dispinfo.Disp_Smoke_Effect_Cnt%2==0) {
						display_contour_in(0xff);
						
					}
					if (Dispinfo.Disp_Smoke_Effect_Cnt%2==1) {
						display_contour_in(0x00);
					}
					
					Dispinfo.Disp_Smoke_Effect_Cnt = (Dispinfo.Disp_Smoke_Effect_Cnt + 1) % 2;
				}
				if(Dispinfo.Smg_Paoma_Time%1==0) {
				Dispinfo.Disp_pwm_star++;
				}
				if(Dispinfo.Disp_pwm_star<25)
				{
					unsigned char u = (unsigned char)((Dispinfo.Disp_pwm_star) * 255.0 / 25);
					unsigned char d = 255-(unsigned char)((Dispinfo.Disp_pwm_star) * 255.0 / 25);
					display_yellow(u);
					display_star(d);
					display_bigstar(u, u);
				}
				else if(Dispinfo.Disp_pwm_star>=25&&Dispinfo.Disp_pwm_star<=50)
				{
					unsigned char u = (unsigned char)((Dispinfo.Disp_pwm_star-25) * 255.0 / 25);
					unsigned char d = 255-(unsigned char)((Dispinfo.Disp_pwm_star-25) * 255.0 / 25);
					display_yellow(d);
					display_star(u);
					display_bigstar(d, d);
					
				}
				else if(Dispinfo.Disp_pwm_star>50)
				{
					Dispinfo.Disp_pwm_star=0;
				}
				if(Dispinfo.Smg_Paoma_Time%5==0) {
					Dispinfo.Disp_pwm++;
				}
				if(Dispinfo.Disp_pwm<25)
				{
					unsigned char i = (unsigned char)((Dispinfo.Disp_pwm) * 255.0 / 25);
					display_dolphin(i, 0xff);
				}
				else if(Dispinfo.Disp_pwm>=25&&Dispinfo.Disp_pwm<=50)
				{
					unsigned char i = 255-(unsigned char)((Dispinfo.Disp_pwm-25) * 255.0 / 25);
					display_dolphin(i, 0xff);
				}
				else if(Dispinfo.Disp_pwm>50)
				{
					display_dolphin(0, 0xff);
					Dispinfo.Disp_pwm=0;
				}
				Dispinfo.Smg_Paoma_Time_stop++;
				if (Dispinfo.Smg_Paoma_Time_stop==380||swInfo.swGeras == SW_GERAS_L0||Dispinfo.Disp_Task==VoutGearSet_L2||Dispinfo.Disp_Task==VoutGearSet_L1)
				{
				Ram_Clear();
				Smg_Paoma_En_stop=0;
				Dispinfo.Smg_Paoma_Time_stop=0;
				Smg_Paoma_En = 0;
				Dispinfo.Disp_cl_bat=0;
				}
				
			}
			else if(!CHRG_IO||BatInfo.Usb_Full_Flag && (BatInfo.Bat_Volt < 4110))
			{
				CHRG_ENABLE;
				Dispinfo.Smg_Paoma_Time_stop=0;
				if(Dispinfo.Smg_Paoma_Cnt==0)
				{
					sysinit();
					Ram_Clear();
				}
				Dispinfo.Smg_Paoma_Cnt=1;
				if(Dispinfo.Smg_Go_Ch==1)
				{
					display_bat(Bat_Leve,0x00,1);
					display_oil(Oil_Leve,0x00,1);
					Dispinfo.Smg_Go_Ch=0;
				}
				display_bat(Bat_Leve,0xff,0);
				display_oil(Oil_Leve,0xff,0);
				display_contour_out(0xff);
				if(++Dispinfo.Smg_Paoma_Time >=34)
				{
					Dispinfo.Smg_Paoma_Time = 0;
				}
				if(Dispinfo.Smg_Paoma_Time==0)
				{
					
					if (Dispinfo.Disp_Smoke_Effect_Cnt%2==0) {
						display_contour_in(0xff);
						display_Bat_logo(0xff);
						display_Oil_logo(0xff);

					}
					if (Dispinfo.Disp_Smoke_Effect_Cnt%2==1) {
						display_contour_in(0x00);
						display_Bat_logo(0x00);
					}
					Dispinfo.Disp_Smoke_Effect_Cnt = (Dispinfo.Disp_Smoke_Effect_Cnt + 1) % 2;
				}
					if(Dispinfo.Smg_Paoma_Time%1==0) {
					Dispinfo.Disp_pwm_star++;
					}
					if(Dispinfo.Disp_pwm_star<25)
					{
						unsigned char u = (unsigned char)((Dispinfo.Disp_pwm_star) * 255.0 / 25);
						unsigned char d = 255-(unsigned char)((Dispinfo.Disp_pwm_star) * 255.0 / 25);
						display_yellow(u);
						display_star(d);
						display_bigstar(u, u);
					}
					else if(Dispinfo.Disp_pwm_star>=25&&Dispinfo.Disp_pwm_star<=50)
					{
						unsigned char u = (unsigned char)((Dispinfo.Disp_pwm_star-25) * 255.0 / 25);
						unsigned char d = 255-(unsigned char)((Dispinfo.Disp_pwm_star-25) * 255.0 / 25);
						display_yellow(d);
						display_star(u);
						display_bigstar(d, d);
						
					}
					else if(Dispinfo.Disp_pwm_star>50)
					{
						Dispinfo.Disp_pwm_star=0;
					}
					if(Dispinfo.Smg_Paoma_Time%5==0) {
						Dispinfo.Disp_pwm++;
					}
					if(Dispinfo.Disp_pwm<25)
					{
						unsigned char i = (unsigned char)((Dispinfo.Disp_pwm) * 255.0 / 25);
						display_dolphin(i, 0xff);
					}
					else if(Dispinfo.Disp_pwm>=25&&Dispinfo.Disp_pwm<=50)
					{
						unsigned char i = 255-(unsigned char)((Dispinfo.Disp_pwm-25) * 255.0 / 25);
						display_dolphin(i, 0xff);
					}
					else if(Dispinfo.Disp_pwm>50)
					{
						display_dolphin(0, 0xff);
						Dispinfo.Disp_pwm=0;
					}
				}
		else 
		{
			// Smg_Paoma_En = 0;
			Dispinfo.Disp_cl_bat=0;
			Dispinfo.Disp_pwm=0;
			Dispinfo.Disp_pwm_star=0;
			Dispinfo.Smg_Paoma_Cnt = 0;
			Dispinfo.Smg_Paoma_Time = 0;		 
		}
		
	}
	
}



