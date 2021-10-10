#include "mysetp.h"


u8g2_t u8g2;



void setp(){
    HAL_Delay(1000);
    u8g2Init(&u8g2);
    HAL_Delay(1000);
    while (1){
        u8g2_ClearBuffer(&u8g2);
        u8g2_SetFont(&u8g2, u8g2_font_10x20_tr);
        u8g2_DrawBitmap
        u8g2_SendBuffer(&u8g2);

    }
}



