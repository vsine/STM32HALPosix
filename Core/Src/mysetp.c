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
int flag=0;
int flag1=0;
void loop(){

    u8g2_ClearBuffer(&u8g2);
    u8g2_SetFont(&u8g2,u8g2_font_courB10_tf);
    u8g2_DrawStr(&u8g2,0,10,"fs:ok!");
    u8g2_DrawStr(&u8g2,0,20,"nvic:success!");
    u8g2_SetFont(&u8g2,u8g2_font_emoticons21_tr);
    u8g2_DrawGlyph(&u8g2,10,48,0x0021);
    u8g2_DrawGlyph(&u8g2,35,48,0x0037);
    u8g2_DrawGlyph(&u8g2,60,48,0x0036);
    u8g2_SetFont(&u8g2,u8g2_font_battery19_tn);
    if(flag1)
    u8g2_DrawGlyph(&u8g2,88,48,0x0035);
    else{
        u8g2_DrawGlyph(&u8g2,88,48,0x0034);
    }
    u8g2_SetFont(&u8g2,u8g2_font_iconquadpix_m_all);
    u8g2_DrawGlyph(&u8g2,100,48,0x0050);
    u8g2_DrawGlyph(&u8g2,100,34,0x0055);
    u8g2_SendBuffer(&u8g2);
    //HAL_Delay(1);
    
 
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){

}
//float GetDistance(){}

void pTick(){
   if(++flag>500){
       flag1=!flag1;
       flag=0;
   }
   
}