#ifndef __DHT11_H
#define __DHT11_H

#include "mylib.h"

/**************************** KHAI BAO BIEN ****************************/
typedef struct
{
	uint8_t temp_int ;		//so nguyen nhiet do
	uint8_t temp_deci ; 	//so thap phan
	uint8_t humi_int ; 	//So nguyen cua do am
	uint8_t humi_deci ;	//sau so thap phan
	uint8_t check_sum ;  // sum tong
} DHT11_DATA_TypeDef ;

/********************************* DHT11 Define port connect ********************************/
#define			GPIO_DHT11_CLK			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
#define			GPIO_DHT11_PORT			GPIOA						
#define			GPIO_DHT11_PIN			GPIO_Pin_8 

/********************************* DHT11 define huong vao ra**************************************/
#define			DHT11_DOUT_0			GPIO_WriteBit(GPIO_DHT11_PORT,GPIO_DHT11_PIN,Bit_RESET)
#define 		DHT11_DOUT_1			GPIO_WriteBit(GPIO_DHT11_PORT,GPIO_DHT11_PIN,Bit_SET)
#define 		DHT11_DATA_IN()		GPIO_ReadInputDataBit(GPIO_DHT11_PORT,GPIO_DHT11_PIN)

/*********************************KHAI BAO HAM CON *************************************/
void DHT11_Init(void) ;

uint8_t Read_TempAndHumidity (DHT11_DATA_TypeDef *DHT11_DATA) ;

#endif 						
	
