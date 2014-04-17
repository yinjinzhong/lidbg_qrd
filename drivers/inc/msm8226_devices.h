

#ifndef _DEV_SOC__
#define _DEV_SOC__

void lidbg_device_main(int argc, char **argv);

//led
#define LED_GPIO  (60)
#define LED_ON  do{SOC_IO_Output(0, LED_GPIO, 0); }while(0)
#define LED_OFF  do{SOC_IO_Output(0, LED_GPIO, 1); }while(0)

//ad
#define AD_KEY_PORT   (0xff)

//button
#define BUTTON_LEFT_1 (31)//k1
#define BUTTON_LEFT_2 (32)//k2
#define BUTTON_RIGHT_1 (33)//k3
#define BUTTON_RIGHT_2 (34)//k4
//USB
#define GPIO_USB_ID (99)  // error ,notice!

#define USB_ID_HIGH_DEV do{\
								SOC_IO_Config(GPIO_USB_ID,GPIO_CFG_INPUT,GPIO_CFG_PULL_UP,GPIO_CFG_16MA);\
								SOC_IO_Output(0,GPIO_USB_ID,1);\
							}while(0)
#define USB_ID_LOW_HOST do{  \
								SOC_IO_Config(GPIO_USB_ID,GPIO_CFG_OUTPUT,GPIO_CFG_NO_PULL,GPIO_CFG_16MA);\
								SOC_IO_Output(0, GPIO_USB_ID, 0);\
							}while(0)

// PANNE_PEN , RESET
#define LCD_ON  do{    \
			u8 buff[] = {0x02, 0x0d, 0x1};\
			lidbg("LCD_ON\n");\
			SOC_LPC_Send(buff, SIZE_OF_ARRAY(buff));\
					}while(0)
	
#define LCD_OFF   do{   \
			u8 buff[] = {0x02, 0x0d, 0x0};\
			lidbg("LCD_OFF\n");\
			SOC_LPC_Send(buff, SIZE_OF_ARRAY(buff));\
					}while(0)
#endif