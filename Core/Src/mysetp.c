#include "mysetp.h"
#include "stdlib.h"


u8g2_t u8g2;

void setp(){
    HAL_Delay(100);
    u8g2Init(&u8g2);
    u8g2_ClearBuffer(&u8g2);
    u8g2_SetFont(&u8g2,u8g2_font_courB12_tf);
    u8g2_DrawStr(&u8g2,10,30,"test");
    u8g2_SendBuffer(&u8g2);

}

void loop(){

    u8g2_ClearBuffer(&u8g2);
    u8g2_SetFont(&u8g2,u8g2_font_courB12_tf);
    u8g2_DrawStr(&u8g2,10,30,"eXe");
    u8g2_SendBuffer(&u8g2);
    HAL_Delay(1);

 
}




void pTick(){
   
   
}