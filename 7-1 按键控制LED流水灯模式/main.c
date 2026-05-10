#include <regx52.h>
#include "delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"
#include "Timer0.h"
#include "key.h"
#include <INTRINS.h>

unsigned char KeyNumber, LEDMode;
unsigned int miao = 56;
unsigned int fen = 59;
unsigned int shi = 0;
void main()
{
    // P2 = 0xfe;
    LCD_Init();
    Timer0Init();
    while (1)
    {
        // KeyNumber = Key();
        // if (KeyNumber == 1) LEDMode = 1;
        // if (KeyNumber == 2) LEDMode = 2;
        
        // if (KeyNumber == 3) P2_2 = ~P2_2;
        // if (KeyNumber == 4) P2_3 = ~P2_3;
        LCD_ShowString(1, 1, "Clock:");

        LCD_ShowNum(2, 1, shi, 2);
        LCD_ShowString(2, 3, ":");

        LCD_ShowNum(2, 4, fen, 2);
        LCD_ShowString(2, 6, ":");

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
        }
        if (fen == 60)
        {
            shi++;
            fen = 0;
        }
        if (shi == 24)
        {
            shi = 0;
        }
        // if (LEDMode == 1) { P2 = _crol_(P2, 1); }
        // if (LEDMode == 2) { P2 = _cror_(P2, 1); }
        
    }
}