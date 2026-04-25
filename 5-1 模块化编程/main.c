#include <regx52.h>
#include "Delay.h"

void main()
{
    while (1)
    {
        Delay(500);
        P2=0xfe;
        Delay(700);
        P2=0xff;
    }
}