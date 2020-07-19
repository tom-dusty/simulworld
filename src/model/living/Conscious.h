//
// Created by Dusterwald, Thomas Karl on 2020-07-17.
//

#ifndef SIMUL_WORLD_CONSCIOUS_H
#define SIMUL_WORLD_CONSCIOUS_H

#include "Living.h"

class Conscious: public Living {
public:
    Conscious(std::shared_ptr<World> world, double movementRate, double sensoryRadius);
};

#endif //SIMUL_WORLD_CONSCIOUS_H
