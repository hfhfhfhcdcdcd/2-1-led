#ifndef __DS1302_H__
#define __DS1302_H__

extern unsigned char DS1302_Time[] ;
void DS1302_ReadTime(void);
void DS1302_SetTime(void);
unsigned char DS1302_ReadData(unsigned char Command);
void DS1302_WriteByte(unsigned char Command, unsigned char Data);
void DS1302_Init(void);


#endif 