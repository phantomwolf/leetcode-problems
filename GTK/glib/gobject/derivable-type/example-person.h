#ifndef EXAMPLE_PERSON_H
#define EXAMPLE_PERSON_H

#include <glib-object.h>

G_BEGIN_DECLS

#define EXAMPLE_TYPE_PERSON example_person_get_type ()
G_DECLARE_DERIVABLE_TYPE (ExamplePerson, example_person, EXAMPLE, PERSON, GObject)

struct _ExamplePersonClass
{
    GObjectClass parent_class;

    /* Class virtual function fields */
    void (* show) (ExamplePerson *self);

    /* Padding to allow adding up to 12 new virtual functions without breaking ABI */
    gpointer padding[12];
};


ExamplePerson *example_person_new (void);

void example_person_show (ExamplePerson *self);

G_END_DECLS

#endif
