#include "mysetp.h"
#include "stdlib.h"
#include "mpu6050.h"
#include "klaman.h"
u8g2_t u8g2;
scalar_kalman_t temp;
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
    scalar_kalman_init(&temp,1,1,0.001,0.1);
    
}

void loop(){

    u8g2_ClearBuffer(&u8g2);
    u8g2_SetFont(&u8g2,u8g2_font_courB12_tf);
    u8g2_DrawStr(&u8g2,10,20,"former:");
    u8g2_DrawStr(&u8g2,10,40,"klaman:");
    char str[10]; 
    char str1[10]; 
    short rc;
    MPU_Get_Accelerometer(&rc,&rc,&rc);
    float i=rc;
    
    float f=scalar_kalman(&temp,i);
    gcvt(f,4,str);
    gcvt(i,4,str1);
    u8g2_DrawStr(&u8g2,78,40,str);
    u8g2_DrawStr(&u8g2,78,20,str1);
    //u8g2_DrawLine(&u8g2,20,20,40,20);
    u8g2_SendBuffer(&u8g2);
    HAL_Delay(1);
}




