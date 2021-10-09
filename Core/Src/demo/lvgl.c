#include "mysetp.h"


#include "lvgl.h"
#include "lv_port_disp.h"
int k=0;
lv_obj_t * bar1;
static void lv_ui(void)
{

    lv_obj_t * btn = lv_btn_create(lv_scr_act(),NULL);
    lv_obj_t * lab = lv_label_create(btn, NULL);
    lv_obj_align(btn,NULL, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(lab, "fuck me");
    //lv_btn_set_recolor(label2, true);
    //lv_label_set_long_mode(label2, LV_LABEL_LONG_SROLL_CIRC); /*Circular scroll*/
    // Hello world ! Trisuborn.
    bar1 = lv_bar_create(lv_scr_act(), NULL);
    lv_obj_set_width(bar1,100);
}
void lvgl_setp(){
    lv_init();
    lv_port_disp_init();
    lv_ui();
    while(1){
        lv_tick_inc(5);
        lv_task_handler();
        HAL_Delay(5);
        lv_bar_set_value(bar1,k,LV_ANIM_OFF);
        k++;
        if (k>100)
        {
            k=0;
        }

        
    }
}
void setp(){
    lvgl_setp();
}
