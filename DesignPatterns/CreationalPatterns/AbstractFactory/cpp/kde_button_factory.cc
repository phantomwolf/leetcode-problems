#include <string>

#include "kde_button.h"
#include "kde_button_factory.h"

using std::string;

Button *KDEButtonFactory::createButton(const string &text) {
  return new KDEButton(text);
}
