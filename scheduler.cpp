#include "scheduler.h"

/****************************************************************************
 * Constants and types
 ****************************************************************************/
// Maximum number of threads
static const int NUM_T = 10;

struct Task_t {
	Task_fn_t callback;
	const char* name;
	time_t next_run = 0;
};

/****************************************************************************
 * Static variables
 ****************************************************************************/
static Task_t tasks[NUM_T];
static byte current_num_tasks = 0;

/****************************************************************************
 * Static functions
 ****************************************************************************/
static size_t get_next_task() {
	size_t next_task = NUM_T;
	time_t next_time = 0x7FFFFFFF;

	for (int i = 0; i < current_num_tasks; ++i) {
		if (tasks[i].next_run < next_time) {
			next_time = tasks[i].next_run;
			next_task = i;
		}
	}

	if (next_task == NUM_T) {
		// error condition, lock up forever
		delay(100000);
	}
	return next_task;
}

static void wait_or_sleep(time_t milliseconds) {
	// TODO: this function should put the processor to sleep if there is a long enough wait
	delay(milliseconds);
}

/****************************************************************************
 * Exported functions
 ****************************************************************************/
void SCHED_add_task(Task_fn_t function, const char* const task_name) {
	if (current_num_tasks < NUM_T) {
		tasks[current_num_tasks].callback = function;
		tasks[current_num_tasks].name = task_name;

		current_num_tasks++;
	}
}

void SCHED_run_sched() {
	// First init each task
	for (int i = 0; i < current_num_tasks; ++i) {
		tasks[i].next_run = tasks[i].callback(true);
	}

	// Loop forever calling each task
	while (1) {
		const size_t current_task = get_next_task();
		const time_t next_time = tasks[current_task].next_run;

		const time_t current_time = millis();

		if (next_time > current_time) {
			const time_t wait_time = next_time - current_time;
			wait_or_sleep(wait_time);
		}

		const time_t delta_time = tasks[current_task].callback(false);
		tasks[current_task].next_run += delta_time;
	}
}
