#include "main.h"   //需要包含这个头文件
                    //自己定义头文件，类似"bsp_key.h"
/*该状态机实现了按键的短按长按和双击功能，使用状态机实现很好理解*/
/*在cubemax的配置是把四个GPIO设置为输入模式，开启定时器4,建议分屏80-1，重装载10000-1*/
/*建议把结构体放在key.h中，这里不提供.h文件*/
struct keys
{
    u8      key_steps;      //执行到的步骤
    _Bool   key_status;     //引脚的转态
    _Bool   key_ok;         //短按
    _Bool   key_long_hit;   //长按
    _Bool   key_dble_hit;   //双击
    _Bool   key_dble_flag;  //进入双击判断标志
};

struct keys key[4] = { 0 };

u16 long_time   = 0;
u16 double_time = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)//定时器回调函数
{
    if(htim->Instance == TIM4)//选择使用定时器4，定时时间是10ms
    {
        //读取每个引脚的电平状况
        key[0].key_status = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0);
        key[1].key_status = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1);
        key[2].key_status = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2);
        key[3].key_status = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);
        
        for(int i = 0;i < 4;i++)
        {
            switch(key[i].key_steps)
            {
                case 0:
                {
                    if(key[i].key_status == 0)//如果按下了
                    {
                        long_time = 0;        //长按重新计时
                        key[i].key_steps = 1; //跳到第二步执行，相当于延时了10ms（消抖）
                    }
                }break; 
                case 1:
                {
                     if(key[i].key_status == 0)//还是按下的
                     {
                        key[i].key_steps = 2; //跳到第三步执行，如果仅仅使用短按，在此步即可实现
                     }
                     else
                        key[i].key_steps = 0; //松开了回到第一步
                }break;
                case 2:
                {
                     if(key[i].key_status == 1)//松开了
                     {                       
                        key[i].key_long_hit = 0; //松开后长按结束,此处的长按置0可能没有执行过长按。
                        if(key[i].key_dble_flag == 0) //不管是否长按都会进入双击的判断，此处表示第一次按下
                        {
                            double_time = 0;        //让双击判定时间置0
                            key[i].key_dble_flag = 1;//表示第一次按下了
                        }
                        else  //第二次按下，因为按下了才能到第三步（key[i].key_steps = 2）
                        {
                            key[i].key_dble_flag = 0; //按下计数置0
                            key[i].key_dble_hit = 1; //执行双击
                        }
                        key[i].key_steps = 0; //回到第一步
                     }
                     else//一直按着
                     {
                         long_time++;//长按时间自增
                         if(long_time >= 100)//按下时间大于100ms，表示长按了
                             key[i].key_long_hit = 1;//执行长按
                     }
                }break;
                
            }
            if(key[i].key_dble_flag == 1) //表示第一次按下后
                {
                    double_time++;//按下后的判定双击的时间自增
                    if(double_time >= 20) //如果松开第一次大于200ms没有按下第二次
                    {
                        key[i].key_ok = 1; //表示短按
                        key[i].key_dble_flag = 0;//按下计数置0
                    }
                }
        }
    }
}


//在main函数中的实现，函数名放while(1)即可
void KEY_Proc(void)
{
    if(key[0].key_ok == 1) // 表示KEY1短按
    {
        { }
        key[0].key_ok = 0;//必须置0
    }
    if(key[0].key_long_hit == 1)// 表示KEY1长按  在状态机中置0了
    {
        { }
    }
    if(key[0].key_dble_hit == 1)// 表示KEY1双击
    {
        { }
        key[0].key_dble_hit = 0;  //必须置0
    }
}
