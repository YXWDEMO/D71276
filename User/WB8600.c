#include "main.h"


//亮度
uint8_t loop1_10reg[8]={0x00,0x07,0x06,0x05,0x04,0x03,0x02,0x01};
uint8_t loop2_10reg[8]={0x01,0x00,0x07,0x06,0x05,0x04,0x03,0x02};
uint8_t loop3_10reg[8]={0x02,0x01,0x00,0x07,0x06,0x05,0x04,0x03};
uint8_t loop4_10reg[8]={0x03,0x02,0x01,0x00,0x07,0x06,0x05,0x04};
uint8_t loop5_10reg[8]={0x04,0x03,0x02,0x01,0x00,0x07,0x06,0x05};
uint8_t loop6_10reg[8]={0x05,0x04,0x03,0x02,0x01,0x00,0x07,0x06};
uint8_t loop7_10reg[8]={0x06,0x05,0x04,0x03,0x02,0x01,0x00,0x07};
uint8_t loop8_10reg[8]={0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00};

//显示使能
uint8_t loop1_12reg[8]={0x03,0x00,0x03,0x03,0x03,0x03,0x03,0x03};
uint8_t loop2_12reg[8]={0x03,0x03,0x00,0x03,0x03,0x03,0x03,0x03};
uint8_t loop3_12reg[8]={0x03,0x03,0x03,0x00,0x03,0x03,0x03,0x03};
uint8_t loop4_12reg[8]={0x03,0x03,0x03,0x03,0x00,0x03,0x03,0x03};
uint8_t loop5_12reg[8]={0x03,0x03,0x03,0x03,0x03,0x00,0x03,0x03};
uint8_t loop6_12reg[8]={0x03,0x03,0x03,0x03,0x03,0x03,0x00,0x03};
uint8_t loop7_12reg[8]={0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x00};
uint8_t loop8_12reg[8]={0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x03};


uint8_t Led_Show[16];

uint8_t  Led_Num[4];
uint8_t  Led_Icon;
uint16_t Led_L_Icon;
uint16_t Led_M_Icon;
uint16_t Led_R_Icon;

void _delay_us(uint16_t us)
{
  uint16_t i,j;
	for(j=0;j<us;j++)
	{
		for(i=0;i<1;i++)
		{
		  __NOP();
		}
	}

}

//程序步骤：
void Step1_R(void)		// 写00~05寄存器是连续写，单独函数：void WB8600M_Write_6
{
	uint8_t i;
	i=0;

	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop1_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x01,0x00,0x00,0x01,0x00,0x00);
	WB8600M_Write_One(0x12,loop1_12reg[i]);
	_delay_us(delay_WB8600M_1);
	//这部分程序：点亮第1个灯，电流对应上面数组10寄存器的第1个值
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop2_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x02,0x00,0x00,0x02,0x00,0x00);			
	WB8600M_Write_One(0x12,loop2_12reg[i]);
	_delay_us(delay_WB8600M_1);
	//这部分程序：点亮第2个灯，电流对应上面数组10寄存器的第2个值
	
  //下面的程序以此类推，点亮第3~第8个灯

	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop3_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x04,0x00,0x00,0x04,0x00,0x00);			// GRID1，SEG3，数据要改
	WB8600M_Write_One(0x12,loop3_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop4_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x08,0x00,0x00,0x08,0x00,0x00);			// GRID1，SEG4，数据要改
	WB8600M_Write_One(0x12,loop4_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop5_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x10,0x00,0x00,0x10,0x00,0x00);			// GRID1，SEG5，数据要改
	WB8600M_Write_One(0x12,loop5_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop6_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x20,0x00,0x00,0x20,0x00,0x00);			// GRID1，SEG6，数据要改
	WB8600M_Write_One(0x12,loop6_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop7_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x40,0x00,0x00,0x40,0x00,0x00);			// GRID1，SEG7，数据要改
	WB8600M_Write_One(0x12,loop7_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop8_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x80,0x00,0x00,0x80,0x00,0x00);			// GRID1，SEG8
	WB8600M_Write_One(0x12,loop8_12reg[i]);
	_delay_us(delay_WB8600M_1);	
}


