#include "mysetp.h"
#include "stdlib.h"


//extern TIM_HandleTypeDef htim1;

void setp(){
//HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
//HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_1);
//HAL_Delay(11);

}
void loop(){
    HAL_Delay(300);
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    
}
//float GetDistance(){}
void pTick(){

   
}