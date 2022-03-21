#include <REGX52.H>
#include "LCD1602.h"

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

void lcd1602_init(void)
{
	lcd1602_write_cmd(0x38);
	lcd1602_write_cmd(0x0C);
	lcd1602_write_cmd(0x06);
	lcd1602_write_cmd(0x01);
}

void lcd1602_show_string(u8 x, u8 y, u8 *str)
{
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

void lcd1602_show_number(u8 x, u8 y, u8 number)
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
	lcd1602_write_data(number + 0x30); 
}

void lcd1602_clear(void)
{
	lcd1602_write_cmd(0x01);
}