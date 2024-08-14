#ifndef _WB8600_H
#define _WB8600_H

#define WB8600M_Speed    200	  //ѭ�������Ƶ���ת�ٶ�
#define WB8600M_Fre      0x35	//11�Ĵ���
#define delay_WB8600M_1  2000//1065	//��֮����ʱ1065us

#define WB8600M_Addr 0x84


#define		bit00000000		0x00
#define		bit00000001		0x01
#define		bit00000010		0x02
#define		bit00000011		0x03
#define		bit00000100		0x04
#define		bit00000101		0x05
#define		bit00000110		0x06
#define		bit00000111		0x07
#define		bit00001000		0x08
#define		bit00001001		0x09
#define		bit00001010		0x0a
#define		bit00001011		0x0b
#define		bit00001100		0x0c
#define		bit00001101		0x0d
#define		bit00001110		0x0e
#define		bit00001111		0x0f

#define		bit00010000		0x10
#define		bit00010001		0x11
#define		bit00010010		0x12
#define		bit00010011		0x13
#define		bit00010100		0x14
#define		bit00010101		0x15
#define		bit00010110		0x16
#define		bit00010111		0x17
#define		bit00011000		0x18
#define		bit00011001		0x19
#define		bit00011010		0x1a
#define		bit00011011		0x1b
#define		bit00011100		0x1c
#define		bit00011101		0x1d
#define		bit00011110		0x1e
#define		bit00011111		0x1f

#define		bit00100000		0x20
#define		bit00100001		0x21
#define		bit00100010		0x22
#define		bit00100011		0x23
#define		bit00100100		0x24
#define		bit00100101		0x25
#define		bit00100110		0x26
#define		bit00100111		0x27
#define		bit00101000		0x28
#define		bit00101001		0x29
#define		bit00101010		0x2a
#define		bit00101011		0x2b
#define		bit00101100		0x2c
#define		bit00101101		0x2d
#define		bit00101110		0x2e
#define		bit00101111		0x2f

#define		bit00110000		0x30
#define		bit00110001		0x31
#define		bit00110010		0x32
#define		bit00110011		0x33
#define		bit00110100		0x34
#define		bit00110101		0x35
#define		bit00110110		0x36
#define		bit00110111		0x37
#define		bit00111000		0x38
#define		bit00111001		0x39
#define		bit00111010		0x3a
#define		bit00111011		0x3b
#define		bit00111100		0x3c
#define		bit00111101		0x3d
#define		bit00111110		0x3e
#define		bit00111111		0x3f

#define		bit01000000		0x40
#define		bit01000001		0x41
#define		bit01000010		0x42
#define		bit01000011		0x43
#define		bit01000100		0x44
#define		bit01000101		0x45
#define		bit01000110		0x46
#define		bit01000111		0x47
#define		bit01001000		0x48
#define		bit01001001		0x49
#define		bit01001010		0x4a
#define		bit01001011		0x4b
#define		bit01001100		0x4c
#define		bit01001101		0x4d
#define		bit01001110		0x4e
#define		bit01001111		0x4f

#define		bit01010000		0x50
#define		bit01010001		0x51
#define		bit01010010		0x52
#define		bit01010011		0x53
#define		bit01010100		0x54
#define		bit01010101		0x55
#define		bit01010110		0x56
#define		bit01010111		0x57
#define		bit01011000		0x58
#define		bit01011001		0x59
#define		bit01011010		0x5a
#define		bit01011011		0x5b
#define		bit01011100		0x5c
#define		bit01011101		0x5d
#define		bit01011110		0x5e
#define		bit01011111		0x5f

#define		bit01100000		0x60
#define		bit01100001		0x61
#define		bit01100010		0x62
#define		bit01100011		0x63
#define		bit01100100		0x64
#define		bit01100101		0x65
#define		bit01100110		0x66
#define		bit01100111		0x67
#define		bit01101000		0x68
#define		bit01101001		0x69
#define		bit01101010		0x6a
#define		bit01101011		0x6b
#define		bit01101100		0x6c
#define		bit01101101		0x6d
#define		bit01101110		0x6e
#define		bit01101111		0x6f

#define		bit01110000		0x70
#define		bit01110001		0x71
#define		bit01110010		0x72
#define		bit01110011		0x73
#define		bit01110100		0x74
#define		bit01110101		0x75
#define		bit01110110		0x76
#define		bit01110111		0x77
#define		bit01111000		0x78
#define		bit01111001		0x79
#define		bit01111010		0x7a
#define		bit01111011		0x7b
#define		bit01111100		0x7c
#define		bit01111101		0x7d
#define		bit01111110		0x7e
#define		bit01111111		0x7f

#define		bit10000000		0x80
#define		bit10000001		0x81
#define		bit10000010		0x82
#define		bit10000011		0x83
#define		bit10000100		0x84
#define		bit10000101		0x85
#define		bit10000110		0x86
#define		bit10000111		0x87
#define		bit10001000		0x88
#define		bit10001001		0x89
#define		bit10001010		0x8a
#define		bit10001011		0x8b
#define		bit10001100		0x8c
#define		bit10001101		0x8d
#define		bit10001110		0x8e
#define		bit10001111		0x8f

