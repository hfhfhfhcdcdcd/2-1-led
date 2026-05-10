#include <regx52.h>
#include "delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

void main()
{
    unsigned char KeyNum = 0;
    unsigned int PassWord;
    LCD_Init();
    LCD_ShowString(1, 1, "PassWord:");
    
    while (1)
    {
        KeyNum = MatrixKey();
        if (KeyNum)
        {
            if (KeyNum <= 10)
            {
                PassWord = KeyNum % 10;
            }
                LCD_ShowNum(2, 1, PassWord, 2);
        }
        
        
    }
}
	