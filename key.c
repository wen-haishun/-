#include "key.h"

struct keys key[4] = { 0 };

u16 long_time   = 0;
u16 double_time = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM4)
    {
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
                    if(key[i].key_status == 0)
                    {
                        long_time = 0;
                        key[i].key_steps = 1;
                    }
                }break; 
                case 1:
                {
                     if(key[i].key_status == 0)
                     {
                        key[i].key_steps = 2;
                     }
                     else
                        key[i].key_steps = 0; 
                }break;
                case 2:
                {
                     if(key[i].key_status == 1)
                     {
                        key[i].key_steps = 0; 
                        key[i].key_long_hit = 0;
                        if(key[i].key_dble_flag == 0)
                        {
                            double_time = 0;
                            key[i].key_dble_flag = 1;
                        }
                        else
                        {
                            key[i].key_dble_flag = 0;
                            key[i].key_dble_hit = 1;
                        }
                     }
                     else
                     {
                         long_time++;
                         if(long_time >= 100)
                             key[i].key_long_hit = 1;
                     }
                }break;
                
            }
            if(key[i].key_dble_flag == 1)
                {
                    double_time++;
                    if(double_time >= 20)
                    {
                        key[i].key_ok = 1;
                        key[i].key_dble_flag = 0;
                    }
                }
        }
    }
}




