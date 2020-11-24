#pragma once

#include <ostream>
#include "State.hpp"

namespace Action {

enum Type {
    SPEED,
    SLOW,
    JUMP,
    WAIT,
    UP,
    DOWN
};

void speed(State&);
void slow(State&);
void jump(State&);
void wait(State&);
void up(State&);
void down(State&);

inline std::ostream& operator<<(std::ostream& _out, Type action_t)
{
    switch (action_t) {
    case SPEED:
        return _out << "SPEED";
    case SLOW:
        return _out << "SLOW";
    case JUMP:
        return _out << "JUMP";
    case WAIT:
        return _out << "WAIT";
    case UP:
        return _out << "UP";
    case DOWN:
        return _out << "DOWN";
    }
}

}
