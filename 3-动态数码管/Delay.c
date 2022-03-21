#include <INTRINS.H>

void DelayNms(unsigned int n)		//@11.0592MHz
{
	unsigned char i, j;
	
	while(n--)
	{
		_nop_();
		_nop_();
		_nop_();
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
	}
}

void DelayNus(unsigned char n)		//@11.0592MHz
{
	while(n--)
	{
		_nop_();
		_nop_();
		_nop_();
	}
}