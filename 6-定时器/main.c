#include <REGX52.H>
#include <INTRINS.H>
#include "LCD1602.h"
#include "Timer.h"
#include "MatrixKey.h"

unsigned char keyNumber;
void main()
{
	P2 = 0x7F;
	Timer0_init();
	Timer1_init();
	while(1);
}

// 定时器
void Timer0_Routin() interrupt 1
{
	static unsigned int T0Count = 0;
	TL0 = 0x66;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	T0Count++;
	if(T0Count >= 500)
	{
		T0Count = 0;
		P2 = _cror_(P2, 1);
	}
}

// 定时器
void Timer1_Routin() interrupt 3
{
	static unsigned int T1Count = 0;
	static unsigned int Sec = 0;
	TL1 = 0x66;		//设置定时初始值
	TH1 = 0xFC;		//设置定时初始值
	T1Count++;
	if(T1Count >= 1000)
	{
		T1Count = 0;
		Sec++;
		lcd1602_show_string(0,0,"time:");
		lcd1602_show_number(0,1,3,Sec);
	}
}
