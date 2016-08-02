#include "cwi.h"

static HANDLE TIMER_HANDLE;
static clock_t START_CLOCK;
static uint64_t COUNTER;
static double EXECUTE_DURATION;
static bool IS_PRINT;
static void (*F_TO_CALL)();

void void_default_function() {
    return;
}

void set_variables_initial_values() {
    TIMER_HANDLE        = 0;
    START_CLOCK         = 0;
    COUNTER             = 0;
    EXECUTE_DURATION    = 0;
    IS_PRINT            = false;
    F_TO_CALL           = void_default_function;
}

void* function_connected_to_timer(void* f_to_call(), bool TimerOrWaitFired) {
    f_to_call();
    COUNTER++;
}

void start(void* f, short frequency, uint64_t duration, bool is_print) {
    set_variables_initial_values(); 
    IS_PRINT = is_print;
    set_calling_function(f);
    start_execution(frequency, duration);
}

void stop() {
    DeleteTimerQueueTimer(NULL, TIMER_HANDLE, NULL);
    EXECUTE_DURATION = (clock() - START_CLOCK) / (double) CLOCKS_PER_SEC;

    if (IS_PRINT)
        print_results(COUNTER, EXECUTE_DURATION);
}

void set_calling_function(void *f) {
    F_TO_CALL = f;
}

void start_execution(short frequency, uint64_t duration) {
    START_CLOCK = clock();

    CreateTimerQueueTimer(&TIMER_HANDLE, NULL, function_connected_to_timer, F_TO_CALL, 0, frequency, WT_EXECUTEDEFAULT);

    if (duration > 0) {
        sleeping_with_duration(START_CLOCK, duration);
        stop();
    }
}

void sleeping_with_duration(clock_t start_clock, double duration) {
    while (true) {
        if (clock() - start_clock > duration)
            return;
    }
}

void print_results(uint64_t counter, double duration) {
    double frequency = counter / duration;

    printf("+ + + + + + + + + + + + +\n"
                   "+ RESULTS:\t\t+\n"
                   "+ DURATION (s): %.2f\t+\n"
                   "+ COUNT: %" PRIu64 "\t\t+\n"
                   "+ FREQ (f/s): %.4f\t+\n"
                   "+ + + + + + + + + + + + +", duration, counter, frequency);
}
