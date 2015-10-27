#ifndef EXAMPLE_BOSS_H
#define EXAMPLE_BOSS_H

#include <glib-object.h>
#include "example-person.h"

G_BEGIN_DECLS

#define EXAMPLE_TYPE_BOSS example_boss_get_type ()
G_DECLARE_DERIVABLE_TYPE (ExampleBoss, example_boss, EXAMPLE, BOSS, ExamplePerson)

struct _ExampleBossClass
{
    ExamplePersonClass parent_class;

    void (*show) (ExampleBoss *self);

    /* padding */
    gpointer padding[12];
};

G_END_DECLS

#endif
