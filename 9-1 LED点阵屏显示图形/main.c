#include "regx52.h"
#include "delay.h"

sbit RCK = P3^5;
sbit SCK = P3^6;
sbit SER = P3^4;

#define MATRIX_LED_PORT P0
/**
  * @brief: 74HC595写入一个字节
  * @param:写入的字节Data
  * @retval:无
  */
void _74HC595_WriteByte(unsigned char Byte)
{
    unsigned char i;
    for (i = 0;i < 8;i++)
    {
        SER = Byte & (0x80 >> i);//按位与出来的  任何非零数  都相当于“1”；0=0。
        SCK = 1;
        SCK = 0;
    }
    RCK = 1;
    RCK = 0;
}


/**
  * @brief: 点阵屏LED显示一列。
  * @param: Column列，范围0~7，最左边是第0行；Data在这列显示的灯，上边是高位。Column给低电平有效，Data高电平有效。eg：0，0xff => 第一行的小灯全亮
  * @retval:无
  */
void MatrixLED_ShowColum(unsigned char Column, unsigned char Data)
{
    
    _74HC595_WriteByte(Data);
    P0 = ~(0x80 >> Column);
    Delay(1);
    P0 = 0xff;

    // P0 = ~(0x80 >> Column);
    // _74HC595_WriteByte(Data);
    // Delay(1);
    // P0 = 0xff;
    // Data = 0x00;
}
void main()
{
    RCK = 0;
    SCK = 0;
    while (1)
    {
        MatrixLED_ShowColum(0, 0x10);   
        MatrixLED_ShowColum(1, 0x28);
        MatrixLED_ShowColum(2, 0x54);
        MatrixLED_ShowColum(3, 0x28);   
        MatrixLED_ShowColum(4, 0x10);
        MatrixLED_ShowColum(5, 0x28);
        MatrixLED_ShowColum(6, 0x44);
        MatrixLED_ShowColum(7, 0xfe);
    }
}