#ifndef __EXAMPLE_CHINESE_H__
#define __EXAMPLE_CHINESE_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define EXAMPLE_TYPE_CHINESE example_chinese_get_type ()
G_DECLARE_FINAL_TYPE (ExampleChinese, example_chinese, EXAMPLE, CHINESE, GObject)

G_END_DECLS

#endif
