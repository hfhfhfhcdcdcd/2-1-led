#include <regx52.h>
#include "delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

void Timer0_Init()
{
    TMOD = 0x01;//0000 0001
    TF0 = 0;
    TR0 = 1;
    TH0 = 64535 / 256;
    TL0 = 64535 % 256;
    ET0 = 1;
    EA = 1;
    PT0 = 0;
}
void main()
{
    Timer0_Init();
    while (1)
    {
        
    }
}



unsigned int T0Count;
void Timer0_Rountine() interrupt 1
{
    TH0 = 64535 / 256;
    TL0 = 64535 % 256;
    T0Count++;
    if (T0Count == 1000)
    {
        P2_0 = 0;
        T0Count = 0;
    }
        

}