#include "mysetp.h"
#include "stdlib.h"
u8g2_t u8g2;
void setp(){
    HAL_Delay(100);
    u8g2Init(&u8g2);
    u8g2_ClearBuffer(&u8g2);
    u8g2_SetFont(&u8g2,u8g2_font_courB12_tf);
    u8g2_DrawStr(&u8g2,10,20,"Q:2.3");
    u8g2_DrawStr(&u8g2,10,40,"R:4.7");
    u8g2_DrawStr(&u8g2,10,55,"X(K|K):12.7");
    //u8g2_DrawLine(&u8g2,20,20,40,20);
    u8g2_SendBuffer(&u8g2);
    while (1)
    {
       
    }
    
}






