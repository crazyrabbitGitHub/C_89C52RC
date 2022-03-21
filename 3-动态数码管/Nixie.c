#include <REGX52.H>
#include "Delay.h"

unsigned char arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

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