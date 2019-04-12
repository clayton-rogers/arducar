
#include "scheduler.h"
#include "nokia.h"
#include "pins.h"
#include "range.h"

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
		RANGE_init(3, 4); // TRIG, ECHO
		return 1000;
	}

	static int count = 0;
	count++;
	if (count == 200) {
		count = 0;

		const Run_time_t runtime = SCHED_get_task_run_time();
		char buffer[50];
		NOKIA_all_white();
		NOKIA_set_cursor_pos(0,0);
		sprintf(buffer, "%lu", runtime.millis);
		NOKIA_put_string(buffer);

		NOKIA_set_cursor_pos(0,1);
		sprintf(buffer, "%lu", runtime.micros);
		NOKIA_put_string(buffer);

		return 20000;
	}

	NOKIA_all_white();
	NOKIA_set_cursor_pos(0,0);
	NOKIA_put_string("Range (m)");
	NOKIA_set_cursor_pos(0,1);
	const double range = RANGE_get();
	String range_str = String(range);
	NOKIA_put_string(range_str.c_str());

	return 500;
}

void setup() {
	SCHED_add_task(flash_led_task);
	SCHED_add_task(nokia_task);
}

void loop() {

	SCHED_run_sched();

}
