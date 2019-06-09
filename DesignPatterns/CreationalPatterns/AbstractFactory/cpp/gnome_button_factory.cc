#include <string>

#include "gnome_button.h"
#include "gnome_button_factory.h"

using std::string;

Button *GnomeButtonFactory::createButton(const string &text) {
  return new GnomeButton(text);
}
