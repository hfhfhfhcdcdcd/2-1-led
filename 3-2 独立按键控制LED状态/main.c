#include <regx52.h>

void Delay1ms(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
    while (xms)
    {
        i = 2;
        j = 239;
        do
        {
            while (--j);
        } while (--i);
        xms--;
    }
    
}

void main()
{
    while (1)
    {
        if (P3_1 == 0)
        {
            Delay1ms(20);
            while (P3_1 == 0);
            Delay1ms(20);
#ifndef P2_0_H
#define P2_0_H
            P2_0 = ~P2_0;
#endif
        }
        if (P3_1 == 0)
        {
            Delay1ms(20);
            while (P3_1 == 0);
            Delay1ms(20);
#ifndef P2_1_H
#define P2_1_H
            P2_1 = ~P2_1;
#endif
        }
    }
}