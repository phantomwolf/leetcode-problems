#include <iostream>
#include <string>

#include "kde_button.h"

using std::cout;
using std::endl;
using std::string;

KDEButton::KDEButton(const std::string &text) : Button(text) {}

void KDEButton::click() {
    cout << "KDEButton: " << this->text << endl;
}
