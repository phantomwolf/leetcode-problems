#include <iostream>
#include <string>

#include "button.h"

using std::string;
using std::cout;
using std::endl;

// Button
Button::Button(const string &text): text(text) {}

void Button::click() {
    cout << "Button: " << this->text << endl;
}
