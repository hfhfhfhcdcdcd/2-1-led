#include "regx52.h"
#include "LCD1602.h"
#include "DS1302.h"
#include "delay.h"
#include "key.h"
// #include "Change_Time.h"

unsigned char KeyNum,MODE,TimeSelect;

void TimeShow(void)
{
    DS1302_ReadTime();
    LCD_ShowNum(1, 1,    DS1302_Time[0], 2);
    LCD_ShowNum(1, 4,    DS1302_Time[1], 2);
    LCD_ShowNum(1, 7,    DS1302_Time[2], 2);
    LCD_ShowNum(1, 10,   DS1302_Time[6], 2);//星期
    LCD_ShowNum(2, 1,    DS1302_Time[3], 2);//时
    LCD_ShowNum(2, 4,    DS1302_Time[4], 2);//分
    LCD_ShowNum(2, 7,    DS1302_Time[5], 2);//秒
}

void TimeSet(void)
{
    if (KeyNum == 2)
    {
        TimeSelect++;
        TimeSelect %= 7;
    }
    
    if (KeyNum == 3)
    {
        DS1302_Time[TimeSelect]++;

        
        if (DS1302_Time[0] > 99)//年
        {
            DS1302_Time[0] = 1;
        }
        else if (DS1302_Time[1] > 12)//月
        {
            DS1302_Time[1] = 1;
        }
        /*31天的月份  的 溢出判断*/
        else if ((DS1302_Time[1] == 1) || (DS1302_Time[1] == 3) || (DS1302_Time[1] == 5) || (DS1302_Time[1] == 7) || (DS1302_Time[1] == 8) || (DS1302_Time[1] == 10) || (DS1302_Time[1] == 12))
        {
            if (DS1302_Time[2] > 31)//日
                {
                DS1302_Time[2] = 1;
                }
        }
        /*30天的月份  的 溢出判断*/
        else if ((DS1302_Time[1] == 4) || (DS1302_Time[1] == 6) || (DS1302_Time[1] == 9) || (DS1302_Time[1] == 11))
        {
            if (DS1302_Time[2] > 30)//日
                {
                DS1302_Time[2] = 1;
                }
        }
        /*2月份  的 溢出判断*/
        else if (DS1302_Time[1] == 2)
        {
            /*闰年2月份  的 溢出判断*/
            if ((DS1302_Time[0] / 4) == 0)
            {
            if (DS1302_Time[2] > 29)//日
                {
                DS1302_Time[2] = 1;
                }
            }
            /*平年2月份  的 溢出判断*/
            else
            {
                if (DS1302_Time[2] > 28)//日
                {
                    DS1302_Time[2] = 1;
                }
            }
        }  
        else if(DS1302_Time[6] > 7)//星期
        {
            P2 = 0x00;
            DS1302_Time[6] = 1;
        }
        else{}
        DS1302_SetTime();
    }

    if (KeyNum == 4)
    {
        DS1302_Time[TimeSelect]--;
        DS1302_SetTime();
    }
    switch (TimeSelect)
    {
    case 0:LCD_ShowString(2, 11, "Year  ");break;
    case 1:LCD_ShowString(2, 11, "Month ");break;
    case 2:LCD_ShowString(2, 11, "Day   ");break;
    case 3:LCD_ShowString(2, 11, "Hour  ");break;
    case 4:LCD_ShowString(2, 11, "Minute");break;
    case 5:LCD_ShowString(2, 11, "Second");break;
    case 6:LCD_ShowString(2, 11, "Xingqi");break;
    default:break;
    }
    
    LCD_ShowNum(1, 1,    DS1302_Time[0], 2);
    LCD_ShowNum(1, 4,    DS1302_Time[1], 2);
    LCD_ShowNum(1, 7,    DS1302_Time[2], 2);
    LCD_ShowNum(1, 10,   DS1302_Time[6], 2);//星期

    LCD_ShowNum(2, 1,    DS1302_Time[3], 2);//时
    LCD_ShowNum(2, 4,    DS1302_Time[4], 2);//分
    LCD_ShowNum(2, 7,    DS1302_Time[5], 2);//秒
}

void main()
{
    LCD_Init();
    DS1302_Init();
    LCD_ShowString(1, 14, "RTC");
    DS1302_SetTime();
    LCD_ShowString(1, 1, "  -  -  -");
    LCD_ShowString(2, 1, "  -  -");
    while (1)
    {
        KeyNum = Key();
        if (KeyNum==1)
        {
            if (MODE == 0) { MODE = 1; }
            else if (MODE == 1) { MODE = 0; }
        }
        switch (MODE)
        {
        case 0:TimeShow();break;
        case 1:TimeSet();break;
        default:break;
        } 
    }
}