//下面的程序是在上面程序基础上，复制，把变量i逐渐加1
void Step2_R(void)		// 把 Step1_R 函数复制，改 Step2 + i改成1。别的不用改
{
	uint8_t i;
	i=1;

	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop1_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x01,0x00,0x00,0x01,0x00,0x00);				// GRID1，SEG1。第一个00是寄存器，后面是00-05寄存器数据
	WB8600M_Write_One(0x12,loop1_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop2_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x02,0x00,0x00,0x02,0x00,0x00);			// GRID1，SEG2
	WB8600M_Write_One(0x12,loop2_12reg[i]);
	_delay_us(delay_WB8600M_1);

	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop3_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x04,0x00,0x00,0x04,0x00,0x00);			// GRID1，SEG3
	WB8600M_Write_One(0x12,loop3_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop4_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x08,0x00,0x00,0x08,0x00,0x00);			// GRID1，SEG4
	WB8600M_Write_One(0x12,loop4_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop5_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x10,0x00,0x00,0x10,0x00,0x00);			// GRID1，SEG5
	WB8600M_Write_One(0x12,loop5_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop6_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x20,0x00,0x00,0x20,0x00,0x00);			// GRID1，SEG6
	WB8600M_Write_One(0x12,loop6_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop7_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x40,0x00,0x00,0x40,0x00,0x00);			// GRID1，SEG7
	WB8600M_Write_One(0x12,loop7_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop8_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x80,0x00,0x00,0x80,0x00,0x00);			// GRID1，SEG8
	WB8600M_Write_One(0x12,loop8_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
}

void Step3_R(void)		// 写00~05寄存器是连续写，单独函数：void WB8600M_Write_6
{
	uint8_t i;
	i=2;

	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop1_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x01,0x00,0x00,0x01,0x00,0x00);				// GRID1，SEG1。第一个00是寄存器，后面是00-05寄存器数据
	WB8600M_Write_One(0x12,loop1_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop2_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x02,0x00,0x00,0x02,0x00,0x00);			// GRID1，SEG2
	WB8600M_Write_One(0x12,loop2_12reg[i]);
	_delay_us(delay_WB8600M_1);

	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop3_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x04,0x00,0x00,0x04,0x00,0x00);			// GRID1，SEG3
	WB8600M_Write_One(0x12,loop3_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop4_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x08,0x00,0x00,0x08,0x00,0x00);			// GRID1，SEG4
	WB8600M_Write_One(0x12,loop4_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop5_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x10,0x00,0x00,0x10,0x00,0x00);			// GRID1，SEG5
	WB8600M_Write_One(0x12,loop5_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop6_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x20,0x00,0x00,0x20,0x00,0x00);			// GRID1，SEG6
	WB8600M_Write_One(0x12,loop6_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop7_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x40,0x00,0x00,0x40,0x00,0x00);			// GRID1，SEG7
	WB8600M_Write_One(0x12,loop7_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop8_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x80,0x00,0x00,0x80,0x00,0x00);			// GRID1，SEG8
	WB8600M_Write_One(0x12,loop8_12reg[i]);
	_delay_us(delay_WB8600M_1);
}

void Step4_R(void)		// 写00~05寄存器是连续写，单独函数：void WB8600M_Write_6
{
	uint8_t i;
	i=3;

	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop1_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x01,0x00,0x00,0x01,0x00,0x00);				// GRID1，SEG1。第一个00是寄存器，后面是00-05寄存器数据
	WB8600M_Write_One(0x12,loop1_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop2_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x02,0x00,0x00,0x02,0x00,0x00);			// GRID1，SEG2
	WB8600M_Write_One(0x12,loop2_12reg[i]);
	_delay_us(delay_WB8600M_1);

	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop3_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x04,0x00,0x00,0x04,0x00,0x00);			// GRID1，SEG3
	WB8600M_Write_One(0x12,loop3_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop4_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x08,0x00,0x00,0x08,0x00,0x00);			// GRID1，SEG4
	WB8600M_Write_One(0x12,loop4_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop5_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x10,0x00,0x00,0x10,0x00,0x00);			// GRID1，SEG5
	WB8600M_Write_One(0x12,loop5_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop6_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x20,0x00,0x00,0x20,0x00,0x00);			// GRID1，SEG6
	WB8600M_Write_One(0x12,loop6_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop7_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x40,0x00,0x00,0x40,0x00,0x00);			// GRID1，SEG7
	WB8600M_Write_One(0x12,loop7_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop8_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x80,0x00,0x00,0x80,0x00,0x00);			// GRID1，SEG8
	WB8600M_Write_One(0x12,loop8_12reg[i]);
	_delay_us(delay_WB8600M_1);
}

