#ifndef __TW9912_CONFIG_H__
#define __TW9912_CONFIG_H__

u8 TW9912_Stop[]=
	{
	0xff,0x00//page0
	,0x03,0x07//Output Control Register
//	,0x06,0x27//shut down
	,0xfe,
};
u8  TW9912_Shutd[]=
{
	0x06,0x27,//shut down
};

u8 TW9912_testing_signal[]=
{
	0x01,0xff,//Chip Status Register (CSTATUS) read only
			/*
				bit7 =1 Video not present.                       							bit7=0 Video detected
			    	bit6 =1 Horizontal sync PLL is locked to the incoming video source     bit6=0 Horizontal sync PLL is not locked
			    	bit5 =1 Sub-carrier PLL is locked to the incoming video source.          bit5 =0 Sub-carrier PLL is not locked
			    	bit4 =1 Even field is being decoded                                                           bit4 =0 Odd field is being decoded
			    	bit3 =1 Vertical logic is locked to the incoming video source                bit3 =0 c.
			    	bit2 Reserved
			    	bit1 =1 No color burst signal detected.  							bit1=0 Color burst signal detected.
				bit0 =1 50Hz source detected 									bit0=0 60Hz source detected
			*/
	0x1e,0xff,//Component Video Format (CVFMT) bit[4:6]read only
			/*
				Component video input format detection.
				bit[4:6]--> 0 = 480i 1 = 576i 2 = 480p 3 = 576p others = NA
			*/
};
 u8 TW9912_INIT_Public[]=
{
0xfe,0x0
,0xfe,
 };
 
