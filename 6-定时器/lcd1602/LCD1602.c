#include <REGX52.H>
#include "LCD1602.h"
#include "MathUtils.h"

char isInited = 0;
/**
	* 写入命令
	*/
void lcd1602_write_cmd(u8 cmd)
{
	LCD1602_RS = 0;
	LCD1602_RW = 0;
	LCD1602_E = 0;
	LCD1602_DATAPORT = cmd;
	DelayNms(1);
	LCD1602_E = 1;
	DelayNms(1);
	LCD1602_E = 0;
	
}
/**
	* 写入字符
	*/
void lcd1602_write_data(u8 dat)
{
	LCD1602_RS = 1;
	LCD1602_RW = 0;
	LCD1602_E = 0;
	LCD1602_DATAPORT = dat;
	DelayNms(1);
	LCD1602_E = 1;
	DelayNms(1);
	LCD1602_E = 0;
	
}
/**
	* 初始化
	*/
void lcd1602_init(void)
{
	if(isInited)
	{
		return;
	}
	lcd1602_write_cmd(0x38);
	lcd1602_write_cmd(0x0C);
	lcd1602_write_cmd(0x06);
	lcd1602_write_cmd(0x01);
	isInited = 1;
}

void lcd1602_show_string(u8 x, u8 y, u8 *str)
{
	lcd1602_init();
	if(y > 1 | x > 15) return;
	if(y < 1)  // 第一行
	{
		while(*str != '\0')
		{
		
			if(x < 16) {
				lcd1602_write_cmd(0x80 + x);
			}
			else
			{
				lcd1602_write_cmd(0xB0 + x);
			}
			lcd1602_write_data(*str);
			str++;
			x++;
		}
	}
	else       // 第二行
	{
		while(*str != '\0')
		{
			if(x < 16)
			{
				lcd1602_write_cmd(0xC0 + x);
			}
			else 
			{
				lcd1602_write_cmd(0x70 + x);
			}
			lcd1602_write_data(*str);
			str++;
			x++;
		}
	}
}
/**
	* 展示数字
	*/
void lcd1602_show_number(u8 x, u8 y, u8 digit, u8 number)
{
	u8 tempNumber = number;
	
	lcd1602_init();
	while(digit--)
	{
		if(y > 1 | x > 15) return;
		if(y < 1)
		{
			lcd1602_write_cmd(0x80 + x);
		}
		else
		{
			lcd1602_write_cmd(0xC0 + x);
		}
		lcd1602_write_data(tempNumber / intPow(10, digit) + 0x30); 
		if(++x > 15)
		{
			x = 1;
			y++;
		}
		tempNumber = tempNumber % intPow(10, digit);
	}
}
/**
	* 设置为空
	*/
void lcd1602_clear_limit(u8 startX, u8 startY, u8 digit)
{
	u8 x = startX, y = startY;
	int i = 0;
	
	lcd1602_init();
	
	if(startX > 15 | startY > 1 | digit == 0) return;
	for(; i < digit; i++)
	{
			lcd1602_show_string(x, y, " ");
		 if(x++ > 15)
		 {
				x = 0;
				y++;
		 }
		if(startY > 1) break;
	}
}

/**
	* 清空屏幕
	*/
void lcd1602_clear(void)
{
	lcd1602_write_cmd(0x01);
}