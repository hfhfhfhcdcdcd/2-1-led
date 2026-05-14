#include "regx52.h"
#include "LCD1602.h"
#include "DS1302.h"



void main()
{
    LCD_Init();
    DS1302_Init();
    // LCD_ShowString(1, 1, "RTC");
    DS1302_SetTime();
   
    while (1)
    {
        DS1302_ReadTime();
        LCD_ShowString(1, 1, "Ye");
        LCD_ShowString(1, 3, "Mo");
        LCD_ShowString(1, 5, "Da");
        LCD_ShowString(1, 7, "SU");
        LCD_ShowNum(2, 1, DS1302_Time[0], 2);
        LCD_ShowNum(2, 3,  DS1302_Time[1],2);
        LCD_ShowNum(2, 5, DS1302_Time[2], 2);
        LCD_ShowNum(2, 7, DS1302_Time[6], 2);
        LCD_ShowString(1, 10, "Ho");
        LCD_ShowString(1, 13, "Mi");
        LCD_ShowString(1, 15, "Se");
        LCD_ShowNum(2, 10, DS1302_Time[3], 2);//时
        LCD_ShowNum(2, 13, DS1302_Time[4],2);//分
        LCD_ShowNum(2, 15,  DS1302_Time[5],2);//秒
        
    }
}