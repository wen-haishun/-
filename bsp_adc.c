#include "main.h"   // 需包含这个头文件

// ADCÖ´ÐÐ³ÌÐò
u16 adc1_val,adc2_val;
float volt_r37,volt_r38,volt_mcp;
void ADC_Process(void)
{

	HAL_ADC_Start(&hadc1);
	adc1_val = HAL_ADC_GetValue(&hadc1);
	volt_r38 = adc1_val/4096.0f*3.3f;
	
    HAL_ADC_Start(&hadc2);
	adc2_val = HAL_ADC_GetValue(&hadc2);
	volt_r37 = adc2_val/4096.0f*3.3f;
}
