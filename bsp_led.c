#include "main.h"       //需包含的头文件
                        //自己定义头文件，类似"bsp_led.h"
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


//在主函数实现,把函数放while(1)即可。
u8  led_ctrl = 0x0;//定义一个变量实现控制
u32 ledTick = 0;   //闪烁计时
void LED_Ctrl(void)
{
    if(uwTick - ledTick < 100) return; //计时100ms进入一次
    ledTick = uwTick;
    //实现LED1闪烁
    led_ctrl ^= 0x01;
    //实现闪烁的同时LED2亮
    led_ctrl |= 0x02;
    //使用一下方式实现点亮和熄灭不影响别的位
    led_ctrl |= 0x04;  //点亮LED3
    led_ctrl &= ~0x04; //熄灭LED3
    LED_Contrl(led_ctrl);
}
