#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "example-boss.h"

void test(ExamplePerson *obj)
{
    ExamplePersonClass *klass = EXAMPLE_PERSON_GET_CLASS (obj);
    klass->show (obj);
}

int main ()
{
    srand (time (0));

    ExampleBoss *obj = g_object_new (EXAMPLE_TYPE_BOSS, NULL);
    test ((ExamplePerson *) obj);

    g_object_unref (obj);

    return 0;
}
