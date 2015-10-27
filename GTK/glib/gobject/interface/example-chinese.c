#include "example-editable.h"
#include "example-chinese.h"

struct _ExampleChinese
{
    GObject parent_instance;
};


static void example_chinese_editable_interface_init (ExampleEditableInterface *iface);

G_DEFINE_TYPE_WITH_CODE (ExampleChinese, example_chinese, G_TYPE_OBJECT,
                        G_IMPLEMENT_INTERFACE (EXAMPLE_TYPE_EDITABLE,
                                               example_chinese_editable_interface_init))


static void
example_chinese_editable_hello (ExampleChinese *self)
{
    g_print ("你好\n");
}

static void
example_chinese_editable_interface_init (ExampleEditableInterface *iface)
{
    iface->hello = (void *) example_chinese_editable_hello;
}

static void
example_chinese_class_init (ExampleChineseClass *klass)
{
    g_print ("example_chinese_class_init...\n");
}

static void
example_chinese_init (ExampleChinese *self)
{
    g_print ("example_chinese_init...\n");
}

