/**
 *
 *	@author 	Quoc Bao
 *	@email		baoqq.spkt@gmail.com
 *	@ide		Keil uVision 5
 */

#ifndef _UART_H
#define _UART_H

#include "mylib.h"
/////////////////////////
//UART2
void USART2_Config(void);
void USART2_PutChar(char c);
void USART2_PutString(char *s);
uint16_t USART2_GetChar(void);
////////////////////////////////
//UART3
void USART3_Config(void);
void USART3_PutChar(char c);
void USART3_PutString(char *s);
uint16_t USART3_GetChar(void);
#endif
