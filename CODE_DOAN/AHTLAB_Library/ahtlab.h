#ifndef _AHTLAB_H
#define _AHTLAB_H

#include "STM32F4xx.h"

#define TRUE 						(1)
#define FALSE						(0)

#define PORTLed				GPIOD
#define PORTButton		GPIOE
#define Led1					GPIO_Pin_12	
#define Led2					GPIO_Pin_13	
#define Led3					GPIO_Pin_14
#define Led4					GPIO_Pin_15
#define Buzzer				GPIO_Pin_11
#define UserButton		GPIO_Pin_2	
#define UserButton1		GPIO_Pin_3	

#define PORTCB				GPIOA

#define CB1					GPIO_Pin_4	
#define CB2					GPIO_Pin_5	
#define CB3					GPIO_Pin_6
#define CB4					GPIO_Pin_7

#define PORTUART2			GPIOA
#define UART2_TX			GPIO_Pin_2
#define UART2_RX			GPIO_Pin_3

#define PORTUART1			GPIOA
#define UART1_TX			GPIO_Pin_9
#define UART1_RX			GPIO_Pin_10

#define PORTUART3			GPIOB
#define UART3_TX			GPIO_Pin_10
#define UART3_RX			GPIO_Pin_11

#define PORTSPI				GPIOA
#define PORT_CS				GPIOE
#define SPI1_MOSI			GPIO_Pin_7
#define SPI1_MISO			GPIO_Pin_6
#define SPI1_SCK			GPIO_Pin_5
#define F_CS					GPIO_Pin_3

#define W25QXX_CS(n)	GPIO_WriteBit(PORT_CS,F_CS,n)



#endif
