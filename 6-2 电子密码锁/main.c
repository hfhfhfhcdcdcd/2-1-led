#include <regx52.h>
#include "delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

void main()
{
    unsigned char KeyNum1 = 0;
    unsigned char KeyNum2 = 0;   
    unsigned char KeyNum3 = 0;   
    unsigned char KeyNum4 = 0;       
    LCD_Init();
    LCD_ShowString(1, 1, "PassWord:");
    
    while (1)
    {
        KeyNum1 = MatrixKey();        
        KeyNum2 = MatrixKey();
        KeyNum3 = MatrixKey();
        KeyNum4 = MatrixKey();
        
        if ((KeyNum1) || (KeyNum2) || (KeyNum3) || (KeyNum4))
        {
            LCD_ShowNum(2, 1, KeyNum1, 1);
            LCD_ShowNum(2, 2, KeyNum2, 1);
            LCD_ShowNum(2, 3, KeyNum3, 1);
            LCD_ShowNum(2, 4, KeyNum4, 1);
        }
        
        
    }
}
	