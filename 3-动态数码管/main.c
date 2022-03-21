#include "Nixie.h"

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
