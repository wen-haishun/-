#include "main.h"   // 需包含这个头文件
		     //自己定义头文件，类似"bsp_dac.h"
//DAC
u16 dac_ch1_val,dac_ch2_val;
void DAC_Process()
{  
	dac_ch1_val = (1.1f/3.3f*4095);
	dac_ch2_val = (2.5f/3.3f*4095);
	
	HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, dac_ch1_val);	//0-->0v  4095--> 3.3V    1.1v --> 1365
	HAL_DAC_Start(&hdac1, DAC_CHANNEL_1);
	  
    HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_2, DAC_ALIGN_12B_R, dac_ch2_val);	//0-->0v  4095--> 3.3V    2.2v --> 2730
	HAL_DAC_Start(&hdac1, DAC_CHANNEL_2);
}
