#include <regx52.h>
#include "delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"
#include "Timer0.h"
#include "key.h"

unsigned char KeyNumber;
void main()
{
    // Timer0Init();
    while (1)
    {
        KeyNumber = Key();
        if (KeyNumber == 1) P2_0 = ~P2_0;
        if (KeyNumber == 2) P2_1 = ~P2_1;
        if (KeyNumber == 3) P2_2 = ~P2_2;
        if (KeyNumber == 4) P2_3 = ~P2_3;
    }
}


// void Timer0_Rountine() interrupt 1
// {
//     static unsigned int T0Count;
//     TH0 = 0xFC;
//     TL0 = 0x18;
//     T0Count ++;
//     if (T0Count == 1000)
//     {
//         P2_0 = ~P2_0;
//         T0Count = 0;
//     }
// }