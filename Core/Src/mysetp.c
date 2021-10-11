#include "mysetp.h"
#include "fatfs.h"
#include "stdlib.h"
u8g2_t u8g2;

FATFS fs;
FATFS *pfs;
FIL fil;



void setp(){
    HAL_Delay(1000);
    u8g2Init(&u8g2);
    HAL_Delay(1000);
    u8g2_ClearBuffer(&u8g2);
    u8g2_SetFont(&u8g2, u8g2_font_8x13_tr);

    if(f_mount(&fs, "0:", 0) == FR_OK)
    u8g2_DrawStr(&u8g2,20,10,"fs ok1!");
    
    HAL_Delay(100);

    //if(f_open(&fil, "first.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE)== FR_OK)
   // u8g2_DrawStr(&u8g2,20,30,"read ok!");
   // else
    char str[25];
    itoa(f_open(&fil, "0:/first.txt", FA_READ), str, 10);
    u8g2_DrawStr(&u8g2,20,30,str);
    char *buff;
    f_read(&fil,buff,4,4);
    //f_write(&fil,"123",10,0);
    //f_close(&fil);
    //BYTE work[512];
    
    //itoa(f_mkfs("",0, 0, work, sizeof (work)), str, 10);
    //u8g2_DrawStr(&u8g2,20,40,buff);


    u8g2_SendBuffer(&u8g2);
    while (1){
       HAL_Delay(100);

    }
}



