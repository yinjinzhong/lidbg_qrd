
#ifdef DEBUG_CS42L52

#include "lidbg.h"

//#define CS42L52_MASTER


#if 0
u8 cs42l52_config[] =//42l52
{
    0x0, 0x0,
    0x1, 0xe3,
    0x2, 0x0,
    0x3, 0x1f,
    0x4, 0x5,
#ifdef CS42L52_MASTER
    0x5, 0xa2,
    0x6, 0x87,
#else
    // 0x5, 0xa3,// 48K 2.4M 24M  datasheet-p35
    0x5, 0xa0,// 44.1K 2.8M 11.28M
    0x6, 0x07,
#endif

    0x7, 0x5,
    0x8, 0x93,
    0x9, 0x93,
    0xa, 0xa5,
    0xb, 0x0,
    0xc, 0x3,
    0xd, 0x60,
    0xe, 0x0,
    0xf, 0x2,
    0x10, 0x3f,
    0x11, 0x1f,
    0x12, 0x0,
    0x13, 0x0,
    0x14, 0x0,
    0x15, 0x0,
    0x16, 0x0,
    0x17, 0x0,
    0x18, 0x80,
    0x19, 0x80,
    0x1a, 0x0,
    0x1b, 0x0,
    0x1c, 0x0,
    0x1d, 0x0,
    0x1e, 0x0,
    0x1f, 0x88,
    0x20, 0x0,
    0x21, 0x0,
    0x22, 0x0,
    0x23, 0x0,
    0x24, 0x0,
    0x25, 0x0,
    0x26, 0x0,
    0x27, 0x0,
    0x28, 0x7f,
    0x29, 0xc0,
    0x2a, 0x0,
    0x2b, 0x3f,
    0x2c, 0x0,
    0x2d, 0x0,
    0x2e, 0x0,
    0x2f, 0x0,
    0x30, 0x0,
    0x31, 0x0,
    0x32, 0x3b,
    0x33, 0x0,
    0x34, 0x5f,


    0xFF		// end flag

};
#else

//\u4f7f\u7528A\u901a\u9053MIC1
u8 cs42l52_config[] =//42l52
{
    0x0, 0x0,
    0x1, 0xe3,
    0x2, 0x14,//\u5f00A\uff0c\u5173B
    0x3, 0x1C,//\u5f00Mic1\u5173Mic2
    0x4, 0x5,
#ifdef CS42L52_MASTER
    0x5, 0xa2,
    0x6, 0x87,
#else
// 0x5, 0xa3,// 48K 2.4M 24M  datasheet-p35
0x5, 0xa0,// 44.1K 2.8M 11.28M

//0x5, 0xd0,// 16K

//0x6, 0x07,
0x6, 0x27,
#endif
    0x7, 0x5,//bias volatage 0.91*Va
    0x8, 0x93,
    0x9, 0x93,
    0xa, 0xa5,
    0xb, 0x0,
    0xc, 0x2,
    0xd, 0x60,
    0xe, 0x0,
    0xf, 0x2,
    0x10, 0x20,//A Mic1\uff0c\u5dee\u5206\uff0c\u589e\u76ca16dB
    0x11, 0x60,//B Mic2\uff0c\u5dee\u5206\uff0c\u589e\u76ca16dB
    0x12, 0x0,
    0x13, 0x0,
    0x14, 0x0,
    0x15, 0x0,
    0x16, 0x0,
    0x17, 0x0,
    0x18, 0x80,
    0x19, 0x80,
    0x1a, 0x0,
    0x1b, 0x0,
    0x1c, 0x0,
    0x1d, 0x0,
    0x1e, 0x0,
    0x1f, 0x88,
    0x20, 0x0,
    0x21, 0x0,
    0x22, 0x0,
    0x23, 0x0,
    0x24, 0x0,
    0x25, 0x0,
    0x26, 0x0,
    0x27, 0x0,
    0x28, 0x7f,
    0x29, 0xc0,
    0x2a, 0x0,
    0x2b, 0x3f,
    0x2c, 0x0,
    0x2d, 0x0,
    0x2e, 0x0,
    0x2f, 0x0,
    0x30, 0x0,
    0x31, 0x0,
    0x32, 0x3b,
    0x33, 0x0,
    0x34, 0x5f,

    // 0xFF  // end flag
};



#endif


/*
//record ok
\u9ad8\u672c\u80fd 9:40:31
//\u4f7f\u7528A\u901a\u9053MIC1
u8 cs42l52_config[] =//42l52
{
     0x0, 0x0,
     0x1, 0xe3,
     0x2, 0x14,//\u5f00A\uff0c\u5173B
     0x3, 0x1C,//\u5f00Mic1\u5173Mic2
     0x4, 0x5, #ifdef CS42L52_MASTER
     0x5, 0xa2,
     0x6, 0x87,
#else
     // 0x5, 0xa3,// 48K 2.4M 24M  datasheet-p35
     0x5, 0xa0,// 44.1K 2.8M 11.28M
     0x6, 0x07,
#endif
     0x7, 0x5,//bias volatage 0.91*Va
     0x8, 0x93,
     0x9, 0x93,
     0xa, 0xa5,
     0xb, 0x0,
     0xc, 0x2,
     0xd, 0x60,
     0xe, 0x0,
     0xf, 0x2,
     0x10, 0x20,//A Mic1\uff0c\u5dee\u5206\uff0c\u589e\u76ca16dB
     0x11, 0x60,//B Mic2\uff0c\u5dee\u5206\uff0c\u589e\u76ca16dB
     0x12, 0x0,
     0x13, 0x0,
     0x14, 0x0,
     0x15, 0x0,
     0x16, 0x0,
     0x17, 0x0,
     0x18, 0x80,
     0x19, 0x80,
     0x1a, 0x0,
     0x1b, 0x0,
     0x1c, 0x0,
     0x1d, 0x0,
     0x1e, 0x0,
     0x1f, 0x88,
     0x20, 0x0,
     0x21, 0x0,
     0x22, 0x0,
     0x23, 0x0,
     0x24, 0x0,
     0x25, 0x0,
     0x26, 0x0,
     0x27, 0x0,
     0x28, 0x7f,
     0x29, 0xc0,
     0x2a, 0x0,
     0x2b, 0x3f,
     0x2c, 0x0,
     0x2d, 0x0,
     0x2e, 0x0,
     0x2f, 0x0,
     0x30, 0x0,
     0x31, 0x0,
     0x32, 0x3b,
     0x33, 0x0,
     0x34, 0x5f,

     0xFF  // end flag
};

*/

int audio_codec_init(void)
{

    u32 i = 0;
    u8 data = 0;

    lidbg("cs42l52 init+\n");

    CS42L52_RESET;

    for(i = 0; i < SIZE_OF_ARRAY(cs42l52_config) / 2; i++)
    {
        SOC_I2C_Send(1, 0x4a, &cs42l52_config[i*2] , 2);

    }

    for(i = 0; i < SIZE_OF_ARRAY(cs42l52_config) / 2; i++)
    {
        data = 0xff;
        SOC_I2C_Rec(1, 0x4a, cs42l52_config[i*2], &data , 1);
        lidbg("%x %x\n", cs42l52_config[i*2], data);
    }

    lidbg("cs42l52 init-\n");

    return 1;
}
//EXPORT_SYMBOL(audio_codec_init);

#endif
