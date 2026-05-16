#include "regx52.h"
#include "LCD1602.h"
#include "DS1302.h"
#include "delay.h"
#include "key.h"
#include "Change_Time.h"
#include "timer0.h"
void main()
{
    LCD_Init();
    Timer0Init();
    DS1302_Init();
    DS1302_SetTime();//把事先准备好的时间数组写到DS1302上面
    LCD_ShowString(1, 14, "RTC");
    LCD_ShowString(1, 1, "  -  -  -");
    LCD_ShowString(2, 1, "  -  -");
    
    while (1)
    {
        KeyNum = Key();//从按键获取返回值,返回值为1234
        /*按键1按下去切换是显示还是设置*/
        TimeSet();
        /*显示的话调用TimeShow.设置的话调用TimeSet*/
        switch (MODE)
        {
        case 0:TimeShow();break;
        case 1:TimeSet();break;
        default:break;
        } 
    }
}

void Timer0_Rountine() interrupt 1
{
    static unsigned int T0Count;
    TH0 = 0xFC;
    TL0 = 0x18;
    T0Count++;
    if (T0Count == 500)
    {
        T0Count = 0;
        if (MODE == 1) { LCD_ShowString(1, 1, "  ");Delay(500); }
    }
        

}