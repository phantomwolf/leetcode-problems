#include "example-chinese.h"

int main (int argc, char *argv[])
{
    ExampleChinese *obj;
    obj = g_object_new (EXAMPLE_TYPE_CHINESE, NULL);

    g_object_unref (obj);
    return 0;
}
