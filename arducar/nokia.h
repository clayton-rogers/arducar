#ifndef _nokia_h
#define _nokia_h

#include <Arduino.h>

extern const int CHAR_PER_LINE;
extern const int NUMBER_LINES;
extern const int CHAR_PER_SCREEN;

// NOTE: needs to be called within the first 30 ms afte power is applied
void NOKIA_init(int pin_sce, int pin_dc, int pin_clk, int pin_data, int pin_rst);

// TODO: write fn etc

void NOKIA_set_cursor_pos(int x, int y);
void NOKIA_put_char(char c);
void NOKIA_put_string(const char* str);

void NOKIA_put_data(byte* data, int len);

void NOKIA_all_white();
void NOKIA_all_black();

#endif // _nokia_h
