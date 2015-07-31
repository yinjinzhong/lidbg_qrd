#ifndef __DSI83_H__
#define __DSI83_H__


#define DSI83_DELAY_TIME	(0)
#define 	PANEL_GPIO_RESET       (25)
#define 	DSI83_GPIO_EN          (58)
#define 	DSI83_I2C_ADDR	       (0x2d)
#define T123_GPIO_RST          (28)
#define T123_RESET do{  \
	gpio_tlmm_config(T123_GPIO_RST, 0, GPIO_OUTPUT, GPIO_NO_PULL,GPIO_8MA, GPIO_ENABLE);\
	gpio_set_value(T123_GPIO_RST, 0);\
	mdelay(300);\
	gpio_tlmm_config(T123_GPIO_RST, 0, GPIO_OUTPUT, GPIO_NO_PULL,GPIO_8MA, GPIO_ENABLE);\
	gpio_set_value(T123_GPIO_RST, 1);\
	mdelay(30);\
	}while(0)
#define LCD_RESET do{  \
	gpio_tlmm_config(PANEL_GPIO_RESET, 0, GPIO_OUTPUT, GPIO_NO_PULL,GPIO_8MA, GPIO_ENABLE);\
	gpio_set_value(PANEL_GPIO_RESET, 0);\
	mdelay(20);\
	gpio_tlmm_config(PANEL_GPIO_RESET, 0, GPIO_OUTPUT, GPIO_NO_PULL,GPIO_8MA, GPIO_ENABLE);\
	gpio_set_value(PANEL_GPIO_RESET, 1);\
	mdelay(30);\
	}while(0)

#ifndef TEST_PATTERN
char dsi83_conf[] =
{
0x09, 0x00,
0x0A, 0x03,
0x0B, 0x20,
0x0D, 0x00,
0x10, 0x36,
0x11, 0x00,
0x12, 0x31,
0x13, 0x00,
0x18, 0x78,
0x19, 0x00,
0x1A, 0x03,
0x1B, 0x00,
0x20, 0x00,
0x21, 0x04,
0x22, 0x00,
0x23, 0x00,
0x24, 0x00,
0x25, 0x00,
0x26, 0x00,
0x27, 0x00,
0x28, 0xf9,
0x29, 0x00,
0x2A, 0x00,
0x2B, 0x00,
0x2C, 0x08,
0x2D, 0x00,
0x2E, 0x00,
0x2F, 0x00,
0x30, 0x03,
0x31, 0x00,
0x32, 0x00,
0x33, 0x00,
0x34, 0x2e,
0x35, 0x00,
0x36, 0x00,
0x37, 0x00,
0x38, 0x00,
0x39, 0x00,
0x3A, 0x00,
0x3B, 0x00,
0x3C, 0x00,
0x3D, 0x00,
0x3E, 0x00,
0xff
};
#else
char dsi83_conf[] =    //dsi83 test mode
{
0x09, 0x00,
0x0A, 0x03,
0x0B, 0x10,
0x0D, 0x00,
0x10, 0x26,
0x11, 0x00,
0x12, 0x19,
0x13, 0x00,
0x18, 0x78,
0x19, 0x00,
0x1A, 0x03,
0x1B, 0x00,
0x20, 0x00,
0x21, 0x04,
0x22, 0x00,
0x23, 0x00,
0x24, 0x58,
0x25, 0x02,
0x26, 0x00,
0x27, 0x00,
0x28, 0x21,
0x29, 0x00,
0x2A, 0x00,
0x2B, 0x00,
0x2C, 0x08,
0x2D, 0x00,
0x2E, 0x00,
0x2F, 0x00,
0x30, 0x03,
0x31, 0x00,
0x32, 0x00,
0x33, 0x00,
0x34, 0x2e,
0x35, 0x00,
0x36, 0x06,
0x37, 0x00,
0x38, 0x32,
0x39, 0x00,
0x3A, 0x06,
0x3B, 0x00,
0x3C, 0x10,
0x3D, 0x00,
0x3E, 0x00,
0xff
};
#endif


#endif

