#ifndef _scheduler_h
#define _scheduler_h

#include <Arduino.h>

// unsigned long type is used by all the built-in fns to represent time
// It is used to represent milliseconds here.
typedef unsigned long time_t;

struct Run_time_t {
	time_t millis = 0;
	time_t micros = 0;
};

// Task functions are expected to return the number of milliseconds until
// their next invocation. Note this time is measure from the time it is invoked,
// not the time is returns. So a 500 ms return will always run at 2Hz even if it
// takes multiple milliseconds to run.
//
// The "first" parameter is used by the task to perform one time initialisation.
// The very first time the task is called it will be set to true, and every time
// after will be set to false.
typedef time_t (*Task_fn_t)(bool first);

struct Task_t {
	Task_fn_t callback;
	time_t next_run = 0;
	Run_time_t run_time;
};

const Task_t* SCHED_add_task(Task_fn_t function);
void          SCHED_run_sched(void);
Run_time_t    SCHED_get_task_run_time(void);

#endif
