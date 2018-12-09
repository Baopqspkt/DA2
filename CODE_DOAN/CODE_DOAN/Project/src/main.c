#include "mylib.h"
GPIO_InitTypeDef GPIO_InitStructure;

	
void init_GPIO(void);
void ReceviceData(void);
void Checkled(void);


uint8_t data = 0,dht;
uint8_t nd,dam;

void SysTick_Handler()
{
	TimingDelay_Decrement();
}

void init_GPIO()
{

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	
  
  GPIO_InitStructure.GPIO_Pin = Led1|Led2|Led3|Led4|Buzzer;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(PORTLed, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = CB1|CB2|CB3|CB4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(PORTCB, &GPIO_InitStructure);
}

void ReceviceData()
{
	data = USART3_GetChar();
	switch(data)
	{
		case 0x01:{GPIO_ResetBits(PORTLed,Led1); break; }
		case 0x11:{GPIO_SetBits(PORTLed,Led1); break; }
		case 0x02:{GPIO_ResetBits(PORTLed,Led2); break; }
		case 0x12:{GPIO_SetBits(PORTLed,Led2); break; }
		case 0x03:{GPIO_ResetBits(PORTLed,Led3); break; }
		case 0x13:{GPIO_SetBits(PORTLed,Led3); break; }
		case 0x04:{GPIO_ResetBits(PORTLed,Led4); break; }
		case 0x14:{GPIO_SetBits(PORTLed,Led4); break; }
		case 0x98:{GPIO_ResetBits(PORTLed,Buzzer); break; }
		case 0x99:{GPIO_SetBits(PORTLed,Buzzer); break; }
		default: {GPIO_ResetBits(PORTLed,Buzzer); 
							GPIO_ResetBits(PORTLed,Led1);
							GPIO_ResetBits(PORTLed,Led2);
							GPIO_ResetBits(PORTLed,Led3);
							GPIO_ResetBits(PORTLed,Led4);
							break;}
	}
}
////////////////////////////////////////////////////////
void Checkled()
{
	if (GPIO_ReadInputDataBit(PORTCB,CB1)==1)
		myprintf3("den1.val=1");
	else
		myprintf3("den1.val=0");
	if (GPIO_ReadInputDataBit(PORTCB,CB2)==1)
		myprintf2("den2.val=1");
	else
		myprintf3("den2.val=0");
	if (GPIO_ReadInputDataBit(PORTCB,CB3)==1)
		myprintf3("den3.val=1");
	else
		myprintf3("den3.val=0");
	if (GPIO_ReadInputDataBit(PORTCB,CB4)==1)
		myprintf3("den4.val=1");
	else
		myprintf3("den4.val=0");
	
}


int main(){
	
	CLOCK_SetClockTo168MHz();
	SystemCoreClockUpdate();                      /* Get Core Clock Frequency   */
  if (SysTick_Config(SystemCoreClock / 1000)) { /* SysTick 1 msec interrupts  */
    while (1);                                  /* Capture error              */
  }
	DHT11_DATA_TypeDef DHT11_DATA ;
	Init_timer2();
	Init_timer3();
	init_GPIO();
	USART2_Config();	
	USART3_Config();	
	DHT11_Init();
	myprintf2("\r\n check DTH11\r\n") ;
	while(1)
		{
			if(dht > 5){
				dht = 0;
			GPIO_ToggleBits(PORTLed,Led1);
			if(Read_TempAndHumidity ( & DHT11_DATA)==SUCCESS)
					myprintf2("%d,%d",nd,dam);	
			else
					myprintf2("error");}	
		}
	}

