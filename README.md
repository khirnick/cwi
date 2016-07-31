# cwi
## What is cwi?
<i>cwi - call with interval</i>. You can call functions with specified interval in your C-code.
##Try it out
1. Download [click](https://github.com/hitryy/cwi) files `cwi.h` and `cwi.c`
2. Put `cwi.h` and `cwi.c` in your project's folder
3. Include header file `#include 'cwi.h'`
4. Start using cwi:
  ~~~c
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
  ~~~
