#include "main.h"   // ��������ͷ�ļ�
		     //�Լ�����ͷ�ļ�������"bsp_lcd.h" 
		     		 
_Bool lcd_mode = 0; 
void LCD_Proc(void)
{
	u8 test_value = 10;
	u8 LCD_buf[20]; // ����һ�����飬20���ɣ���Ϊ��Ļ�ĳ�����20
	//ֱ�������Ļ 
	LCD_DisplayStringLine(Line0,(unsigned char*)"      LCD_TEST    "); 
	sprintf((char*)display_buf," Value:%d",test_value); //ʹ��ƴ�Ӻ�������ʵ�ֱ������ַ�����ƴ�ӡ� 
	LCD_DisplayStringLine(Line0,display_buf);//��ƴ�Ӻõ��ַ�����ӡ��
	
	//���Ҫʵ����������,��һ����Ļ�е��ַ����͵ڶ�����Ļ�е���ʾ��ͬһ�У����ҵ�һ����Ļ�ĳ����ᵼ���л����ڶ�����Ļ��ʱ�����ʾ��һ����Ļ�ȵڶ�����Ļ������Ĳ���
	/*
		��ʽһ��ˢ����Ļ�����������������ʹ���������Լ���ʱ��ÿ�ζ�ˢ��Ӱ��۸С�
		��ʽ��ʹ�ں�����ӿո�ʹ֮����һ�¡� 
	*/ 
	if(lcd_mode == 0)
	{
		LCD_DisplayStringLine(Line0,(unsigned char*)"ABCDEFGH");  
	}
	else
	{
		LCD_DisplayStringLine(Line0,(unsigned char*)"ABCD    "); //��ӿո� 
	}
}
