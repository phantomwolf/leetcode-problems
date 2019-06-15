#ifndef _KDE_H
#define _KDE_H

#include <string>

#include "button.h"

// Role: ConcreteProduct
class KDEButton : public Button {
 public:
  KDEButton(const std::string &text);
  virtual void click();
};

#endif
