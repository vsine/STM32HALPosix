#include "mysetp.h"
#include "stdlib.h"
#include "mpu6050.h"
#include "klaman.h"
#include <math.h>
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
    Calibration();
    scalar_kalman_init(&temp,1,1,0.01,1);
}

void loop(){

    u8g2_ClearBuffer(&u8g2);
    u8g2_SetFont(&u8g2,u8g2_font_courB12_tf);
    u8g2_DrawStr(&u8g2,10,20,"former:");
    u8g2_DrawStr(&u8g2,10,40,"klaman:");


    int readouts[7];
    ReadAccGyr(readouts);//读出测量值
    float realVals[7];
    Rectify(readouts, realVals); //根据校准的偏移量进行纠正
    float fNorm = sqrt(realVals[0] * realVals[0] + realVals[1] * realVals[1] + realVals[2] * realVals[2]);
    float fRoll = GetRoll(realVals, fNorm); //计算Roll角
    if (realVals[1] > 0) {
      fRoll = -fRoll;
     }
     float fPitch = GetPitch(realVals, fNorm); //计算Pitch角
     if (realVals[0] < 0) {
     fPitch = -fPitch;
     }

    char str[10]; 
    char str1[10]; 
    float i=MPU_Get_Temperature();
    float f=scalar_kalman(&temp,i);
    gcvt(f,4,str);
    gcvt(i,4,str1);
    u8g2_DrawStr(&u8g2,78,40,str);
    u8g2_DrawStr(&u8g2,78,20,str1);
    //u8g2_DrawLine(&u8g2,20,20,40,20);
    u8g2_SendBuffer(&u8g2);
    HAL_Delay(1);
}




