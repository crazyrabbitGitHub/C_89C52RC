#include <REGX52.H>
#include <INTRINS.H>

unsigned char arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void Nixie(unsigned char location, number);
void DelayNms(unsigned int n);
void DelayNus(unsigned char n);

void main()
{
	unsigned char i;
	while(1)
	{
		for(i = 0; i < 8; i++)
		{
			Nixie(i, i);
		}
	}
}

void Nixie(unsigned char location ,number)
{
	unsigned tempVar = location;
	if(location > 9 || location < 0 || number < 0 || number > 9)
	{
		return;
	}
	P2_2 = tempVar % 2;
	tempVar = tempVar / 2;
	P2_3 = tempVar % 2;
	tempVar = tempVar / 2;
	P2_4 = tempVar % 2;
	P0 = arr[number];
	
	DelayNus(100);
	P0 = 0x00;
}

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
