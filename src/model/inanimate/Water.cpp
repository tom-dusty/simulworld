//
// Created by Dusterwald, Thomas Karl on 2020-07-18.
//

#include "Water.h"

const std::string Water::name = "water";

Water::Water(std::shared_ptr<World> world):
Entity(world){}

// What the name of this entity is
const std::string &Water::Name() {
    return name;
}

// The character representation of this object
const char Water::Symbol() {
    return symbol;
}

void Water::doStuff() {
    // Water doesn't do anything.. TODO: implement flow
}

void Water::DefaultAction() {
    // Water doesn't do anything.. TODO: implement flow
}

bool Water::BlocksMovement() {
    return true;
}