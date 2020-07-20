//
// Created by Dusterwald, Thomas Karl on 2020-07-20.
//

#ifndef SIMUL_WORLD_OUTPUTCOLOUR_H
#define SIMUL_WORLD_OUTPUTCOLOUR_H

#include <string>

namespace OutputColour {
    enum Colour {
        BLACK = 30,
        RED = 31,
        GREEN = 32,
        YELLOW = 33,
        BLUE = 34,
        MAGENTA = 35,
        CYAN = 36,
        WHITE = 37,

        BRIGHT_BLACK = 90,
        BRIGHT_RED = 91,
        BRIGHT_GREEN = 92,
        BRIGHT_YELLOW = 93,
        BRIGHT_BLUE = 94,
        BRIGHT_MAGENTA = 95,
        BRIGHT_CYAN = 96,
        BRIGHT_WHITE = 97,
    };

    std::string ColourChar(const Colour &colour, char character);
};


#endif //SIMUL_WORLD_OUTPUTCOLOUR_H