void Step5_R(void)		// 写00~05寄存器是连续写，单独函数：void WB8600M_Write_6
{
	uint8_t i;
	i=4;

	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop1_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x01,0x00,0x00,0x01,0x00,0x00);				// GRID1，SEG1。第一个00是寄存器，后面是00-05寄存器数据
	WB8600M_Write_One(0x12,loop1_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop2_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x02,0x00,0x00,0x02,0x00,0x00);			// GRID1，SEG2
	WB8600M_Write_One(0x12,loop2_12reg[i]);
	_delay_us(delay_WB8600M_1);

	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop3_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x04,0x00,0x00,0x04,0x00,0x00);			// GRID1，SEG3
	WB8600M_Write_One(0x12,loop3_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop4_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x08,0x00,0x00,0x08,0x00,0x00);			// GRID1，SEG4
	WB8600M_Write_One(0x12,loop4_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop5_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x10,0x00,0x00,0x10,0x00,0x00);			// GRID1，SEG5
	WB8600M_Write_One(0x12,loop5_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop6_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x20,0x00,0x00,0x20,0x00,0x00);			// GRID1，SEG6
	WB8600M_Write_One(0x12,loop6_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop7_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x40,0x00,0x00,0x40,0x00,0x00);			// GRID1，SEG7
	WB8600M_Write_One(0x12,loop7_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop8_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x80,0x00,0x00,0x80,0x00,0x00);			// GRID1，SEG8
	WB8600M_Write_One(0x12,loop8_12reg[i]);
	_delay_us(delay_WB8600M_1);
}

void Step6_R(void)		// 写00~05寄存器是连续写，单独函数：void WB8600M_Write_6
{
	uint8_t i;
	i=5;

	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop1_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x01,0x00,0x00,0x01,0x00,0x00);				// GRID1，SEG1。第一个00是寄存器，后面是00-05寄存器数据
	WB8600M_Write_One(0x12,loop1_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop2_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x02,0x00,0x00,0x02,0x00,0x00);			// GRID1，SEG2
	WB8600M_Write_One(0x12,loop2_12reg[i]);
	_delay_us(delay_WB8600M_1);

	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop3_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x04,0x00,0x00,0x04,0x00,0x00);			// GRID1，SEG3
	WB8600M_Write_One(0x12,loop3_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop4_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x08,0x00,0x00,0x08,0x00,0x00);			// GRID1，SEG4
	WB8600M_Write_One(0x12,loop4_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop5_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x10,0x00,0x00,0x10,0x00,0x00);			// GRID1，SEG5
	WB8600M_Write_One(0x12,loop5_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop6_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x20,0x00,0x00,0x20,0x00,0x00);			// GRID1，SEG6
	WB8600M_Write_One(0x12,loop6_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop7_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x40,0x00,0x00,0x40,0x00,0x00);			// GRID1，SEG7
	WB8600M_Write_One(0x12,loop7_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop8_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x80,0x00,0x00,0x80,0x00,0x00);			// GRID1，SEG8
	WB8600M_Write_One(0x12,loop8_12reg[i]);
	_delay_us(delay_WB8600M_1);
}

void Step7_R(void)		// 写00~05寄存器是连续写，单独函数：void WB8600M_Write_6
{
	uint8_t i;
	i=6;

	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop1_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x01,0x00,0x00,0x01,0x00,0x00);				// GRID1，SEG1。第一个00是寄存器，后面是00-05寄存器数据
	WB8600M_Write_One(0x12,loop1_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop2_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x02,0x00,0x00,0x02,0x00,0x00);			// GRID1，SEG2
	WB8600M_Write_One(0x12,loop2_12reg[i]);
	_delay_us(delay_WB8600M_1);

	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop3_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x04,0x00,0x00,0x04,0x00,0x00);			// GRID1，SEG3
	WB8600M_Write_One(0x12,loop3_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop4_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x08,0x00,0x00,0x08,0x00,0x00);			// GRID1，SEG4
	WB8600M_Write_One(0x12,loop4_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop5_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x10,0x00,0x00,0x10,0x00,0x00);			// GRID1，SEG5
	WB8600M_Write_One(0x12,loop5_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop6_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x20,0x00,0x00,0x20,0x00,0x00);			// GRID1，SEG6
	WB8600M_Write_One(0x12,loop6_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop7_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x40,0x00,0x00,0x40,0x00,0x00);			// GRID1，SEG7
	WB8600M_Write_One(0x12,loop7_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop8_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x80,0x00,0x00,0x80,0x00,0x00);			// GRID1，SEG8
	WB8600M_Write_One(0x12,loop8_12reg[i]);
	_delay_us(delay_WB8600M_1);
}

