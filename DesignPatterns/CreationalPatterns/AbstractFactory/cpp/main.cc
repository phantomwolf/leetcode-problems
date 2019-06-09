#include <iostream>
#include <stdexcept>
#include <string>

#include "button_factory.h"
#include "gnome_button_factory.h"
#include "kde_button_factory.h"

using namespace std;

int main(int argc, char *argv[]) {
  string mode("gnome");
  if (argc > 1) {
    mode = argv[1];
  }
  // Button factory
  ButtonFactory *factory;
  if (mode == "gnome") {
    factory = new GnomeButtonFactory();
  } else if (mode == "kde") {
    factory = new KDEButtonFactory();
  } else {
    throw runtime_error("Invalid mode");
  }
  // Create button
  Button *btn = factory->createButton("cancel");
  btn->click();

  return 0;
}
