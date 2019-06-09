#ifndef _BUTTON_H
#define _BUTTON_H

#include <string>

// Abstract base class
class Button {
public:
    Button(const std::string &text);
    virtual void click();

protected:
    std::string text;
};

#endif
