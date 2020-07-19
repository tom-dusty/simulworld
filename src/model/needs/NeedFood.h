//
// Created by Dusterwald, Thomas Karl on 2020-07-19.
//

#ifndef SIMUL_WORLD_NEEDFOOD_H
#define SIMUL_WORLD_NEEDFOOD_H

#include "Need.h"

class NeedFood : public Need {
private:
    double degradeRate;
public:
    NeedFood(std::shared_ptr<World> world, double degradeFactor, double prioritisationFactor);

    void degrade();
};


#endif //SIMUL_WORLD_NEEDFOOD_H