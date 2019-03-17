
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

const Task_t* blink_task;

time_t nokia_task(bool first) {
	if (first) {
		NOKIA_init(PIN_N_SCE, PIN_N_DC, PIN_N_CLK, PIN_N_DATA, PIN_N_RST);
		return 1000;
	}
	static int count = 100;
	NOKIA_put_string("TEXT ");
	if (count == 0) {
		Run_time_t run_time = blink_task->run_time;
		NOKIA_all_white();
		char buffer[CHAR_PER_LINE];

		NOKIA_set_cursor_pos(0,0);
		sprintf(buffer, "%lu", run_time.millis);
		NOKIA_put_string(buffer);

		NOKIA_set_cursor_pos(0,1);
		sprintf(buffer, "%lu", run_time.micros);
		NOKIA_put_string(buffer);

		return 1000000;
	}
	--count;
	return 250;
}

void setup() {
	blink_task = SCHED_add_task(flash_led_task, "LED_TASK");
	SCHED_add_task(nokia_task, "NOKIA");
}

void loop() {

	SCHED_run_sched();

}