u8 TW9912_INIT_AGAIN[]=
{
0x02,0x4C
,0x03,0x20
,0x05,0x1E
,0x06,0x03
,0x1E,0x18
,0x2F,0x24
,0x30,0x00
,0x34,0x1A
,0xC0,0x01
,0xC1,0xC7
,0xCB,0x30
,0xCD,0x54
,0xD8,0x00
,0xD9,0x04
,0xDA,0x80
,0xDB,0x80
,0xE1,0x49
,0xE3,0x00
,0xE4,0x00
,0xE5,0x00
,0xE6,0x00
,0xE8,0x3F
,0xE9,0x61
,0xfe,
};
 u8 TW9912_INIT_NTSC_Interlaced_input[]=
{
0x02,0x4C
,0x03,0x20
,0x04,0x00
,0x05,0x1E
,0x06,0x03
,0x07,0x02
,0x08,0x19
,0x09,0xf0
,0x0A,0x22
//,0x0B,0xdc
,0x0B,0xe4
,0x0C,0xCC
,0x0D,0x15
,0x12,0x1e

,0x10,0xfc

,0x17,0x34
,0x18,0x44
,0x1A,0x10
,0x1B,0x00
,0x1C,0x07
,0x1D,0x7F
,0x1E,0x08
,0x1F,0x00
,0x20,0x50
,0x21,0x42
,0x22,0xF0
,0x23,0xD8
,0x24,0xBC
,0x25,0xB8
,0x26,0x44
,0x27,0x38
,0x28,0x00
,0x29,0x00
,0x2A,0x78
,0x2B,0x44
,0x2C,0x30
,0x2D,0x14
,0x2E,0xA5
,0x2F,0x24
,0x30,0x00
,0x33,0x05
,0x34,0x1A
,0x35,0x00
,0x36,0xE8
,0x37,0x2D
,0x38,0x01
,0x40,0x00
,0x41,0x80
,0x42,0x00
,0xC0,0x01
,0xC1,0xC7
,0xC2,0x01
,0xC3,0x03
,0xC4,0x5A
,0xC5,0x00
,0xC6,0x20
,0xC7,0x04
,0xC8,0x00
,0xC9,0x06
,0xCA,0x06
,0xCB,0x30
,0xCC,0x00
,0xCD,0x54
,0xD0,0x00
,0xD1,0xF0
,0xD2,0xF0
,0xD3,0xF0
,0xD4,0x00
,0xD5,0x00
,0xD6,0x10
,0xD7,0x70
,0xD8,0x00
,0xD9,0x04
,0xDA,0x80
,0xDB,0x80
,0xDC,0x20
,0xE0,0x00
,0xE1,0x49
,0xE2,0xD9
,0xE3,0x00
,0xE4,0x00
,0xE5,0x00
,0xE6,0x00
,0xE7,0x2A
,0xE8,0x3F
,0xE9,0x61
,0xfe,
};
 u8 TW9912_INIT_NTSC_Progressive_input[]=
{
0xff,0x00//page0
,0x06,0x10
,0x06,0x10
,0x06,0x10
,0x06,0x10
,0x02,0x70
,0x03,0x20
,0x05,0x20
,0x07,0x11
,0x08,0x1B
,0x09,0xEE
,0x0A,0x09
,0x0B,0x80
,0x11,0x80
,0x1E,0x02
,0x37,0x2A
,0x38,0x5D
,0xC0,0x10
,0xC2,0xD2
,0xC3,0x06
,0xC4,0xB4
,0xC5,0x10
,0xC6,0x32
,0x06,0x00
,0xCB,0xD0
,0xCC,0x40
,0xD7,0x50
,0xD9,0x10
,0xE1,0x45
,0xE2,0xDA
,0xE6,0x02
,0xE8,0x00
,0xE9,0xA0
,0x07,0x11
,0x09,0xEE
,0x0A,0x09
,0x06,0x00
,0xCB,0xD0
,0xfe,
};
u8 TW9912_INIT_PAL_Interlaced_input[]=
{
0x02,0x4C
,0x03,0x20
,0x04,0x00
,0x05,0x1E
,0x06,0x03
,0x07,0x12
,0x08,0x12
,0x09,0x27  
,0x0A,0x1b
,0x0B,0xe0
,0x0C,0xCC
,0x0D,0x15


,0x12,0xf0

,0x15,0x00
,0x15,0x00
,0x17,0x33
,0x18,0x44
,0x1A,0x10
,0x1B,0x00
,0x1C,0x17
,0x1D,0x7F
,0x1E,0x18
,0x1F,0x00
,0x20,0x50
,0x21,0x42
,0x22,0xF0
,0x23,0xD8
,0x24,0xBC
,0x25,0xB8
,0x26,0x44
,0x27,0x38
,0x28,0x00
,0x29,0x00
,0x2A,0x78
,0x2B,0x44
,0x2C,0x30
,0x2D,0x14
,0x2E,0xA5
,0x2F,0x24
,0x30,0x00
,0x33,0x05
,0x34,0x1A
,0x35,0x00
,0x36,0xE8
,0x37,0x2D
,0x38,0x01
,0x40,0x00
,0x41,0x80
,0x42,0x00
,0xC0,0x01
,0xC1,0xC7
,0xC2,0x01
,0xC3,0x03
,0xC4,0x5A
,0xC5,0x00
,0xC6,0x20
,0xC7,0x04
,0xC8,0x00
,0xC9,0x06
,0xCA,0x06
,0xCB,0x30
,0xCC,0x00
,0xCD,0x54
,0xD0,0x00
,0xD1,0xF0
,0xD2,0xF0
,0xD3,0xF0
,0xD4,0x00
,0xD5,0x00
,0xD6,0x10
,0xD7,0x70
,0xD8,0x00
,0xD9,0x04
,0xDA,0x80
,0xDB,0x80
,0xDC,0x20
,0xE0,0x00
,0xE1,0x49
,0xE2,0xD9
,0xE3,0x00
,0xE4,0x00
,0xE5,0x00
,0xE6,0x00
,0xE7,0x2A
,0xE8,0x3F
,0xE9,0x61
,0xfe,
};
u8 TW9912_INIT_PAL_Progressive_input[]=
{
0x02,0x60
,0x03,0x20
,0x04,0x00
,0x05,0x20
,0x06,0x00
,0x07,0x21
,0x08,0x18
,0x09,0x40
,0x0A,0x00
,0x0B,0x70
,0x0D,0x15
,0x12,0x1e

,0x10,0xfc

,0x13,0x80
,0x14,0x80

,0x15,0x00
,0x17,0x34
,0x18,0x44
,0x1A,0x10
,0x1B,0x00
,0x1E,0x22
,0x20,0x50
,0x21,0x42
,0x22,0xF0
,0x23,0xD8
,0x24,0xBC
,0x25,0xB8
,0x26,0x44
,0x27,0x38
,0x28,0x00
,0x29,0x00
,0x2A,0x78
,0x2B,0x44
,0x2C,0x30
,0x2F,0x24
,0x34,0x1A
,0x36,0xE2
,0x37,0x2A
,0x38,0x5D
,0x40,0x00
,0x41,0x80
,0x42,0x00
,0xC0,0x10
,0xC2,0xC2
,0xC3,0x06
,0xC4,0xB4
,0xC5,0x10
,0xC6,0x26
,0xC9,0x01
,0xCB,0xF0
,0xCC,0x40
,0xCD,0x54
,0xD0,0x00
,0xD1,0xF0
,0xD2,0xF0
,0xD3,0xF0
,0xD4,0x00
,0xD7,0x50
,0xD8,0x00
,0xD9,0x10
,0xDA,0x80
,0xDB,0x80
,0xE1,0x49
,0xE2,0xDA
,0xE3,0x00
,0xE4,0x00
,0xE5,0x00
,0xE6,0x02
,0xE7,0x2A
,0xE8,0x00
,0xE9,0xA0
,0xfe,
};
#endif