void Step8_R(void)		// 写00~05寄存器是连续写，单独函数：void WB8600M_Write_6
{
	uint8_t i;
	i=7;

	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop1_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x01,0x00,0x00,0x01,0x00,0x00);				// GRID1，SEG1。第一个00是寄存器，后面是00-05寄存器数据
	WB8600M_Write_One(0x12,loop1_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop2_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x02,0x00,0x00,0x02,0x00,0x00);			// GRID1，SEG2
	WB8600M_Write_One(0x12,loop2_12reg[i]);
	_delay_us(delay_WB8600M_1);

	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop3_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x04,0x00,0x00,0x04,0x00,0x00);			// GRID1，SEG3
	WB8600M_Write_One(0x12,loop3_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop4_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x08,0x00,0x00,0x08,0x00,0x00);			// GRID1，SEG4
	WB8600M_Write_One(0x12,loop4_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop5_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x10,0x00,0x00,0x10,0x00,0x00);			// GRID1，SEG5
	WB8600M_Write_One(0x12,loop5_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop6_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x20,0x00,0x00,0x20,0x00,0x00);			// GRID1，SEG6
	WB8600M_Write_One(0x12,loop6_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop7_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x40,0x00,0x00,0x40,0x00,0x00);			// GRID1，SEG7
	WB8600M_Write_One(0x12,loop7_12reg[i]);
	_delay_us(delay_WB8600M_1);
	
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,loop8_10reg[i]);		// 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,WB8600M_Fre);		// GRID扫描行数
	WB8600M_Write_6(0x00,0x80,0x00,0x00,0x80,0x00,0x00);			// GRID1，SEG8
	WB8600M_Write_One(0x12,loop8_12reg[i]);
	_delay_us(delay_WB8600M_1);
}

//main函数里写 HXSW_R 这个函数，就可以实现彗星扫尾灯效了
void HXSW_R(void)		// 7个灯，有1个不亮
{
	uint16_t j;
	
	for(j=0;j<WB8600M_Speed;j++)	// WB8600M_Speed在HXSW.h文件中定义，WB8600M_Speed越大，旋转速度越慢
	{
		Step1_R();
	}
	for(j=0;j<WB8600M_Speed;j++)
	{
		Step2_R();
	}
	for(j=0;j<WB8600M_Speed;j++)
	{
		Step3_R();
	}
	for(j=0;j<WB8600M_Speed;j++)
	{
		Step4_R();
	}
	for(j=0;j<WB8600M_Speed;j++)
	{
		Step5_R();
	}
	for(j=0;j<WB8600M_Speed;j++)
	{
		Step6_R();
	}
	for(j=0;j<WB8600M_Speed;j++)
	{
		Step7_R();
	}
	for(j=0;j<WB8600M_Speed;j++)
	{
		Step8_R();
	}
}

void I2C_start(void)
{
	SDA_OUT;
    SCL_1;
	_delay_us(1);
	SDA_1;
	_delay_us(1);
	SDA_0;
	_delay_us(1);
	SCL_0;
	_delay_us(1);
  
}

void I2C_stop(void)
{
	SDA_OUT;
	SCL_0;
	_delay_us(1);
	SDA_0;
	_delay_us(1);
	SCL_1;
	_delay_us(1);
	SDA_1;
	_delay_us(1);
}

//等待应答信号
//返回值：1，接收应答失败
//       0，接收应答成功
uint8_t Ack(void)
{
	
  uint16_t ErrCount=0;
	SDA_IN;
	_delay_us(1);
	SCL_1;
	_delay_us(1);
	while(SDA_Value)
	{
		ErrCount++;
		if(ErrCount>2500)
		{
			I2C_stop();
			return 1;
		}
	}

	SCL_0;
	_delay_us(1);

	return 0;

}


