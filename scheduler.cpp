#include "scheduler.h"

/****************************************************************************
 * Constants and types
 ****************************************************************************/
// Maximum number of threads
static const int NUM_T = 10;

/****************************************************************************
 * Static variables
 ****************************************************************************/
static Task_t tasks[NUM_T];
static byte current_num_tasks = 0;

/****************************************************************************
 * Static functions
 ****************************************************************************/
static Task_t* get_next_task() {
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
	return &tasks[next_task];
}

static void wait_or_sleep(time_t milliseconds) {
	// TODO: this function should put the processor to sleep if there is a long enough wait
	delay(milliseconds);
}

/****************************************************************************
 * Exported functions
 ****************************************************************************/
const Task_t* SCHED_add_task(Task_fn_t function) {
	const Task_t* ret = nullptr;
	if (current_num_tasks < NUM_T) {
		tasks[current_num_tasks].callback = function;
		ret = &tasks[current_num_tasks];
		current_num_tasks++;
	}

	return ret;
}

// The current task gets saved here to be used when the current run time is queried
static Task_t* current_task;
void SCHED_run_sched() {
	// First init each task
	for (int i = 0; i < current_num_tasks; ++i) {
		tasks[i].next_run = tasks[i].callback(true);
	}

	// Loop forever calling each task
	while (1) {
		current_task = get_next_task();
		const time_t next_time = current_task->next_run;

		const time_t current_time = millis();

		if (next_time > current_time) {
			const time_t wait_time = next_time - current_time;
			wait_or_sleep(wait_time);
		}

		// Run the task
		time_t before_time = micros();
		const time_t delta_time = current_task->callback(false);
		time_t after_time = micros();

		// Update the next time to run
		current_task->next_run += delta_time;

		// Update the CPU usage
		time_t cpu_time = 0;
		if (after_time > before_time) {
			// If micros rolls over, just don't count that usage.
			cpu_time = after_time - before_time;
		}
		current_task->run_time.micros += cpu_time;
		while (current_task->run_time.micros > 1000) {
			++current_task->run_time.millis;
			current_task->run_time.micros -= 1000;
		}
	}
}

Run_time_t SCHED_get_task_run_time(void) {
	return current_task->run_time;
}
