#ifndef CWI_CWI_H
#define CWI_CWI_H

#define _WIN32_WINNT 0x0601

#include <windows.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include "time.h"
#include "stdio.h"
#include <stdarg.h>

void start(void* f, short frequency, uint64_t duration, bool is_print);
void stop();

static void void_default_function();
static void set_variables_initial_values();
static void* function_connected_to_timer(void* f_to_call(), bool TimerOrWaitFired);
static void start_execution(short frequency, uint64_t duration);
static void sleeping_with_duration(clock_t start_clock, double duration);
static void print_results(uint64_t counter, double duration);

#endif
