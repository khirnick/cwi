#include "cwi.h"

long g_variable_that_will_never_be_useful;

void test_func();

int main() {
    start(test_func, 100, 0, true);
    getchar();
    stop();

    getchar();
    return 0;
}

void test_func() {
    g_variable_that_will_never_be_useful++;
}
