#include "led.h"
/*
    C引脚的高八位控制led，先让高八位置1让led灯全灭。
    使用八位的变量左移八位达到控制led。
*/
void LED_Contrl(u8 led_contrl)
{
    HAL_GPIO_WritePin(GPIOC,0xff00,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET);
    
    HAL_GPIO_WritePin(GPIOC,led_contrl << 8,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET);
}
