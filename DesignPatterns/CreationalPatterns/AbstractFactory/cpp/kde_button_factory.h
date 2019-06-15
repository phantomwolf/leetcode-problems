#ifndef _KDE_BUTTON_FACTORY_H
#define _KDE_BUTTON_FACTORY_H

#include <string>

#include "button_factory.h"

// Role: ConcreteFactory
class KDEButtonFactory : public ButtonFactory {
 public:
  virtual Button *createButton(const std::string &text);
};

#endif
