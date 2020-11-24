#include "Actions.hpp"
#include "Agent.hpp"
#include "State.hpp"
#include <iostream>


int main()
{
    State state(std::cin);

    // Debug
    for (int i=0; i<4; ++i) {
        for (int j=0; j<10; ++j) {
            std::cerr << state.bridge.lanes[i][j] << ' ';
        }
        std::cerr << std::endl;
    }
    
    while (1) {
        state.turn_input(std::cin);

        std::cout << Action::SPEED << std::endl;
    }
}
