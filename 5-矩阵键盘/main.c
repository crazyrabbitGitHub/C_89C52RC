#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"
#include "MathUtils.h"

/**
	*	匹配密码：前8个按钮位输入数字1~8,最后两个按钮分别位取消和确认
	*/
void main()
{
	unsigned int password = 836;
	unsigned char passwordLen = getIntegerSize(password);
	unsigned int inputPassword = 0;
 	// 3位密码
	unsigned char passwordDigit = passwordLen;
	unsigned char xAddress = passwordDigit;
	unsigned char keyArrLocation = 0;
	
	lcd1602_show_string(0,0,"Three password:");
	while(passwordDigit+1)
	{
		while(passwordDigit)
		{
			unsigned char martrixKey =	MatrixKey();
			keyArrLocation = xAddress - passwordDigit;
			switch(martrixKey)
			{
				// 密码：1~8
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
					lcd1602_show_number(keyArrLocation, 1, 1, martrixKey);
					inputPassword = inputPassword * 10 + martrixKey;
					passwordDigit--;
					break;
				// 取消:
				case 15:
					if(keyArrLocation)
					{
						passwordDigit++;
						inputPassword /= 10;
						lcd1602_clear_limit(--keyArrLocation, 1, 1);
					}
					break;
				default:{}
			}
		}
		// 操作按钮
		switch(MatrixKey())
		{
			case 15:
				passwordDigit++;
				inputPassword /= 10;
				lcd1602_clear_limit(keyArrLocation, 1, 1);
				break;
			case 16:
				if(inputPassword == password)
				{
					lcd1602_clear();
					lcd1602_show_string(0,0,"success");
					// 退出
					passwordDigit--;
				}
				else{
					lcd1602_clear_limit(0,0,16);
					lcd1602_show_string(0,0,"failure");
					DelayNms(500);
					lcd1602_show_string(0,0,"Three password:");
				}
				break;
		}
		
	}
	DelayNms(500);
	lcd1602_clear();
	lcd1602_show_string(0,0,"progress exit");
	while(1);
}