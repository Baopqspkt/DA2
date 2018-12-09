#include "mylib.h"


void USART2_Config(void)
{
    // Enable clock for GPIOA
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    // Enable clock for USART2
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

    // Connect PA6 to USART2_Tx
    GPIO_PinAFConfig(PORTUART2, GPIO_PinSource2, GPIO_AF_USART2);
    // Connect PA7 to USART2_Rx
    GPIO_PinAFConfig(PORTUART2, GPIO_PinSource3, GPIO_AF_USART2);

    // Initialization of GPIOA
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = UART2_TX | UART2_RX;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(PORTUART2, &GPIO_InitStruct);

    // Initialization of USART2
    USART_InitTypeDef USART_InitStruct;
    USART_InitStruct.USART_BaudRate = 115200;
    USART_InitStruct.USART_HardwareFlowControl =
            USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStruct.USART_Parity = USART_Parity_No;
    USART_InitStruct.USART_StopBits = USART_StopBits_1;
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;
    USART_Init(USART2, &USART_InitStruct);

    // Enable USART2
    USART_Cmd(USART2, ENABLE);
}

void USART2_PutChar(char c)
{
    // Wait until transmit data register is empty
    while (!USART_GetFlagStatus(USART2, USART_FLAG_TXE));
    // Send a char using USART2
    USART_SendData(USART2, c);
}

void USART2_PutString(char *s)
{
    // Send a string
    while (*s)
    {
        USART2_PutChar(*s++);
    }
}

uint16_t USART2_GetChar()
{
    // Wait until data is received
    while (!USART_GetFlagStatus(USART2, USART_FLAG_RXNE));
    // Read received char
    return USART_ReceiveData(USART2);
}
///////////////////////////////////////////////////
//UART3
void USART3_Config(void)
{
    // Enable clock for GPIOB
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    // Enable clock for USART3
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

    // Connect PB10 to USART3_Tx
    GPIO_PinAFConfig(PORTUART3, GPIO_PinSource10, GPIO_AF_USART3);
    // Connect PB11 to USART3_Rx
    GPIO_PinAFConfig(PORTUART3, GPIO_PinSource11, GPIO_AF_USART3);

    // Initialization of GPIOB
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = UART3_TX | UART3_RX;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(PORTUART3, &GPIO_InitStruct);

    // Initialization of USART3
    USART_InitTypeDef USART_InitStruct;
    USART_InitStruct.USART_BaudRate = 9600;
    USART_InitStruct.USART_HardwareFlowControl =
            USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStruct.USART_Parity = USART_Parity_No;
    USART_InitStruct.USART_StopBits = USART_StopBits_1;
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;
    USART_Init(USART3, &USART_InitStruct);

    // Enable USART3
    USART_Cmd(USART3, ENABLE);
}

void USART3_PutChar(char c)
{
    // Wait until transmit data register is empty
    while (!USART_GetFlagStatus(USART3, USART_FLAG_TXE));
    // Send a char using USART2
    USART_SendData(USART3, c);
}

void USART3_PutString(char *s)
{
    // Send a string
    while (*s)
    {
        USART3_PutChar(*s++);
    }
}

uint16_t USART3_GetChar()
{
    // Wait until data is received
    //while (!USART_GetFlagStatus(USART3, USART_FLAG_RXNE));
    // Read received char
    return USART_ReceiveData(USART3);
}
