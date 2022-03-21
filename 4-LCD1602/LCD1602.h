#ifndef __LCD1602_H__
#define __LCD1602_H__

#include "Delay.h"

sbit LCD1602_RS = P2^6;
sbit LCD1602_RW = P2^5;
sbit LCD1602_E = P2^7;
#define LCD1602_DATAPORT   P0

typedef unsigned char u8;

void lcd1602_init(void);
void lcd1602_show_string(u8 x, u8 y, u8 *str);
void lcd1602_show_number(u8 x, u8 y, u8 number);
void lcd1602_clear(void);

#endif