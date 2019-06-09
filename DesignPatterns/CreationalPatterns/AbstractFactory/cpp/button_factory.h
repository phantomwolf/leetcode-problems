#ifndef _BUTTON_FACTORY_H
#define _BUTTON_FACTORY_H

#include <string>

#include "button.h"

// Abstract factory
class ButtonFactory {
 public:
  virtual Button *createButton(const std::string &text) = 0;
};

#endif