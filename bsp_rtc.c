#include "main.h"   // ��������ͷ�ļ�
		     //�Լ�����ͷ�ļ�������"bsp_rtc.h" 

/*RTC,cubemx��ͬ��Ԥ����ֵ31���첽Ԥ����ֵ999����ص�ʱ����������*/
RTC_TimeTypeDef rtc_time;  //ʱ����Ƚṹ�� 
RTC_DateTypeDef rtc_date;  //�����սṹ�� 
void RTC_Process()
{
	HAL_RTC_GetTime(&hrtc, &rtc_time, RTC_FORMAT_BIN); //��ȡʱ�䣬�����Ƹ�ʽ 
	HAL_RTC_GetDate(&hrtc, &rtc_date, RTC_FORMAT_BIN); //��ȡʱ�䣬�����Ƹ�ʽ 
}
