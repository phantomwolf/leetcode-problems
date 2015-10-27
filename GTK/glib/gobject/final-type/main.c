#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "example-person.h"


int main (int argc, char *argv[])
{
    srand (time (0));

    ExamplePerson *person;

    GValue val = G_VALUE_INIT;
    g_value_init (&val, G_TYPE_STRING);
    g_value_set_string (&val, "dummy");

    /* Initialize */
    person = example_person_new (&val);
    
    /* Properties */
    g_object_get_property (G_OBJECT (person), "FULL-NAME", &val);
    printf("property FULL-NAME: %s\n", g_value_get_string (&val));

    g_value_set_string (&val, "John Smith");
    g_object_set_property (G_OBJECT (person), "FULL-NAME", &val);
    g_value_set_string (&val, "");

    g_object_get_property (G_OBJECT (person), "FULL-NAME", &val);
    printf("property FULL-NAME: %s\n", g_value_get_string (&val));

    /* Release resources */
    g_value_unset (&val);

    /* Methods */
    printf ("age: %d\n", example_person_get_age (person));
    example_person_set_age (person, 18);
    printf ("age: %d\n", example_person_get_age (person));

    example_person_show_secret (person);

    g_object_unref (person);

    return 0;
}
