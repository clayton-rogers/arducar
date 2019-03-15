
#include "scheduler.h"
#include "nokia.h"

const byte PIN_LED = 13;
const byte PIN_N_SCE = 11;
const byte PIN_N_DC = 10;
const byte PIN_N_DATA = 9;
const byte PIN_N_CLK = 8;
const byte PIN_N_RST = 12;

time_t flash_led_task(bool first) {
	if (first) {
		pinMode(PIN_LED, OUTPUT);
	}

	static bool is_on = false;

	if (is_on) {
		is_on = false;
		digitalWrite(PIN_LED, LOW);
	} else {
		is_on = true;
		digitalWrite(PIN_LED, HIGH);
	}

	return 500;
}

time_t nokia_task(bool first) {
	if (first) {
		NOKIA_init(PIN_N_SCE, PIN_N_DC, PIN_N_CLK, PIN_N_DATA, PIN_N_RST);
		return 1000;
	}

	static bool is_white = false;

	static byte data_a[] = {
		0x7f, 0x08, 0x08, 0x08, 0x7f, 0x00, // H
		0x7F, 0x49, 0x49, 0x49, 0x41, 0x00, // E
		0x7F, 0x40, 0x40, 0x40, 0x40, 0x00, // L
		0x7F, 0x40, 0x40, 0x40, 0x40, 0x00, // L
		0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, // O
	};
	static byte data_b[] = {
		0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00, // W
		0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, // O
		0x7F, 0x09, 0x19, 0x29, 0x46, 0x00, // R
		0x7F, 0x40, 0x40, 0x40, 0x40, 0x00, // L
		0x41, 0x7F, 0x41, 0x41, 0x3E, 0x00, // D
	};

	if (is_white) {
		is_white = false;
		for (int j = 0; j < 2; ++j) {
			for (int i = 0; i < 6; ++i) {
				NOKIA_set_cursor_pos(j*7,i);
				NOKIA_put_data(&data_a[0], sizeof(data_a));
			}
		}
	} else {
		is_white = true;
		for (int j = 0; j < 2; ++j) {
			for (int i = 0; i < 6; ++i) {
				NOKIA_set_cursor_pos(j*7,i);
				NOKIA_put_data(&data_b[0], sizeof(data_b));
			}
		}
	}

	return 1000;
}

void setup() {
	SCHED_add_task(flash_led_task, "LED_TASK");
	SCHED_add_task(nokia_task, "NOKIA");
}

void loop() {

	SCHED_run_sched();

}
