#include <REGX52.H>

void Timer0_init(void)
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0xCD;		//设置定时初始值
	TH0 = 0xD4;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}
// 定时器0运行
//void Timer0_Routine() interrupt 1
//{
//	static unsigned int T0Count = 0;
//	TL0 = 0x66;		//设置定时初始值
//	TH0 = 0xFC;		//设置定时初始值
//	T0Count++;
//	if(T0Count == 1000)
//	{
//		T0Count = 0;
//		lcd1602_show_number(0,0,key);
//	}
//}

void Timer1_init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x10;		//设置定时器模式
	TL1 = 0x66;		//设置定时初始值
	TH1 = 0xFC;		//设置定时初始值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	ET1 = 1;
	EA = 1;
	PT1 = 0;
}

// 定时器
//void Timer1_Routin() interrupt 3
//{
//	static unsigned int T1Count = 0;
//	static unsigned int Sec = 0;
//	TL1 = 0x66;		//设置定时初始值
//	TH1 = 0xFC;		//设置定时初始值
//	T1Count++;
//	if(T1Count >= 1000)
//	{
//		T1Count = 0;
//		Sec++;
//		lcd1602_show_string(0,0,"time:");
//		lcd1602_show_number(0,1,3,Sec);
//	}
//}


