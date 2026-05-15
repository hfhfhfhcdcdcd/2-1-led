#include "regx52.h"
#include "LCD1602.h"
#include "DS1302.h"
#include "delay.h"
#include "key.h"



void main()
{
    LCD_Init();
    DS1302_Init();
    LCD_ShowString(1, 14, "RTC");
    DS1302_SetTime();
   
    while (1)
    {
        change();
        DS1302_ReadTime();

        LCD_ShowNum(1, 1,    DS1302_Time[0], 2);
        LCD_ShowNum(1, 4,    DS1302_Time[1], 2);
        LCD_ShowNum(1, 7,    DS1302_Time[2], 2);
        LCD_ShowNum(1, 10,   DS1302_Time[6], 2);//星期
  
        LCD_ShowNum(2, 1,    DS1302_Time[3], 2);//时
        LCD_ShowNum(2, 4,    DS1302_Time[4], 2);//分
        LCD_ShowNum(2, 7,    DS1302_Time[5], 2);//秒
        
    }
}