#include <regx52.h>
#include "delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"
#include "Timer0.h"
#include "key.h"
#include <INTRINS.h>

unsigned char KeyNumber,LEDMode;
void main()
{
    P2 = 0xfe;
    Timer0Init();
    while (1)
    {
        KeyNumber = Key();
        if (KeyNumber == 1) LEDMode = 1;
        if (KeyNumber == 2) LEDMode = 2;
        
        // if (KeyNumber == 3) P2_2 = ~P2_2;
        // if (KeyNumber == 4) P2_3 = ~P2_3;
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
        if (LEDMode == 1) { P2 = _crol_(P2, 1); }
        if (LEDMode == 2) { P2 = _cror_(P2, 1); }
    }
}