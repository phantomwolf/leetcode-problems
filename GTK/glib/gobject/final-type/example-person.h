#ifndef EXAMPLE_PERSON_H
#define EXAMPLE_PERSON_H

#include <glib-object.h>

// With a C++ compiler, G_BEGIN_DECLS and G_END_DECLS will be expanded to:
//      extern "C" {
//      }
G_BEGIN_DECLS

// Just like G_TYPE_STRING, G_TYPE_FLOAT,
// EXAMPLE_TYPE_PERSON represents the type of our class
#define EXAMPLE_TYPE_PERSON example_person_get_type ()

// A convenience macro for emitting the usual declarations in the header file for a type
// which is not (at the present time) intended to be subclassed.
// This results in the following things happening:
//  - the usual example_person_get_type() function is declared with a return type of GType
//  - the ExamplePerson types is defined as a typedef of struct _ExamplePerson. The struct itself is not defined and should be defined from the .c file before G_DEFINE_TYPE() is used.
//  - the EXAMPLE_PERSON() cast is emitted as static inline function along with the EXAMPLE_IS_PERSON() type checking function
//  - the ExamplePersonClass type is defined as a struct containing GObject. This is done for the convenience of the person defining the type and should not be considered to be part of the ABI. In particular, without a firm declaration of the instance structure, it is not possible to subclass the type and therefore the fact that the size of the class structure is exposed is not a concern and it can be freely changed at any point in the future.
//  - g_autoptr() support being added for your type, based on the type of your parent class
//
// Because the EXAMPLE_TYPE_PERSON is not a callable, you must continue to manually define this as a macro for yourself.
// The declaration of the _get_type() function is the first thing emitted by the macro. This allows this macro to be used in the usual way with export control and API versioning macros.
G_DECLARE_FINAL_TYPE (ExamplePerson, example_person, EXAMPLE, PERSON, GObject)


/* Non-virtual public methods */
ExamplePerson *example_person_new (const GValue *full_name);

gint example_person_get_age (ExamplePerson *self);
void example_person_set_age (ExamplePerson *self,
                             gint           age);
void example_person_show_secret (ExamplePerson *self);

G_END_DECLS

#endif
