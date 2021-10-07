#include "mysetp.h"
#include "lvgl.h"


static void lv_ex_label_1(void)
{
    lv_obj_t * label2 = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_recolor(label2, true);
    lv_label_set_long_mode(label2, LV_LABEL_LONG_SROLL_CIRC); /*Circular scroll*/
    lv_obj_set_width(label2, 120);
    // Hello world ! Trisuborn.
    lv_label_set_text(label2, "#ff0000 Hello# #00ff00 world ! Trisuborn.#");
    lv_obj_align(label2, NULL, LV_ALIGN_CENTER, 0, 0);
}


void setp(){
    lv_init();
    lv_port_disp_init();

    lv_ex_label_1();
    while(1){
        lv_tick_inc(5);
        lv_task_handler();
        HAL_Delay(5);
    }
}



