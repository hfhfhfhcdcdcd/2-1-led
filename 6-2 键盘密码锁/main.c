#include <regx52.h>
#include "delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

void main()
{
    unsigned char KeyNum = 0;
    unsigned int PassWord,Count;
    LCD_Init();
    LCD_ShowString(1, 1, "PassWord:");
    
    while (1)
    {
        KeyNum = MatrixKey();
        if (KeyNum)
        {
            if (KeyNum <= 10)//判断1-10按键是否按下
            {
                if (Count < 4)
                {
                    PassWord *= 10;//密码左移一位，以便存储下一位密码
                    PassWord += KeyNum % 10;//获取一位密码,其中10取余之后变成零所以密码一共是0到9
                    Count++;
                    LCD_ShowNum(2, 1, PassWord, 4);//更新显示密码
                }

            }
                
        }
        
        
    }
}
	