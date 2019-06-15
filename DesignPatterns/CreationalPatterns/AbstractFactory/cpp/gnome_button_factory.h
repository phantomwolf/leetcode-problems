#ifndef _GNOME_BUTTON_FACTORY_H
#define _GNOME_BUTTON_FACTORY_H

#include <string>

#include "button_factory.h"

// Role: ConcreteFactory
class GnomeButtonFactory : public ButtonFactory {
 public:
  virtual Button *createButton(const std::string &text);
};

#endif
