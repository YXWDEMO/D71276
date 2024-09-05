#include "AiP33A06.h"	
#include "main.h"
#include "typedef.h"
void _delay_us(void)
{
//   uint16_t i,j;
// 	for(j=0;j<us;j++)
// 	{
// 		for(i=0;i<;i++)
// 		{
	//__NOP();
	// 	}
	// }
  unsigned char i;
	for(i=0;i<1;i++);
}

void delay_ms(unsigned int k)
{
	unsigned int i,j;
	for(i=0;i<k;i++)
	{
		for(j=0;j<100;j++)
		_delay_us();
	}
}

void iic_start(void)
{
	SCL_1;
	SDA_1;
	_delay_us();
	SDA_0;
	_delay_us();
}
void iic_stop(void)
{
	SDA_0;
	SCL_1;
	_delay_us();
	SDA_1;
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
	SCL_0;
	// P3IO&=0XDF;//�滻����SDAΪ����
	SDA_IN;
	// LL_GPIO_SetPinMode(SDA_PORT,SDA_PIN,LL_GPIO_MODE_INPUT);
	SDA_1;
	_delay_us();
	SCL_1;
	_delay_us();
	SCL_0;
	// LL_GPIO_SetPinMode(SDA_PORT,SDA_PIN,LL_GPIO_MODE_OUTPUT);
  SDA_OUT;
	// P3IO|=0X20; //����Ϊ���
}
void AiP33A06_writebyte(unsigned char dat)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		// SCL=0;
		SCL_0;
		_delay_us();
		SDA(dat&0x80);
		dat<<=1;
		SCL_1;
		_delay_us();
	}
	AiP33A06_ACK();
}

void sysinit()
{
	AiP33A06_writecmd(0x3f);//����SEG�������30mA
	AiP33A06_writecmd(0x48);//����9��ɨ��
	AiP33A06_writecmd(0x53);//����GRID����ʱ��0.5us,���¶ȱ���
	AiP33A06_writecmd(0x6c);//����RAM��ַ��ADS[7:0]�Լ�,REX��ʹ�� 
	AiP33A06_writecmd(0x83);//����ʾ������SEG��������
	AiP33A06_writecmd(0x91);//�ر������λ��ʹ�ܵ��縴λ
	AiP33A06_writecmd(0xc0);//����ADS[7:4]λΪ0
	AiP33A06_writecmd(0xe0);//����ADS[3:0]λΪ0
}
//RAM���㡢����ʾ
void Ram_Clear()
{
	unsigned int i;
	AiP33A06_writecmd(0x48);//����9��ɨ��
	iic_start();
	AiP33A06_writebyte(slave_addr);
	AiP33A06_writebyte(0x68);//��ʼ��ַ0����ַ�Լ�
	for(i=0;i<144;i++)
	{
		AiP33A06_writebyte(0x00);
	}
	iic_stop();
}
void dis_sleep()
{
	Ram_Clear();
	AiP33A06_writecmd(0x6F);//����RAM��ַ��ADS[7:0]�Լ�,REX��ʹ�� 
}
void dis_Wakeup()
{
	AiP33A06_writecmd(0X6C);//����RAM��ַ��ADS[7:0]�Լ�,REX��ʹ��
}
// void delay()
// {
// 	unsigned char i;
// 	for(i=0;i<1;i++);
// }
// void delay_ms(unsigned int k)
// {
// 	unsigned int i,j;
// 	for(i=0;i<k;i++)
// 	{
// 		for(j=0;j<100;j++)
// 		delay();
// 	}
// }


//�̶���ַд����
void write_data(unsigned char addr,unsigned char pwm)
{
	unsigned char  addr_hignt,addr_low;
	addr_hignt =(addr&0xf0)>>4;
	addr_low   =addr&0x0f;
	AiP33A06_writecmd(0x6c);//����RAM��ַ��ADS[7:0]�Լ�,REX��ʹ�� 
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
		AiP33A06_writebyte(0xFF);
	}
	iic_stop();
}



