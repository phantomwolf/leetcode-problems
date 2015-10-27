#include <stdio.h>
#include <stdlib.h>
#include "example-person.h"

/* Private structure */
typedef struct
{
    gint secret_code;
} ExamplePersonPrivate;

// Since G_DECLARE_FINAL_TYPE won't define it, 
// we must define it ourselves
struct _ExamplePerson
{
        GObject     parent_instance;

        gint        age;
        GValue      full_name;
};

// A convenience macro for type implementations, it:
//  - declares a class initialization function
//  - declares an instance initialization function
//  - declares a static variable named t_n_parent_class pointing to the parent class
//  - defines a *_get_type() function
G_DEFINE_TYPE_WITH_PRIVATE (ExamplePerson, example_person, G_TYPE_OBJECT)

// GObject property names. The first one must have a value of 1
// N_PROPS can be used as the total amount of properties later.
enum {
    PROP_FULL_NAME = 1,
    N_PROPS
};

// An array holding all the properties
static GParamSpec *obj_props[N_PROPS] = { NULL, };

static void
example_person_set_property (GObject        *obj,
                             guint           prop_id,
                             const GValue   *value,
                             GParamSpec     *pspec)
{
    ExamplePerson *self = EXAMPLE_PERSON (obj);

    switch (prop_id) {
        case PROP_FULL_NAME:
            g_value_copy (value, &self->full_name);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID (obj, prop_id, pspec);
            break;
    }
}

static void
example_person_get_property (GObject        *obj,
                             guint           prop_id,
                             GValue         *value,
                             GParamSpec     *pspec)
{
    ExamplePerson *self = EXAMPLE_PERSON (obj);

    switch (prop_id) {
        case PROP_FULL_NAME:
            g_value_copy (&self->full_name, value);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID (obj, prop_id, pspec);
            break;
    }
}

static void
example_person_finalize (GObject *obj)
{
    ExamplePerson *self = EXAMPLE_PERSON (obj);
    g_value_unset (&self->full_name);
}

// Class initialization
static void
example_person_class_init (ExamplePersonClass *cls)
{
    GObjectClass *obj_cls = G_OBJECT_CLASS (cls);

    obj_cls->set_property = example_person_set_property;
    obj_cls->get_property = example_person_get_property;
    obj_cls->finalize     = example_person_finalize;

    obj_props[PROP_FULL_NAME] =
        g_param_spec_string ("FULL-NAME",
                             "Full Name",
                             "The full name of the person",
                             "",
                             (G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));
    g_object_class_install_properties (obj_cls, N_PROPS, obj_props);
}

// Instance initialization
static void
example_person_init (ExamplePerson *self)
{
    ExamplePersonPrivate *priv = example_person_get_instance_private (self);
    priv->secret_code = rand();
    printf ("setting secret code: %d\n", priv->secret_code);

    self->age = -1;
    g_value_init (&self->full_name, G_TYPE_STRING);
}

// Non-virtual public function
ExamplePerson *example_person_new (const GValue *full_name)
{
    ExamplePerson *obj = g_object_new (EXAMPLE_TYPE_PERSON, NULL);
    if (G_IS_VALUE (full_name)) {
        g_object_set_property (G_OBJECT (obj), "FULL-NAME", full_name);
    }
    return obj;
}

gint
example_person_get_age (ExamplePerson *self)
{
    return self->age;
}

// Non-virtual public function
void
example_person_set_age (ExamplePerson *self, gint age)
{
    self->age = age;
}

void example_person_show_secret (ExamplePerson *self)
{
    ExamplePersonPrivate *priv = example_person_get_instance_private (self);
    printf ("secret code: %d\n", priv->secret_code);
}
