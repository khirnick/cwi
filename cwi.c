#include "cwi.h"

HANDLE TIMER_HANDLE;
clock_t START_CLOCK;
uint64_t COUNTER;
double EXECUTE_DURATION;
bool IS_PRINT;
void (*F_TO_CALL)();

void* function_connected_to_timer(PVOID lpParameter, BOOLEAN timerOrWaitFired) {
    F_TO_CALL();
    COUNTER++;
}

void start(void* f, short frequency, uint64_t duration, bool is_print) {
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

    CreateTimerQueueTimer(&TIMER_HANDLE, NULL, function_connected_to_timer, NULL, 0, frequency, WT_EXECUTEDEFAULT);

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
