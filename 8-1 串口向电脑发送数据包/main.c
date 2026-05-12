#include "regx52.h"
#include "delay.h"

void UART_Init(void)
{
    // 1. 设置串口工作模式（方式1，允许接收）
    SCON = 0x50;   // SM0=0, SM1=1, REN=1

    // 2. 配置定时器1为模式2（8位自动重装）
    TMOD &= 0x0F;  // 保留定时器0设置，清零定时器1的高4位
    TMOD |= 0x20;  // 设置定时器1模式2 (0010 0000)

    // 3. 设置波特率重装值
    TH1 = 0xF3;    // 243
    TL1 = 0xF3;

    // 4. 波特率倍增 (SMOD=1)
    PCON |= 0x80;  // 设置 PCON 的最高位

    // 5. 启动定时器1
    TR1 = 1;

    // 6. 禁止串口中断（查询方式）
    ES = 0;
    EA = 0;        // 如果其他地方也没有用到中断，可不写

    // 7. 清除标志位（避免上电后立即误判）
    TI = 0;
    RI = 0;

}

void UART_SendByte(unsigned char Byte)
{
    SBUF = Byte;
    while (!TI);
    TI = 0;
}

void main()
{
    
    
    unsigned char byte = 0x00;
    P2 = 0x00;
    UART_Init();
    while (1)
    {
        
        UART_SendByte(byte);
        Delay(100);
        byte++;
    }
}