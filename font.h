#ifndef _font_h
#define _font_h

#include <Arduino.h>

// This is a 8x6 font.
// Typically the bottom and right rows of pixels will be blank.

struct Font_char_t {
	byte character[6];
};

Font_char_t FONT_get_char(char c);

#endif // _font_h
