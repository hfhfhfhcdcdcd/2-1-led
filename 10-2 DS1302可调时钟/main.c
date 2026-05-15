#include "regx52.h"
#include "LCD1602.h"
#include "DS1302.h"
#include "delay.h"
#include "key.h"
#include "Change_Time.h"



void main()
{
    LCD_Init();
    DS1302_Init();
    LCD_ShowString(1, 14, "RTC");
    DS1302_SetTime();
   
    while (1)
    {
        DS1302_ReadTime();

    

          
    }
}