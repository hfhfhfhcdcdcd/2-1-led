#include <regx52.h>
#include "delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"
#include "Timer0.h"

unsigned int miao = 55;
unsigned int fen = 59;
unsigned int shi = 0;
void main()
{
    Timer0Init();
    LCD_Init();
    LCD_ShowString(1, 1, "Clock:");
    LCD_ShowString(2, 1, "  :  :");
    while (1)
    {      
        LCD_ShowNum(2, 1, shi, 2);
        LCD_ShowNum(2, 4, fen, 2);
        LCD_ShowNum(2, 7, miao, 2);
    }
}  


void Timer0_Rountine() interrupt 1
{
    static unsigned int T0Count;
    TH0 = 0xFC;
    TL0 = 0x18;
    T0Count ++;
    
    if (T0Count == 1000)
    {
        T0Count = 0;
        miao++;
        if (miao==60)
        {
            fen++;
            miao = 0;
            if (fen == 60)
            {
                shi++;
                fen = 0;
                if (shi == 24)
                {
                    shi = 0;
                }
            }
        }
    }
}