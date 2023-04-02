#include "main.h"   // 需包含这个头文件
		     //自己定义头文件，类似"bsp_lcd.h" 
		     		 
_Bool lcd_mode = 0; 
u8 test_value = 10;
void LCD_Proc(void)
{	
	u8 LCD_buf[20]; // 定义一个数组，20即可，因为屏幕的长是20
	//直接输出屏幕 
	LCD_DisplayStringLine(Line0,(unsigned char*)"      LCD_TEST    "); 
	//使用拼接函数可以实现变量与字符串的拼接
	sprintf((char*)display_buf," Value:%d",test_value); 
	//将拼接好的字符串输出屏幕。
	LCD_DisplayStringLine(Line0,display_buf);
	
	//如果要实现切屏功能,第一个屏幕中的字符串和第二个屏幕中的显示在同一行，而且第一个屏幕的长，会导致切换到第二个屏幕的时候会显示第一个屏幕比第二个屏幕多出来的部分
	/*
		比如第一个屏幕 ABCDEDFGH 显示在第一行0开始,第二个屏幕 1234 显示在第一行0开始,由第一切换第二时,第二屏幕会显示1234EDFGH
	*/
	/*
		方式一是刷新屏幕：但是如果遇到按键使变量自增自减的时候，每次都刷，影响观感。
		方式二使在后面添加空格，使之长度一致。 
	*/ 
	if(lcd_mode == 0)
	{
		LCD_DisplayStringLine(Line0,(unsigned char*)"ABCDEFGH");  
	}
	else
	{
		LCD_DisplayStringLine(Line0,(unsigned char*)"1234    "); //添加空格 
	}
}
