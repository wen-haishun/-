#include "main.h"   // 需包含这个头文件
		     //自己定义头文件，类似"bsp_rtc.h" 

/*RTC,cubemx中同步预分频值31，异步预分频值999，相关的时间自行设置*/
RTC_TimeTypeDef rtc_time;  //时分秒等结构体 
RTC_DateTypeDef rtc_date;  //年月日结构体 
void RTC_Process()
{
	HAL_RTC_GetTime(&hrtc, &rtc_time, RTC_FORMAT_BIN); //获取时间，二进制格式 
	HAL_RTC_GetDate(&hrtc, &rtc_date, RTC_FORMAT_BIN); //获取时间，二进制格式 
}



//在main函数中把两个结构体里的成员变量调用即可
