#include "mysetp.h"
#include "stdlib.h"
#include "mpu6050.h"
u8g2_t u8g2;
void setp(){
    HAL_Delay(100);
    u8g2Init(&u8g2);
    u8g2_ClearBuffer(&u8g2);
    u8g2_SetFont(&u8g2,u8g2_font_courB12_tf);
    u8g2_DrawStr(&u8g2,10,20,"fs:ok");
    u8g2_DrawStr(&u8g2,10,40,"dfs:ok");
    u8g2_DrawStr(&u8g2,10,55,"X(K|K):0.1");
    //u8g2_DrawLine(&u8g2,20,20,40,20);
    u8g2_SendBuffer(&u8g2);
    MPU_Init();
    
}

void loop(){

    u8g2_ClearBuffer(&u8g2);
    u8g2_SetFont(&u8g2,u8g2_font_courB12_tf);
    u8g2_DrawStr(&u8g2,10,20,"fs:ok");
    u8g2_DrawStr(&u8g2,10,40,"temp:");
    char str[10]; 
    float f=MPU_Get_Temperature();
    gcvt(f,4,str);
    u8g2_DrawStr(&u8g2,10,55,str);
    //u8g2_DrawLine(&u8g2,20,20,40,20);
    u8g2_SendBuffer(&u8g2);
    HAL_Delay(500);
}