void I2C_Write(uint8_t input)		// 先写bit7最后写bit0（先写高位  MSB）
{
	uint8_t i;
	SDA_OUT;
  SCL_0;
	for(i=0;i<8;i++)
	{
		if(input&0x80)
    {
      SDA_1;
		}
    else
		{
      SDA_0;
		}
    _delay_us(1);
		SCL_1;
		_delay_us(1);
		SCL_0;
		_delay_us(1);
		input=input<<1;
	}
}


void WB8600M_Write_One(uint8_t cmd, uint8_t data)		// 地址单次写
{
	I2C_start();
	_delay_us(1);
	I2C_Write(WB8600M_Addr);
	Ack();
	I2C_Write(cmd);
	Ack();
	I2C_Write(data);
	Ack();
	I2C_stop();
	_delay_us(1);
}

void WB8600M_Write_All(uint8_t cmd, uint8_t data)		// 地址连续写，这个函数只为了写00H~0FH，控制显示数据
{
	uint8_t i;
	I2C_start();
	_delay_us(1);
	I2C_Write(WB8600M_Addr);
	Ack();
	I2C_Write(cmd);
	Ack();
	
	for(i=0;i<16;i++)
	{
		I2C_Write(data);
		Ack();
		_delay_us(1);
	}
	I2C_stop();
	_delay_us(1);
}

// 只供彗星扫尾程序使用，连续写00~06寄存器，节约指令时间，设置6扫
void WB8600M_Write_6(uint8_t cmd, uint8_t data1,uint8_t data2, uint8_t data3, uint8_t data4, uint8_t data5, uint8_t data6)
{
	//	uint8_t i;
	I2C_start();
	_delay_us(1);
	I2C_Write(WB8600M_Addr);//芯片IC片选地址
	Ack();
	I2C_Write(cmd);//显示数据地址
	Ack();
	
	I2C_Write(data1); Ack();
	I2C_Write(data2); Ack();
	I2C_Write(data3); Ack();
	I2C_Write(data4); Ack();
	I2C_Write(data5); Ack();
	I2C_Write(data6); Ack();

	I2C_stop();
	_delay_us(1);
}

u8 luminance;

void LED_ON(void)    // 连续 写 全亮
{
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,luminance);	  //00~0F是逐渐增加亮度 0xff
	WB8600M_Write_One(0x11,0x0f); 
	WB8600M_Write_All(0x00,0xFF); 
	WB8600M_Write_One(0x12,0x03);	  //03-工作状态，显示开  01-工作状态，显示关  00-Shutdown
}

void LED_OFF(void)   // 连续写
{
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,0x00);	  // 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,0x0f);
	WB8600M_Write_All(0x00,0x00);	
	WB8600M_Write_One(0x12,0x00);	  // 12H写00和01 02，都可以关
}

void WB8600M(void)
{
  WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,0x00);	  // 00~0F是逐渐增加亮度
	WB8600M_Write_One(0x11,0x0f);
	WB8600M_Write_All(0x00,0x00);	
	WB8600M_Write_One(0x12,0x00);	  // 12H写00和01 02，都可以关
}


void WB8600M_Teat(void)   // 测试
{
  SDA_1;
  _delay_us(1);
  SDA_0;
  _delay_us(1);
  SDA_1;
  _delay_us(1);
  SDA_0;
  _delay_us(1);
  SDA_1;
  _delay_us(1);
  SDA_0;
}


void Red_on(uint8_t current)		
{
	uint8_t j;
	WB8600M_Write_One(0x12,0x01);
	WB8600M_Write_One(0x10,current);	  
	WB8600M_Write_One(0x11,0x3F);	  
	for(j=0;j<16;j++)
	{
		WB8600M_Write_One(j,0xFF);
	}
	WB8600M_Write_One(0x12,0x03);
}

void Breathe_R(void)		
{
	uint8_t i;
	for(i=0;i<16;i++)
	{
		Red_on(i);
		_delay_us(5000);
	}
	_delay_us(50000);

	for(i=15;i>0;i--)
	{
		Red_on(i);
		_delay_us(5000);
	}
	Red_on(0);
	_delay_us(5000);
	LED_OFF();
	_delay_us(50000);
}

