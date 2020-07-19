//
// Created by Dusterwald, Thomas Karl on 2020-07-19.
//

#ifndef SIMUL_WORLD_NEEDWATER_H
#define SIMUL_WORLD_NEEDWATER_H

#include "Need.h"
#include "../actions/DrinkWater.h"

class NeedWater: public Need {
private:
    double degradeRate;
public:
    NeedWater(std::shared_ptr<World> world, double degradeFactor, double prioritisationFactor);

    void degrade();
};


#endif //SIMUL_WORLD_NEEDWATER_H
