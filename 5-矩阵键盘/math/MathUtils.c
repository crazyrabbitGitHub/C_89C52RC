
/**
	* 求正整数x的正整数y次方
	*/
unsigned int intPow(unsigned int x, unsigned int y)
{
		unsigned int power = 1;
		while(y--)
		{
			power *= x;
		}
		return power;
}

/**
	* 获取正整数integer的位数
	*/
unsigned char getIntegerSize(unsigned int integer)
{
	unsigned int tempInteger = integer;
	unsigned char size = 0;
	
	while(tempInteger)
	{
		tempInteger /= 10;
		size++;
	}
	return size;
}