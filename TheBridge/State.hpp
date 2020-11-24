#pragma once

#include "Bridge.hpp"
#include "Bike.hpp"
#include <array>
#include <istream>


struct State {

    const int MAX_TIME = 150;   // 150ms per turn is allowed.
    
    /** The road ahead */
    Bridge bridge;
    /** The amount of bikes we control */
    int    n_bikes;
    /** The amount of bikes that must survive */
    int    n_bikes_goal;
    /** The speed of the bikes */
    int    speed;
    /** The bikes. Initialized with `activated=0` if not present. */
    std::array<Bike, 4> bikes;

    /** Input from online referee */
    State(std::istream& _in);
    void turn_input(std::istream& _in);
    
    /** Access the bridge's lanes */
    bool operator()(int x, int y) const;
};

State::State(std::istream& _in)
    : n_bikes(0)
    , n_bikes_goal(0)
    , speed(0)
{
    _in >> n_bikes;
    _in >> n_bikes_goal;
    bridge = Bridge(_in);
}

void State::turn_input(std::istream& _in)
{
    _in >> speed;
    for (int i=0; i<n_bikes; ++i) {
        bikes[i].update(_in);
    }
}

inline bool State::operator()(int x, int y) const
{
    return bridge.lanes[y][x];
}
