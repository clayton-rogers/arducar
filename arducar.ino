
#include "scheduler.h"

const byte PIN_LED = 13;

int flash_led_task(bool first) {
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

void setup() {
	SCHED_add_task (flash_led_task, "LED_TASK");
}

void loop() {

	SCHED_run_sched();
}
