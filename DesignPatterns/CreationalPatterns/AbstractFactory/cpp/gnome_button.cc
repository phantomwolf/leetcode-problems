#include <iostream>
#include <string>

#include "gnome_button.h"

using std::cout;
using std::endl;
using std::string;

GnomeButton::GnomeButton(const std::string &text) : Button(text) {}

void GnomeButton::click() {
    cout << "GnomeButton: " << this->text << endl;
}
