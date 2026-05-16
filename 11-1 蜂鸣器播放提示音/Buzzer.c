#include <regx52.h>
#include "Buzzer.h"
#include "delay.h"

sbit Buzzer = P2 ^ 5;
unsigned int i;
void Buzzer_Time(unsigned int ms)
{
    for (i = 0;i < ms;i++)
    {
        Buzzer = !Buzzer;
        Delay(1);
    }
}