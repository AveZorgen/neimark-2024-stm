#include "cpp-code.h"
#include <map>
#include <string>
#include <stdio.h>

#include "stm32f1xx_hal.h"

static const unsigned char cpp_text[] = "Hello, stm32 C++ developer!\r\n";

void function_to_investigate()
{
    std::map<std::string, int> m;
    for (int i = 1; i <= 10; ++i)
    {
        m[std::to_string(i)] = i;
    }
}

extern uint32_t malloc_counter;
extern uint32_t free_counter;
extern uint32_t _sbrk_counter;

void print_stat()
{
    // Some code here should print statistic of _sbrk, malloc, free usage
    printf("%s", cpp_text);
    printf("_sbrk_counter: %lu\r\n", _sbrk_counter);
    printf("malloc_counter: %lu\r\n", malloc_counter);
    printf("free_counter: %lu\r\n", free_counter);
}

void cpp_code_entry_point()
{
    function_to_investigate();
    print_stat();
}
