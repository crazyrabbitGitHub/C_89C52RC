#include <REGX52.H>
#include "LCD1602.h"

void main()
{
	lcd1602_init();
	lcd1602_show_string(0,1, "hello worldasdfasdfasdfasdfasdfasdfasdfasdfs");
	while(1);
}