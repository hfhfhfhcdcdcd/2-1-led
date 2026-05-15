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
        // Time_Show();
        KeyNum = Key();
        switch (KeyNum)
        {
        case 1:
            if (MODE == 0) { MODE = 1;Time_Set();}
            else if (MODE = 1) { MODE == 0; Time_Show(); }
            break;
        default:Time_Show();break;
  }

          
    }
}