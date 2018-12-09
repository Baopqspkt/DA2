#include "usbd_usr.h" 
#include "usb_dcd_int.h"
#include <stdio.h> 
#include <uart.h> 
//////////////////////////////////////////////////////////////////////////////////	 
 
//USBD-USR ����	   
//STM32F4����ģ��-�⺯���汾
//�Ա����̣�http://mcudev.taobao.com							  
//*******************************************************************************
//�޸���Ϣ
//��
////////////////////////////////////////////////////////////////////////////////// 	   

//��ʾUSB����״̬
//0,û������;
//1,�Ѿ�����;
vu8 bDeviceState=0;		//Ĭ��û������  


extern USB_OTG_CORE_HANDLE  USB_OTG_dev;

//USB OTG �жϷ�����
//��������USB�ж�
void OTG_FS_IRQHandler(void)
{
  	USBD_OTG_ISR_Handler(&USB_OTG_dev);
}  
//ָ��DEVICE_PROP�ṹ��
//USB Device �û��ص�����. 
USBD_Usr_cb_TypeDef USR_cb =
{
  USBD_USR_Init,
  USBD_USR_DeviceReset,
  USBD_USR_DeviceConfigured,
  USBD_USR_DeviceSuspended,
  USBD_USR_DeviceResumed,
  USBD_USR_DeviceConnected,
  USBD_USR_DeviceDisconnected,    
};
//USB Device �û��Զ����ʼ������
void USBD_USR_Init(void)
{
	//myprintf("USBD_USR_Init\r\n");
} 
//USB Device ��λ
//speed:USB�ٶ�,0,����;1,ȫ��;����,����.
void USBD_USR_DeviceReset (uint8_t speed)
{
	switch (speed)
	{
		case USB_OTG_SPEED_HIGH:
			myprintf("USB Device Library v1.1.0  [HS]\r\n");
			break; 
		case USB_OTG_SPEED_FULL: 
			myprintf("USB Device Library v1.1.0  [FS]\r\n");
			break;
		default:
			myprintf("USB Device Library v1.1.0  [??]\r\n"); 
			break;
	}
}
//USB Device ���óɹ�
void USBD_USR_DeviceConfigured (void)
{
	myprintf("MSC Interface started.\r\n"); 
} 
//USB Device����
void USBD_USR_DeviceSuspended(void)
{
	myprintf("Device In suspend mode.\r\n");
} 
//USB Device�ָ�
void USBD_USR_DeviceResumed(void)
{ 
	myprintf("Device Resumed\r\n");
}
//USB Device���ӳɹ�
void USBD_USR_DeviceConnected (void)
{
	bDeviceState=1;
	myprintf("USB Device Connected.\r\n");
}
//USB Deviceδ����
void USBD_USR_DeviceDisconnected (void)
{
	bDeviceState=0;
	myprintf("USB Device Disconnected.\r\n");
} 

















