//
// Created by Dusterwald, Thomas Karl on 2020-07-18.
//

#ifndef SIMUL_WORLD_DRINKWATER_H
#define SIMUL_WORLD_DRINKWATER_H

#include "Action.h"
#include "Move.h"


class DrinkWater: public Action {
public:
    DrinkWater(std::shared_ptr<World> world, double priority = 80.0);

    double doAction(Coordinate &coord, double sensoryRadius, double need);
};


#endif //SIMUL_WORLD_DRINKWATER_H
