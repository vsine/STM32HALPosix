#include "mysetp.h"
#include "lvgl.h"




void setp(){
    lv_init();
    lv_port_disp_init();
    while(1){
        lv_tick_inc(5);
        lv_task_handler();
        HAL_Delay(5);
    }
}



