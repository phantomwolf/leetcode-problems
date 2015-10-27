#include "example-editable.h"

G_DEFINE_INTERFACE (ExampleEditable, example_editable, G_TYPE_OBJECT)

static void example_editable_default_init (ExampleEditableInterface *iface)
{
    /* add properties and signals to the interface here */
}

void example_editable_hello (ExampleEditable *self)
{
    ExampleEditableInterface *iface;

    g_return_if_fail (EXAMPLE_IS_EDITABLE (self));

    iface = EXAMPLE_EDITABLE_GET_IFACE (self);
    g_return_if_fail (iface->hello != NULL);
    iface->hello (self);
}
