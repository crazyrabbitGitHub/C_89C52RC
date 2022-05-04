#include <REGX52.H>
#include "Delay.h"

unsigned char MatrixKey()
{
	unsigned char keyNumber = 0;
	
	while(!keyNumber)
	{
		P1 = 0xFF;
		P1_3 = 0;
		if(P1_7 == 0){DelayNms(20); while(P1_7 == 0);DelayNms(20);keyNumber = 0 * 4 + 1;}
		if(P1_6 == 0){DelayNms(20); while(P1_6 == 0);DelayNms(20);keyNumber = 1 * 4 + 1;}
		if(P1_5 == 0){DelayNms(20); while(P1_5 == 0);DelayNms(20);keyNumber = 2 * 4 + 1;}
		if(P1_4 == 0){DelayNms(20); while(P1_4 == 0);DelayNms(20);keyNumber = 3 * 4 + 1;}
		
		P1 = 0xFF;
		P1_2 = 0;
		if(P1_7 == 0){DelayNms(20); while(P1_7 == 0);DelayNms(20);keyNumber = 0 * 4 + 2;}
		if(P1_6 == 0){DelayNms(20); while(P1_6 == 0);DelayNms(20);keyNumber = 1 * 4 + 2;}
		if(P1_5 == 0){DelayNms(20); while(P1_5 == 0);DelayNms(20);keyNumber = 2 * 4 + 2;}
		if(P1_4 == 0){DelayNms(20); while(P1_4 == 0);DelayNms(20);keyNumber = 3 * 4 + 2;}
		
		P1 = 0xFF;
		P1_1 = 0;
		if(P1_7 == 0){DelayNms(20); while(P1_7 == 0);DelayNms(20);keyNumber = 0 * 4 + 3;}
		if(P1_6 == 0){DelayNms(20); while(P1_6 == 0);DelayNms(20);keyNumber = 1 * 4 + 3;}
		if(P1_5 == 0){DelayNms(20); while(P1_5 == 0);DelayNms(20);keyNumber = 2 * 4 + 3;}
		if(P1_4 == 0){DelayNms(20); while(P1_4 == 0);DelayNms(20);keyNumber = 3 * 4 + 3;}
		
		P1 = 0xFF;
		P1_0 = 0;
		if(P1_7 == 0){DelayNms(20); while(P1_7 == 0);DelayNms(20);keyNumber = 0 * 4 + 4;}
		if(P1_6 == 0){DelayNms(20); while(P1_6 == 0);DelayNms(20);keyNumber = 1 * 4 + 4;}
		if(P1_5 == 0){DelayNms(20); while(P1_5 == 0);DelayNms(20);keyNumber = 2 * 4 + 4;}
		if(P1_4 == 0){DelayNms(20); while(P1_4 == 0);DelayNms(20);keyNumber = 3 * 4 + 4;}
	}
	
	return keyNumber;
}