void WB8600M_Show_Num(void)
{
  Led_Show[0] = Led_Num[0];
  Led_Show[1] = Led_Num[1];
  Led_Show[2] = Led_Num[2];
  Led_Show[3] = Led_Num[3];
}

void WB8600M_Show_Icon(void)
{
  Led_Icon & c_bit_0   ?(Led_Show[0] |= bit10000000):(Led_Show[0] &=~ bit10000000);  //电量百位1

  Led_Icon & c_bit_1   ?(Led_Show[1] |= bit10000000):(Led_Show[1] &=~ bit10000000);  //闪电
  
  Led_Icon & c_bit_2   ?(Led_Show[2] |= bit10000000):(Led_Show[2] &=~ bit10000000);  //油量百位1

  Led_Icon & c_bit_3   ?(Led_Show[3] |= bit10000000):(Led_Show[3] &=~ bit10000000);  //油量

  Led_Icon & c_bit_4   ?(Led_Show[7] |= bit00000011):(Led_Show[7] &=~ bit00000011);  //低档       
  
  Led_Icon & c_bit_5   ?(Led_Show[7] |= bit00001100):(Led_Show[7] &=~ bit00001100);  //高档   

  Led_L_Icon & c_bit_0   ?(Led_Show[15] |= bit00000111):(Led_Show[15] &=~ bit00000111); //A16 B16 C16
  
  Led_L_Icon & c_bit_1   ?(Led_Show[4] |= bit00100000):(Led_Show[4] &=~ bit00100000);//F5      
                                                                                               
  Led_L_Icon & c_bit_2   ?(Led_Show[4] |= bit01000000):(Led_Show[4] &=~ bit01000000);//G5
  
  Led_L_Icon & c_bit_3   ?(Led_Show[15] |= bit10000000):(Led_Show[15] &=~ bit10000000);//H16
  
  Led_L_Icon & c_bit_4   ?(Led_Show[13] |= bit00001100):(Led_Show[13] &=~ bit00001100);//C14 D14
  
  Led_L_Icon & c_bit_5   ?(Led_Show[4] |= bit00010000):(Led_Show[4] &=~ bit00010000);//E5
  
  Led_L_Icon & c_bit_6   ?(Led_Show[4] |= bit10001111):(Led_Show[4] &=~ bit10001111);  // 5ABCDH
  Led_L_Icon & c_bit_6   ?(Led_Show[13] |= bit11110000):(Led_Show[13] &=~ bit11110000);// 14EFGH
  Led_L_Icon & c_bit_6   ?(Led_Show[14] |= bit11111111):(Led_Show[14] &=~ bit11111111);// 15ABCDEFGH
  Led_L_Icon & c_bit_6   ?(Led_Show[15] |= bit11111000):(Led_Show[15] &=~ bit11111000);// 16DEFGH
  
  Led_M_Icon & c_bit_0   ?(Led_Show[5]  |= bit10000000):(Led_Show[5] &=~  bit10000000); //H6
  Led_M_Icon & c_bit_1   ?(Led_Show[5]  |= bit01000000):(Led_Show[5] &=~  bit01000000); //G6
  Led_M_Icon & c_bit_2   ?(Led_Show[6]  |= bit10000000):(Led_Show[6] &=~  bit10000000); //H7
  Led_M_Icon & c_bit_3   ?(Led_Show[5]  |= bit00000001):(Led_Show[5] &=~  bit00000001); //A6      
  Led_M_Icon & c_bit_4   ?(Led_Show[5]  |= bit00000110):(Led_Show[5] &=~  bit00000110); //B6 C6
  Led_M_Icon & c_bit_5   ?(Led_Show[5]  |= bit00001000):(Led_Show[5] &=~  bit00001000); //D6
  Led_M_Icon & c_bit_6   ?(Led_Show[5]  |= bit00110000):(Led_Show[5] &=~  bit00110000); //E6 F6 
  Led_M_Icon & c_bit_7   ?(Led_Show[6]  |= bit00000010):(Led_Show[6] &=~  bit00000010); //B7
  Led_M_Icon & c_bit_8   ?(Led_Show[6]  |= bit00000100):(Led_Show[6] &=~  bit00000100); //C7
  Led_M_Icon & c_bit_9   ?(Led_Show[6]  |= bit00001000):(Led_Show[6] &=~  bit00001000); //D7
  Led_M_Icon & c_bit_10  ?(Led_Show[6]  |= bit00010000):(Led_Show[6] &=~  bit00010000); //E7
  Led_M_Icon & c_bit_11  ?(Led_Show[6]  |= bit00100000):(Led_Show[6] &=~  bit00100000); //F7
  Led_M_Icon & c_bit_12  ?(Led_Show[6]  |= bit00000001):(Led_Show[6] &=~  bit00000001); //A7
  Led_M_Icon & c_bit_13  ?(Led_Show[6]  |= bit01000000):(Led_Show[6] &=~  bit01000000); //G7
  
  
  Led_R_Icon & c_bit_0   ?(Led_Show[12]  |= bit00000011):(Led_Show[12] &=~  bit00000011); //13 AB 12 GH
  Led_R_Icon & c_bit_0   ?(Led_Show[11]  |= bit11000000):(Led_Show[11] &=~  bit11000000); //13 AB 12 GH
  
  Led_R_Icon & c_bit_1   ?(Led_Show[12]  |= bit00011100):(Led_Show[12] &=~  bit00011100); //13CDE
  
  Led_R_Icon & c_bit_2   ?(Led_Show[12]  |= bit10000000):(Led_Show[12] &=~  bit10000000); //13H 14AB
  Led_R_Icon & c_bit_2   ?(Led_Show[13]  |= bit00000011):(Led_Show[13] &=~  bit00000011); //13H 14AB
  
  Led_R_Icon & c_bit_3   ?(Led_Show[11]  |= bit00111110):(Led_Show[11] &=~  bit00111110); //12BCDEF      
  Led_R_Icon & c_bit_4   ?(Led_Show[12]  |= bit01100000):(Led_Show[12] &=~  bit01100000); //13FG
  
  Led_R_Icon & c_bit_5   ?(Led_Show[9]   |= bit11110000):(Led_Show[9]  &=~  bit01100000); //10FG
  
  Led_R_Icon & c_bit_6   ?(Led_Show[11]  |= bit00000001):(Led_Show[11] &=~  bit00000001); //12A 11GH 
  Led_R_Icon & c_bit_6   ?(Led_Show[10]  |= bit11000000):(Led_Show[10] &=~  bit11000000); //12A 11GH 
  
  Led_R_Icon & c_bit_7   ?(Led_Show[10]  |= bit00000011):(Led_Show[10] &=~  bit00000001); //11A 10E 10H
  Led_R_Icon & c_bit_7   ?(Led_Show[9 ]  |= bit00000011):(Led_Show[9]  &=~  bit10010000); //11A 10E 10H
  
  Led_R_Icon & c_bit_8   ?(Led_Show[10]  |= bit00111100):(Led_Show[10] &=~  bit00111110); //11BCDEF 
  
  Led_R_Icon & c_bit_9   ?(Led_Show[9]  |= bit00001111):(Led_Show[9] &=~  bit00001111); //10ABCD 9GH
  Led_R_Icon & c_bit_9   ?(Led_Show[8]  |= bit11000000):(Led_Show[8] &=~  bit11000000); //10ABCD 9GH
  
  Led_R_Icon & c_bit_10  ?(Led_Show[7]  |= bit11110000):(Led_Show[7] &=~  bit11110000); //8EFGH
  Led_R_Icon & c_bit_11  ?(Led_Show[8]  |= bit00000011):(Led_Show[8] &=~  bit00000011); //9AB
  Led_R_Icon & c_bit_12  ?(Led_Show[8]  |= bit00001100):(Led_Show[8] &=~  bit00001100); //9CD
  Led_R_Icon & c_bit_13  ?(Led_Show[8]  |= bit00110000):(Led_Show[8] &=~  bit00110000); //9EF
  
}

