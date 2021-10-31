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
    u8g2_SetFont(&u8g2,u8g2_font_courB10_tf);
    u8g2_DrawStr(&u8g2,0,10,"fs:ok!");
    u8g2_DrawStr(&u8g2,0,20,"nvic:success!");
    u8g2_SetFont(&u8g2,u8g2_font_open_iconic_weather_6x_t);
    u8g2_DrawGlyph(&u8g2,0,48,0x0045);
    u8g2_SendBuffer(&u8g2);
    HAL_Delay(1);

 
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){

}
//float GetDistance(){}

void pTick(){
   
   
}