#ifndef _range_h
#define _range_h

// Initializes the range module and sets the pins to use for comuication
void RANGE_init(int pin_trig, int pin_echo);

// Gets the current range to target in meters
float RANGE_get();


#endif
