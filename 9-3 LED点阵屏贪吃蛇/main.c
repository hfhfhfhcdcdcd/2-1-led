#include "regx52.h"
#include "delay.h"
#include "matrixled.h"
#include "stdlib.h"
#include "timer0.h"
#include "MatrixKey.h"

unsigned char RandNumColumn,RandNumRow, KeyNum;

unsigned char Random0_7(void)
{
    unsigned char Random1;
    Random1 = rand() % 8;
    return Random1;
}


void main()
{
    Timer0Init();
    MatrixLED_Init();
    while (1)
    {
        MatrixLED_ShowColum(RandNumColumn, (0x80>>RandNumRow));
    }
}

void Timer0_Rountine() interrupt 1
{
    // TH0 = 0xFC;
    // TL0 = 0x18;
    KeyNum = MatrixKey();
    if ((KeyNum == 11) || (KeyNum == 14) || (KeyNum == 15) || (KeyNum == 16))
    {
        srand(TL0);
        RandNumColumn = Random0_7();
        Delay(1);
        RandNumRow = Random0_7();
    }
}