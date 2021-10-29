#include "mysetp.h"
#include "stdlib.h"
#include "mpu6050.h"
#include "klaman.h"
#include <math.h>
#include "inv_mpu.h"
#include "pid.h"

extern TIM_HandleTypeDef htim1;

#define PID_KP  650.0f
#define PID_KI  0
#define PID_KD  0.1f

#define PID_TAU 0.002f

#define PID_LIM_MIN -20000.0f
#define PID_LIM_MAX  20000.0f

#define PID_LIM_MIN_INT -5.0f
#define PID_LIM_MAX_INT  5.0f

#define SAMPLE_TIME_S 0.35f

/* Maximum run-time of simulation */
#define SIMULATION_TIME_MAX 4.0f






scalar_kalman_t temp;
float f,out;
char isrun=0;
PIDController pid;
void setp(){
    HAL_Delay(100);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
    
    HAL_Delay(10);
    mpu_dmp_init();
    scalar_kalman_init(&temp,1,1,0.001,0.2);



    pid.Kp=PID_KP;
    pid.Kd=PID_KD;
    pid.Ki=PID_KI;
    pid.tau=PID_TAU;
    pid.limMax=PID_LIM_MAX;
    pid.limMin=PID_LIM_MIN;
    pid.limMaxInt=PID_LIM_MAX_INT;
    pid.limMinInt=PID_LIM_MAX_INT;

    PIDController_Init(&pid);
    isrun=1;

}
void impu(){


   // char str[10]; 
   
    
    
}
void loop(){


    float p,r,y;
    mpu_dmp_get_data(&p,&r,&y);
    //f=scalar_kalman(&temp,p);
    f=p;





     if(isrun==1){
        out= PIDController_Update(&pid, 0, f);
        if (out<0)
        {
                
             HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
             HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_RESET);
             HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_RESET);
             HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);
            //反转
             __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, (-out));
             __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2, (-out));
        }else if(out>0){
            //正转
             HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
             HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
             HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
             HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);


             __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, out);
             __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2, out);
        }else{
             __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, out);
             __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2, out);
        }
        
    }
}




void pTick(){
   
   
}