#include "Actions.hpp"
#include <algorithm>

enum Jump_State { JUMPING,
    NOT_JUMPING };

void fall_hole_ahead(const State& state, Bike& bike, int dist)
{
    for (Bike bike : state.bikes) {
        for (int i=0; i<dist; ++i) {
            if (state(bike.x+i, bike.y) == 1) {
                bike.activated = 0;
            }
        }
    }
}

void advance_bikes(State& state, Jump_State j_state = NOT_JUMPING)
{
    std::for_each(state.bikes.begin(), state.bikes.end(),
                  [&state](Bike& bike) {
                      if (bike.activated) {
                          bike.x += state.speed;
                      }
                  });
}

namespace Action {

void speed(State& state)
{
    ++state.speed;
    advance_bikes(state);
}

void slow(State& state)
{
    --state.speed;
    advance_bikes(state);
}

void jump(State& state)
{
    advance_bikes(state, JUMPING);
}

void wait(State& state)
{
    advance_bikes(state);
}

void up(State& state)
{
    bool up_valid = std::none_of(state.bikes.begin(),
        state.bikes.end(),
        [](const Bike& bike) {
            return bike.activated && bike.y == 0;
        });
    if (up_valid) {
        
        std::for_each(state.bikes.begin(), state.bikes.end(),
            [](Bike& bike) {
                --bike.y;
            });
    }
    advance_bikes(state);
}

void down(State& state)
{
    bool down_valid = std::none_of(state.bikes.begin(),
        state.bikes.end(),
        [](const Bike& bike) {
            return bike.activated && bike.y == 4;
        });
    if (down_valid) {
        std::for_each(state.bikes.begin(), state.bikes.end(),
            [](Bike& bike) {
                ++bike.y;
            });
    }
    advance_bikes(state);
}
}
