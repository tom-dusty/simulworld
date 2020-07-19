//
// Created by Dusterwald, Thomas Karl on 2020-07-19.
//

#include "ShortSightedHuman.h"

ShortSightedHuman::ShortSightedHuman(std::shared_ptr<World> world):
        Conscious(std::move(world), 1.0, 5.0){}

const std::string &ShortSightedHuman::Name(){
    return name;
}

const char ShortSightedHuman::Symbol(){
    if(isAlive)
        return symbol;
    else
        return 'x';
}

void ShortSightedHuman::DefaultAction() {
    // By default we wander around
    coord = Coordinate::wander(coord);
}