//00000000
//HGFEDCBA

void WB8600M_Deal(void)
{
      
  uint8_t i;
  static u8 j = 0;
  if(Dispinfo.Disp_EN)
  {
      WB8600M_Show_Num();  //显示数码管
      WB8600M_Show_Icon(); //显示图标
  }
  else
  {
      for(i=0;i<16;i++)
      {
          Led_Show[i] = 0;
      } 
  }
      
      luminance = 0;
     
//      WB8600M_Write_One(0x12,0x01);
//      WB8600M_Write_One(0x10,luminance);	  //00~0F是逐渐增加亮度 0xff
//      WB8600M_Write_One(0x11,0x0f); 
      
      I2C_start();
      _delay_us(1);
      I2C_Write(WB8600M_Addr);
      Ack();
      I2C_Write(4*j);
      Ack();
      for(i=0;i<4;i++)
      {
        I2C_Write(Led_Show[(4*j)+i]);
        Ack();
        _delay_us(1);
      }
      I2C_stop();
      _delay_us(1);
      if(j < 3)
      {
        j++;
      }
      else
      {
        j = 0;
      }
      
      
//      WB8600M_Write_One(0x12,0x03);	  //03-工作状态，显示开  01-工作状态，显示关  00-Shutdown
//    WB8600M_Write_One(0x12,0x01);
//    WB8600M_Write_One(0x10,0x0f);	  //00~0F是逐渐增加亮度 0xff
//    WB8600M_Write_One(0x11,0x0f); 
//    WB8600M_Write_All(0x00,0xff); 
//    WB8600M_Write_One(0x12,0x03);	  //03-工作状态，显示开  01-工作状态，显示关  00-Shutdown

//    WB8600M_Write_One(0x12,0x01);
//    WB8600M_Write_One(0x10,0x0f);	  //00~0F是逐渐增加亮度 0xff
//    WB8600M_Write_One(0x11,0x01); 
//    WB8600M_Write_One(0x01,0x01); 
//    WB8600M_Write_One(0x12,0x03);	  //03-工作状态，显示开  01-工作状态，显示关  00-Shutdown

//    WB8600M_Write_One(0x12,0x01);
//    WB8600M_Write_One(0x10,0x0f);	  //00~0F是逐渐增加亮度 0xff
//    WB8600M_Write_One(0x11,0x01); 
//    WB8600M_Write_One(0x02,0x04); 
//    WB8600M_Write_One(0x12,0x03);	  //03-工作状态，显示开  01-工作状态，显示关  00-Shutdown

//    WB8600M_Write_One(0x12,0x01);
//    WB8600M_Write_One(0x10,0x0f);	  //00~0F是逐渐增加亮度 0xff
//    WB8600M_Write_One(0x11,0x0f); 
//    WB8600M_Write_One(0x03,0x08); 
//    WB8600M_Write_One(0x12,0x03);	  //03-工作状态，显示开  01-工作状态，显示关  00-Shutdown

//    WB8600M_Write_One(0x12,0x01);
//    WB8600M_Write_One(0x10,0x0f);	  //00~0F是逐渐增加亮度 0xff
//    WB8600M_Write_One(0x11,0x0f); 
//    WB8600M_Write_One(0x04,0x10); 
//    WB8600M_Write_One(0x12,0x03);	  //03-工作状态，显示开  01-工作状态，显示关  00-Shutdown

//    WB8600M_Write_One(0x12,0x01);
//    WB8600M_Write_One(0x10,0x0f);	  //00~0F是逐渐增加亮度 0xff
//    WB8600M_Write_One(0x11,0x0f); 
//    WB8600M_Write_One(0x05,0x20); 
//    WB8600M_Write_One(0x12,0x03);	  //03-工作状态，显示开  01-工作状态，显示关  00-Shutdown

//    WB8600M_Write_One(0x12,0x01);
//    WB8600M_Write_One(0x10,0x0f);	  //00~0F是逐渐增加亮度 0xff
//    WB8600M_Write_One(0x11,0x0f); 
//    WB8600M_Write_One(0x06,0x40); 
//    WB8600M_Write_One(0x12,0x03);	  //03-工作状态，显示开  01-工作状态，显示关  00-Shutdown

//    WB8600M_Write_One(0x12,0x01);
//    WB8600M_Write_One(0x10,0x0f);	  //00~0F是逐渐增加亮度 0xff
//    WB8600M_Write_One(0x11,0x0f); 
//    WB8600M_Write_One(0x07,0x80); 
//    WB8600M_Write_One(0x12,0x03);	  //03-工作状态，显示开  01-工作状态，显示关  00-Shutdown
   
}
