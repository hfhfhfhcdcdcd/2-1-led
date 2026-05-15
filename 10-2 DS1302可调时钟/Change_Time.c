#include "key.h"
#include "delay.h"
#include "lcd1602.h"
#include "DS1302.h"
#include "regx52.h"

unsigned char  KeyNum, MODE, Count;

void Time_Show(void)
{
  LCD_ShowNum(1, 1,    DS1302_Time[0], 2);
  LCD_ShowNum(1, 4,    DS1302_Time[1], 2);
  LCD_ShowNum(1, 7,    DS1302_Time[2], 2);
  LCD_ShowNum(1, 10,   DS1302_Time[6], 2);//星期

  LCD_ShowNum(2, 1,    DS1302_Time[3], 2);//时
  LCD_ShowNum(2, 4,    DS1302_Time[4], 2);//分
  LCD_ShowNum(2, 7,    DS1302_Time[5], 2);//秒
}


void Time_Set(void)
{
  KeyNum = Key();
  switch (KeyNum)
  {
    case 2:
      Count++;
      Count %= 7;P2 = 0x00;
      break;
    case 3:
      DS1302_Time[Count]++;
      if (DS1302_Time[0] > 99)//年
      {
        DS1302_Time[0] = 1;
      }
      else if (DS1302_Time[1] > 12)//月
      {
        DS1302_Time[1] = 1;
      }
      else if ((DS1302_Time[1] == 1) || (DS1302_Time[1] == 3) || (DS1302_Time[1] == 5) || (DS1302_Time[1] == 7) || (DS1302_Time[1] == 8) || (DS1302_Time[1] == 10) || (DS1302_Time[1] == 12))
      {
        if (DS1302_Time[2] > 31)//日
            {
              DS1302_Time[2] = 1;
            }
      }
      else if ((DS1302_Time[1] == 4) || (DS1302_Time[1] == 6) || (DS1302_Time[1] == 9) || (DS1302_Time[1] == 11))
      {
        if (DS1302_Time[2] > 30)//日
            {
              DS1302_Time[2] = 1;
            }
      }
      else if (DS1302_Time[1] == 2)
      {
        if ((DS1302_Time[0]/4)==0)
        {
          if (DS1302_Time[2] > 29)//日
            {
              DS1302_Time[2] = 1;
            }
        }
        else 
        {
          if (DS1302_Time[2] > 28)//日
            {
              DS1302_Time[2] = 1;
            }
        }
      }
      else if (DS1302_Time[3] > 23)//时
      {
        DS1302_Time[3] = 0;
      }
      else if (DS1302_Time[4] > 59)// 分
      {
        DS1302_Time[4] = 0;
      }
      else if (DS1302_Time[5] > 59)//秒
      {
        DS1302_Time[1] = 0;
      }
      else if (DS1302_Time[6] > 7)//星期
      {
        DS1302_Time[6] = 1;
      }
      break;
    case 4:
      DS1302_Time[Count]--;
      if (DS1302_Time[0] < 1)//年
      {
        DS1302_Time[0] = 1;
      }
      else if (DS1302_Time[1] < 1)//月
      {
        DS1302_Time[1] = 1;
      }
      else if (DS1302_Time[2] < 1)//日
      {
        DS1302_Time[2] = 1;
      }
      else if (DS1302_Time[3] < 0)//时
      {
        DS1302_Time[3] = 0;
      }
      else if (DS1302_Time[4] < 0)// 分
      {
        DS1302_Time[4] = 0;
      }
      else if (DS1302_Time[5] < 0)//秒
      {
        DS1302_Time[1] = 0;
      }
      else if (DS1302_Time[6] < 1)//星期
      {
        DS1302_Time[6] = 7;
      }
      break;
    default:break;
  }
}

// void change(void)
// {
  
// }