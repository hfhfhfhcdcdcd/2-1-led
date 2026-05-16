#include "regx52.h"
#include "delay.h"
#include "key.h"
#include "Nixie.h"
#include "Buzzer.h"


unsigned char KeyNum;

void main()
{
    Nixie(1, 0);
    while (1)
    {
        KeyNum = Key();
        if (KeyNum)
        {
            Buzzer_Time(70);
            Nixie(1, KeyNum);
        }

    }
}

