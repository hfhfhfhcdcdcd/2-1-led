#include <regx52.h>
#include <intrins.h>

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
        P2 = 0xFE;
        Delay1ms(800);
        P2 = 0xFD;
        Delay1ms(700);
        P2 = 0xFB;
        Delay1ms(600);
        P2 = 0xF7;
        Delay1ms(500);
        P2 = 0xEF;
        Delay1ms(400);
        P2 = 0xDF;
        Delay1ms(300);
        P2 = 0xBF;
        Delay1ms(200);
        P2 = 0xF7F;
        Delay1ms(100);

    }
    
}