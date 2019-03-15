#include "nokia.h"

/*****************************************************************************
 * Constants and types
 ****************************************************************************/

const int SCREEN_WIDTH = 84;
const int CHAR_WIDTH = 6;
const int CHAR_HEIGHT = 8;
const int SCREEN_HEIGHT = 6;
const int SCREEN_SIZE = SCREEN_WIDTH * SCREEN_HEIGHT;

/***** BASIC or EXTENDED instruction set *****/
const byte COMMAND_FUNCTION_SET = 0x20;
const byte BIT_CHIP_POWER_DOWN = 0x04; // Active is low
const byte BIT_VERTICAL_ADDRESSING = 0x02; // Horizonal is low
const byte BIT_EXTENDED_INSTRUCTION = 0x01; // Basic instruction is low

/***** BASIC instruction set *****/
const byte COMMAND_DISPLAY_CONTROL = 0x08;
const byte BIT_DISPLAY_BLANK = 0x00;
const byte BIT_NORMAL_MODE = 0x04;
const byte BIT_ALL_ON = 0x01;
const byte BIT_INVERSE = 0x05;

const byte COMMAND_SET_Y_ADDR = 0x40;
// | with 0 .. 7

const byte COMMAND_SET_X_ADDR = 0x80;
// | with 0 .. 127

/***** EXTENDED instruction set *****/
const byte COMMAND_TEMPERATURE_CONTROL = 0x04;
// | with temp co-efficient 0 .. 3

const byte COMMAND_BIAS_SYSTEM = 0x10;
// | with 0 .. 7
// | value is = (7 - n)

const byte COMMAND_VOP = 0x80;
// | with 0 .. 127

/*****************************************************************************
 * Static variables
 ****************************************************************************/
//static byte screen[SCREEN_SIZE];
static int PIN_SCE;  // serial enable
static int PIN_DC;   // data/command
static int PIN_CLK;  // clock
static int PIN_DATA; // data
static int PIN_RST;  // reset (MUST BE RESET BEFORE USING)

/*****************************************************************************
 * Static functions
 ****************************************************************************/
static void send_byte(byte value, bool is_command) {
	digitalWrite(PIN_SCE, LOW);

	// Don't actually need this until bit 0 but might as well do it now.
	digitalWrite(PIN_DC, (is_command ? LOW : HIGH));

	// Make sure clock starts low
	digitalWrite(PIN_CLK, LOW);

	// Bit shift out the data
	for (int i = 7; i >= 0; --i) {
		digitalWrite(PIN_DATA, (value & (1 << i) ? HIGH : LOW));
		digitalWrite(PIN_CLK, HIGH);
		digitalWrite(PIN_CLK, LOW);
	}

	digitalWrite(PIN_SCE, HIGH);
}

static void send_command(byte command) {
	send_byte(command, true);
}

static void send_data(byte data) {
	send_byte(data, false);
}

/*****************************************************************************
 * Exported functions
 ****************************************************************************/
void NOKIA_init(int pin_sce, int pin_dc, int pin_clk, int pin_data, int pin_rst) {
	PIN_SCE  = pin_sce;
	PIN_DC   = pin_dc;
	PIN_CLK  = pin_clk;
	PIN_DATA = pin_data;
	PIN_RST  = pin_rst;

	pinMode(PIN_SCE,  OUTPUT);
	pinMode(PIN_DC,   OUTPUT);
	pinMode(PIN_CLK,  OUTPUT);
	pinMode(PIN_DATA, OUTPUT);
	pinMode(PIN_RST,  OUTPUT);

	// Apply reset
	digitalWrite(PIN_RST, LOW);
	digitalWrite(PIN_RST, HIGH);

	// Set power up, extended set
	send_command(COMMAND_FUNCTION_SET | BIT_EXTENDED_INSTRUCTION);

	// Set Vop value
	send_command(COMMAND_VOP | 56);

	// Set temperature control
	send_command(COMMAND_TEMPERATURE_CONTROL | 0);

	// Set bias system
	send_command(COMMAND_BIAS_SYSTEM | 0x04); // n = 3, (1 : 40)

	// Switch back to basic set
	send_command(COMMAND_FUNCTION_SET);

	// Set normal mode
	send_command(COMMAND_DISPLAY_CONTROL | BIT_NORMAL_MODE);
	//send_command(COMMAND_DISPLAY_CONTROL | BIT_ALL_ON);

	// Clear out the ram with checkerboard
	for (int i = 0; i < SCREEN_SIZE; i+=2) {
		send_data(0xAA);
		send_data(0x55);
	}

	// Reset cursor to 0, 0
	send_command(COMMAND_SET_X_ADDR | 0);
	send_command(COMMAND_SET_Y_ADDR | 0);
}

void NOKIA_all_white() {
	// Set all pixels white
	for (int i = 0; i < SCREEN_SIZE; ++i) {
		send_data(0x00);
	}
}

void NOKIA_all_black() {
	// Set all pixels to black
	for (int i = 0; i < SCREEN_SIZE; ++i) {
		send_data(0xFF);
	}
}

void NOKIA_set_cursor_pos(int x, int y) {
	if (y < 0 || y > SCREEN_HEIGHT ||
	    x < 0 || x > SCREEN_WIDTH / CHAR_WIDTH) {
			return;
		}

	send_command(COMMAND_SET_X_ADDR | x*CHAR_WIDTH);
	send_command(COMMAND_SET_Y_ADDR | y);
}

void NOKIA_put_data(byte* data, int len) {
	for (int i = 0; i < len; ++i) {
		send_data(data[i]);
	}
}
