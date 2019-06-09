#ifndef _GNOME_H
#define _GNOME_H

#include <string>

#include "button.h"

class GnomeButton : public Button {
public:
    GnomeButton(const std::string &text);
    virtual void click();
};

#endif
