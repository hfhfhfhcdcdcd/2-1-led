#include "regx52.h"

sbit DS1302_SCLK = P3 ^ 6;
sbit DS1302_IO = P3 ^ 4;
sbit DS1302_CE = P3 ^ 5;

/**
  * @brief: “写”命令。写的是秒、分、小时、几号、几月、星期几、哪一年、写保护。读指令就是写指令或上0X01
  * @param:无
  * @retval:无
  */
#define DS1302_Sencond  0x80
#define DS1302_Minute   0x82
#define DS1302_Hour     0x84
#define DS1302_Data     0x86
#define DS1302_Mouth    0x88
#define DS1302_Day      0x8A
#define DS1302_Year     0x8C
#define DS1302_WP       0x8E

unsigned char DS1302_Time[] = { 0,1,2,3,4,5,6 };

/**
    * @brief: 初始化DS1302
  * @param:无
  * @retval:无
  */
void DS1302_Init(void)
{
  DS1302_CE = 0;
  DS1302_SCLK = 0;
}

/**
  * @brief: 向DS1302发送一个字节的"写"命令。和一个字节的数据
  * @param:Command：发送的命令
  * @param:Data：写入的数据
  * @retval:无
  */
void DS1302_WriteByte(unsigned char Command, unsigned char Data)
{
  unsigned char i = 0;
  DS1302_CE = 1;
  
  for (i = 0;i < 8;i++)
  {
    DS1302_IO = Command & (0x01 << i);//先写低位
    DS1302_SCLK = 1;
    DS1302_SCLK = 0;
  }
  for (i = 0;i < 8;i++)
  { 
      DS1302_IO = Data & (0x01 << i);
      DS1302_SCLK = 1;
      DS1302_SCLK = 0;
  }
  DS1302_CE = 0;
}

/**
  * @brief: 读一个字节.传入一个读指令，释放io线，读出io线上的字节。
  * @param:读命令Command
  * @retval:读到的数据Data
  */
unsigned char DS1302_ReadData(unsigned char Command)
{
  unsigned char i, Data=0x00;
  Command |= 0x01;
  DS1302_CE = 1;
  
  for (i = 0;i < 8;i++)//发送完1字节的命令
  {
    DS1302_IO = Command & (0x01 << i);
    DS1302_SCLK = 0;
    DS1302_SCLK = 1;
    
  }
  for (i = 0;i < 8;i++)//接收1字节的数据
  {
    DS1302_SCLK = 1;
    DS1302_SCLK = 0;
    if (DS1302_IO) { Data |= (0x01 << i); }
  }
  DS1302_CE = 0;
  DS1302_IO = 0;//MCU释放IO线
  return Data;

}                              

/**
  * @brief: 设置时间
  * @param:无
  * @retval:无
  */
void DS1302_SetTime(void)
{
  DS1302_WriteByte(DS1302_WP, 0x00);//解除写保护
  DS1302_WriteByte(DS1302_Year,   DS1302_Time[0] / 10 * 16 + DS1302_Time[0] % 10);
  DS1302_WriteByte(DS1302_Mouth,  DS1302_Time[1] / 10 * 16 + DS1302_Time[1] % 10);
  DS1302_WriteByte(DS1302_Data,   DS1302_Time[2] / 10 * 16 + DS1302_Time[2] % 10);
  DS1302_WriteByte(DS1302_Hour,   DS1302_Time[3] / 10 * 16 + DS1302_Time[3] % 10);
  DS1302_WriteByte(DS1302_Minute, DS1302_Time[4] / 10 * 16 + DS1302_Time[4] % 10);
  DS1302_WriteByte(DS1302_Sencond,DS1302_Time[5] / 10 * 16 + DS1302_Time[5] % 10);
  DS1302_WriteByte(DS1302_Day,    DS1302_Time[6] / 10 * 16 + DS1302_Time[6] % 10);
  DS1302_WriteByte(DS1302_WP, 0x80);//打开写保护
}

/**
  * @brief:读取时间
  * @param:无
  * @retval:无
  */
void DS1302_ReadTime(void)
{
  DS1302_Time[0] = DS1302_ReadData(DS1302_Year)   /16*10+DS1302_ReadData(DS1302_Year)   %16;
  DS1302_Time[1] = DS1302_ReadData(DS1302_Mouth)  /16*10+DS1302_ReadData(DS1302_Mouth)  %16;
  DS1302_Time[2] = DS1302_ReadData(DS1302_Data)   /16*10+DS1302_ReadData(DS1302_Data)   %16;
  DS1302_Time[3] = DS1302_ReadData(DS1302_Hour)   /16*10+DS1302_ReadData(DS1302_Hour)   %16;
  DS1302_Time[4] = DS1302_ReadData(DS1302_Minute) /16*10+DS1302_ReadData(DS1302_Minute) %16;
  DS1302_Time[5] = DS1302_ReadData(DS1302_Sencond)/16*10+DS1302_ReadData(DS1302_Sencond)%16;
  DS1302_Time[6] = DS1302_ReadData(DS1302_Day)    /16*10+DS1302_ReadData(DS1302_Day)    %16;
}

