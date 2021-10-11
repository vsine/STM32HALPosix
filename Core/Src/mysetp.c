#include "mysetp.h"
#include "fatfs.h"
#include "stdlib.h"
u8g2_t u8g2;

FATFS fs;
FATFS *pfs;
FIL fil;


UINT br;
BYTE frame[1024];
void setp(){
    HAL_Delay(100);
    u8g2Init(&u8g2);
    u8g2_ClearBuffer(&u8g2);
    f_mount(&fs, "0:", 0);
    HAL_Delay(100);
    f_open(&fil, "0:/badapple.txt", FA_READ);
    while (1){
    u8g2_ClearBuffer(&u8g2);   
    f_read(&fil,frame,1024,&br);
    for (int k = 0; k < 8; k++)
        for (int x = 0; x < 128; x++)
            for (int y = 0; y < 8; y++)
                if(frame[k*128+x]&(0x01<<y))
                    u8g2_DrawPixel(&u8g2,x,y+(k*8));
    u8g2_SendBuffer(&u8g2);
    HAL_Delay(1)
    }
}





void jinc(){

}


