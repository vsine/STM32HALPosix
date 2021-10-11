#include "mysetp.h"
#include "stdlib.h"

lv_obj_t *bar;
static void lv_ui(void)
{
    lv_obj_t * btn = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_y(btn,50);
    lv_obj_t * label=lv_label_create(btn, NULL);
     bar=lv_bar_create(lv_scr_act(),NULL);
    lv_obj_set_y(bar,10);
    lv_bar_set_value(bar,70,LV_ANIM_ON);
    lv_obj_set_width(bar,128);
    lv_label_set_text(label,"DDF");

    // Hello world ! Trisuborn.
    // lv_style_t style_btn;
    //lv_obj_set_style_local_bg_color(label, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLUE);
    //lv_style_set_bg_opa(&style_btn, LV_STATE_DEFAULT, LV_OPA_TRANSP);
    //lv_style_set_bg_opa(&style_btn, LV_OPA_50);
    //lv_style_set_border_width(&style_btn, 2);
    //lv_style_set_border_color(&style_btn, lv_color_black());

}
int k=0;

void setp(){
    HAL_Delay(100);
    lv_init();
    lv_port_disp_init();
    lv_ui();
    while(1) {
		// 先调用 lv_tick_inc 再调用 lv_task_handler
		lv_tick_inc(100);
		lv_task_handler();
		HAL_Delay(100);	
        lv_bar_set_value(bar,k++,LV_ANIM_OFF);
        if(k>99){
            k=0;
        }
	}

}






