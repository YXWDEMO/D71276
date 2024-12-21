#include "AiP33A06.h"	
#include "main.h"
#include "typedef.h"
void _delay_us(uint16_t us)
{
	uint16_t i;
	for(i=0;i<us;i++)
	{
		__NOP();
	}
}

void iic_start(void)
{
	SCL(1);
	SDA(1);
	_delay_us(1);
	SDA(0);
	_delay_us(1);
}

void iic_stop(void)
{
	SDA(0);
	SCL(1);
	_delay_us(1);
	SDA(1);
}

void AiP33A06_writecmd(unsigned char dat)
{
	iic_start();
	AiP33A06_writebyte(slave_addr);
	AiP33A06_writebyte(dat);
	iic_stop();
}


void AiP33A06_ACK(void)
{
	SCL(0);
	// P3IO&=0XDF;//替换配置SDA为输入
    SDA_IN;
	// LL_GPIO_SetPinMode(SDA_PORT,SDA_PIN,LL_GPIO_MODE_INPUT);
	SDA(1);
	_delay_us(1);
	SCL(1);
	_delay_us(1);
	SCL(0);
	// LL_GPIO_SetPinMode(SDA_PORT,SDA_PIN,LL_GPIO_MODE_OUTPUT);
	SDA_OUT;
	// P3IO|=0X20; //配置为输出
}

void AiP33A06_writebyte(unsigned char dat)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		// SCL=0;
        SCL(0);
		_delay_us(1);
		SDA(dat & 0x80);
		dat<<=1;
		SCL(1);
		_delay_us(1);
	}
	AiP33A06_ACK();
}

void sysinit()
{
	AiP33A06_writecmd(0x3f);//设置SEG输出电流30mA
	AiP33A06_writecmd(0x48);//设置9行扫描
	AiP33A06_writecmd(0x53);//设置GRID死区时间0.5us,无温度保护
	AiP33A06_writecmd(0x6c);//设置RAM地址从ADS[7:0]自加,REX不使能 
	AiP33A06_writecmd(0x83);//开显示，开启SEG消隐功能
	AiP33A06_writecmd(0x91);//关闭软件复位，使能掉电复位
	AiP33A06_writecmd(0xc0);//设置ADS[7:4]位为0
	AiP33A06_writecmd(0xe0);//设置ADS[3:0]位为0
}

void Ram_Clear()
{
	unsigned int i;
	AiP33A06_writecmd(0x48);//设置9行扫描
	iic_start();
	AiP33A06_writebyte(slave_addr);
	AiP33A06_writebyte(0x68);//起始地址0，地址自加
	for(i=0;i<144;i++)
	{
		AiP33A06_writebyte(0x00);
	}
	iic_stop();
}

void dis_sleep()
{
	Ram_Clear();
	AiP33A06_writecmd(0x6F);//设置RAM地址从ADS[7:0]自加,REX不使能 
}
void dis_Wakeup()
{
	AiP33A06_writecmd(0X6C);//设置RAM地址从ADS[7:0]自加,REX不使能
}


void write_data(unsigned char addr,unsigned char pwm)
{
	unsigned char  addr_hignt,addr_low;
	addr_hignt =(addr&0xf0)>>4;
	addr_low   =addr&0x0f;
	AiP33A06_writecmd(0x6c);//设置RAM地址从ADS[7:0]自加,REX不使能 
	AiP33A06_writecmd(0xc0|addr_hignt);
	iic_start();
	AiP33A06_writebyte(slave_addr);
	AiP33A06_writebyte(0xE0|addr_low);
	AiP33A06_writebyte(pwm);
	iic_stop();
}

void display()
{
	unsigned char i;
	iic_start();
	AiP33A06_writebyte(slave_addr);
	AiP33A06_writebyte(0x68);
	for(i=0;i<144;i++)
	{
		AiP33A06_writebyte(0xff);
	}
	iic_stop();
}
