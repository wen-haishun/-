#include "main.h"   // 需包含这个头文件
		     //自己定义头文件，类似"bsp_adc.h"

/*二路ADC测量，对应开发板上的R37和R38*/
/*cubemax的配置PB15和PB12*/
u16 	adc1_val,adc2_val;
float   volt_r37,volt_r38;
void ADC_Process(void)
{
    HAL_ADC_Start(&hadc1);                 //开启adc1
    adc1_val = HAL_ADC_GetValue(&hadc1);   //获取电压
    volt_r38 = adc1_val/4096.0f*3.3f;      //进行电压转换
	
    HAL_ADC_Start(&hadc2);
    adc2_val = HAL_ADC_GetValue(&hadc2);
    volt_r37 = adc2_val/4096.0f*3.3f;
}
