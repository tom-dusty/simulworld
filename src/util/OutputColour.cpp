//
// Created by Dusterwald, Thomas Karl on 2020-07-20.
//

#include "OutputColour.h"

#include <iostream>
#include <sstream>

std::string OutputColour::ColourChar(const OutputColour::Colour &colour, char character) {
    std::string out;

    std::stringstream str;

    str << "\033[" << colour << ";m" << character << "\033[0m";

    return str.str();
}