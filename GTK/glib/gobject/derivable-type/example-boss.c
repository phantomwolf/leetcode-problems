#include <stdio.h>
#include "example-boss.h"

typedef struct {
    gint secret_code;
} ExampleBossPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (ExampleBoss, example_boss, EXAMPLE_TYPE_PERSON)

static void
example_boss_finalize (GObject *object)
{
    puts ("ExampleBoss finalizing...");
}

static void
example_boss_real_show (ExampleBoss *self)
{
    ExampleBossPrivate *priv = example_boss_get_instance_private (self);
    printf ("ExampleBoss secret: %d\n", priv->secret_code);
}

static void
example_boss_class_init (ExampleBossClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS (klass);
    object_class->finalize = example_boss_finalize;

    EXAMPLE_PERSON_CLASS (klass)->show = (void *) example_boss_real_show;
}

static void
example_boss_init (ExampleBoss *self)
{
    puts ("ExampleBoss init...");
    ExampleBossPrivate *priv = example_boss_get_instance_private (EXAMPLE_BOSS (self));
    priv->secret_code = 9527;
    puts ("ExampleBoss: Setting secret code to 9527...");
}