#define		bit10010000		0x90
#define		bit10010001		0x91
#define		bit10010010		0x92
#define		bit10010011		0x93
#define		bit10010100		0x94
#define		bit10010101		0x95
#define		bit10010110		0x96
#define		bit10010111		0x97
#define		bit10011000		0x98
#define		bit10011001		0x99
#define		bit10011010		0x9a
#define		bit10011011		0x9b
#define		bit10011100		0x9c
#define		bit10011101		0x9d
#define		bit10011110		0x9e
#define		bit10011111		0x9f

#define		bit10100000		0xa0
#define		bit10100001		0xa1
#define		bit10100010		0xa2
#define		bit10100011		0xa3
#define		bit10100100		0xa4
#define		bit10100101		0xa5
#define		bit10100110		0xa6
#define		bit10100111		0xa7
#define		bit10101000		0xa8
#define		bit10101001		0xa9
#define		bit10101010		0xaa
#define		bit10101011		0xab
#define		bit10101100		0xac
#define		bit10101101		0xad
#define		bit10101110		0xae
#define		bit10101111		0xaf

#define		bit10110000		0xb0
#define		bit10110001		0xb1
#define		bit10110010		0xb2
#define		bit10110011		0xb3
#define		bit10110100		0xb4
#define		bit10110101		0xb5
#define		bit10110110		0xb6
#define		bit10110111		0xb7
#define		bit10111000		0xb8
#define		bit10111001		0xb9
#define		bit10111010		0xba
#define		bit10111011		0xbb
#define		bit10111100		0xbc
#define		bit10111101		0xbd
#define		bit10111110		0xbe
#define		bit10111111		0xbf

#define		bit11000000		0xc0
#define		bit11000001		0xc1
#define		bit11000010		0xc2
#define		bit11000011		0xc3
#define		bit11000100		0xc4
#define		bit11000101		0xc5
#define		bit11000110		0xc6
#define		bit11000111		0xc7
#define		bit11001000		0xc8
#define		bit11001001		0xc9
#define		bit11001010		0xca
#define		bit11001011		0xcb
#define		bit11001100		0xcc
#define		bit11001101		0xcd
#define		bit11001110		0xce
#define		bit11001111		0xcf

#define		bit11010000		0xd0
#define		bit11010001		0xd1
#define		bit11010010		0xd2
#define		bit11010011		0xd3
#define		bit11010100		0xd4
#define		bit11010101		0xd5
#define		bit11010110		0xd6
#define		bit11010111		0xd7
#define		bit11011000		0xd8
#define		bit11011001		0xd9
#define		bit11011010		0xda
#define		bit11011011		0xdb
#define		bit11011100		0xdc
#define		bit11011101		0xdd
#define		bit11011110		0xde
#define		bit11011111		0xdf

#define		bit11100000		0xe0
#define		bit11100001		0xe1
#define		bit11100010		0xe2
#define		bit11100011		0xe3
#define		bit11100100		0xe4
#define		bit11100101		0xe5
#define		bit11100110		0xe6
#define		bit11100111		0xe7
#define		bit11101000		0xe8
#define		bit11101001		0xe9
#define		bit11101010		0xea
#define		bit11101011		0xeb
#define		bit11101100		0xec
#define		bit11101101		0xed
#define		bit11101110		0xee
#define		bit11101111		0xef

#define		bit11110000		0xf0
#define		bit11110001		0xf1
#define		bit11110010		0xf2
#define		bit11110011		0xf3
#define		bit11110100		0xf4
#define		bit11110101		0xf5
#define		bit11110110		0xf6
#define		bit11110111		0xf7
#define		bit11111000		0xf8
#define		bit11111001		0xf9
#define		bit11111010		0xfa
#define		bit11111011		0xfb
#define		bit11111100		0xfc
#define		bit11111101		0xfd
#define		bit11111110		0xfe
#define		bit11111111		0xff













#define WB8600M_








extern uint8_t Led_Show[16];
extern uint8_t Led_Num[4];

extern uint8_t Led_Icon;

extern uint16_t Led_L_Icon;
extern uint16_t Led_M_Icon;
extern uint16_t Led_R_Icon;

void I2C_Write(uint8_t input);
void WB8600M_Write_One(uint8_t cmd, uint8_t data);
void WB8600M_Write_All(uint8_t cmd, uint8_t data);
void WB8600M_Write_6(uint8_t cmd, uint8_t data1,uint8_t data2, uint8_t data3, uint8_t data4, uint8_t data5, uint8_t data6);
void LED_ON(void);
void LED_OFF(void);
void WB8600M_Teat(void);
void Breathe_R(void);
void WB8600M_Deal(void);

#endif

