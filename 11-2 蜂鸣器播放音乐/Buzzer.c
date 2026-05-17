#include <regx52.h>
#include "Buzzer.h"
#include "delay.h"

//蜂鸣器端口
sbit Buzzer = P2 ^ 5;
unsigned int i;
/**
  * @brief: 蜂鸣器发声函数
  * @param:想让蜂鸣器发声的时间。想让它发生100毫秒，里面的参数还得乘个2，因为里面调用的是五百微秒的函数
  * @retval:无
  */
void Buzzer_Time(unsigned int ms)
{
    for (i = 0;i < 2*ms;i++)
    {
        Buzzer = !Buzzer;
        Delay500us(1);
    }
}