#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "example-person.h"

/* Private structure definition */
typedef struct {
    gint secret_code;
} ExamplePersonPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (ExamplePerson, example_person, G_TYPE_OBJECT)

static void
example_person_init (ExamplePerson *self)
{
    puts ("ExamplePerson init...");
    ExamplePersonPrivate *priv = example_person_get_instance_private (EXAMPLE_PERSON (self));
    priv->secret_code = rand();
    printf ("ExamplePerson: Setting secret code to %d...\n", priv->secret_code);
}

static void
example_person_finalize (GObject *gobject)
{
    puts ("ExamplePerson finalizing...");
}

static void
example_person_real_show (ExamplePerson *self)
{
    ExamplePersonPrivate *priv = example_person_get_instance_private (self);
    printf("ExamplePerson secret: %d\n", priv->secret_code);
}

static void
example_person_class_init (ExamplePersonClass *klass)
{
    puts ("ExamplePerson class init...");

    klass->show = example_person_real_show;

    GObjectClass *object_class = G_OBJECT_CLASS (klass);
    object_class->finalize = example_person_finalize;
}

ExamplePerson *example_person_new (void)
{
    ExamplePerson *obj;
    obj = g_object_new (EXAMPLE_TYPE_PERSON, NULL);
    return obj;
}

void example_person_show (ExamplePerson *self)
{
    ExamplePersonClass *klass = EXAMPLE_PERSON_GET_CLASS (self);
    return klass->show (self);
}
