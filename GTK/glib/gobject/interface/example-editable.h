#ifndef __EXAMPLE_EDITABLE_H__
#define __EXAMPLE_EDITABLE_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define EXAMPLE_TYPE_EDITABLE example_editable_get_type ()
G_DECLARE_INTERFACE (ExampleEditable, example_editable, EXAMPLE, EDITABLE, GObject)

struct _ExampleEditableInterface
{
    GTypeInterface parent_iface;

    void (*hello) (ExampleEditable *self);
};

void example_editable_hello (ExampleEditable *self);

G_END_DECLS

#endif
