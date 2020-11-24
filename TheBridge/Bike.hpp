#pragma once

#include <istream>


struct Bike {

    int  x{0};
    int  y{0};
    bool activated{0};

    void update(std::istream& _in);
};


void Bike::update(std::istream& _in)
{
    _in >> x >> y >> activated;
}
