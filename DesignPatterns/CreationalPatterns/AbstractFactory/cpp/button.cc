#include <iostream>
#include <string>

#include "button.h"

using std::cout;
using std::endl;
using std::string;

Button::Button(const string &text) : text(text) {}

void Button::click() { cout << "Button: " << this->text << endl; }
