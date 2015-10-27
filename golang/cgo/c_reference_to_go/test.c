#include <stdio.h>
#include "test.h"

void caller(int (*func)(int id))
{
    puts("caller...");
    func(9527);
}

void some_c_callback()
{
    puts("calling go function...");
    go_callback(386);
    puts("finished");
}
