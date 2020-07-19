//
// Created by Dusterwald, Thomas Karl on 2020-07-19.
//

#ifndef SIMUL_WORLD_EATFOOD_H
#define SIMUL_WORLD_EATFOOD_H

#include "Action.h"

class EatFood : public Action {
public:
    EatFood(std::shared_ptr<World> world, double priority = 80.0);

    double doAction(Coordinate &coord, double sensoryRadius, double need);
};


#endif //SIMUL_WORLD_EATFOOD_H
