#ifndef _HOUSE_H
#define _HOUSE_H

#include <string>

class House
{
public:
    virtual ~House();

    virtual void setBasement(std::string basement) = 0;
    virtual void setStructure(std::string structure) = 0;
    virtual void setRoof(std::string roof) = 0;
    virtual void setInterior(std::string interior) = 0;
};

#endif
