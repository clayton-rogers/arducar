
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

	static char a = 0;
	static int count = 0;

	NOKIA_put_char(a);

	if (a == 127) {
		a = 0;
	} else {
		++a;
	}

	++count;
	if (count == CHAR_PER_SCREEN) {
		count = 0;
		return 60000;
	} else {
		return 25;
	}
}

void setup() {
	SCHED_add_task(flash_led_task, "LED_TASK");
	SCHED_add_task(nokia_task, "NOKIA");
}

void loop() {

	SCHED_run_sched();

}
