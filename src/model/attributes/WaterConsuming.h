//
// Created by Dusterwald, Thomas Karl on 2020-07-18.
//

#ifndef SIMUL_WORLD_WATERCONSUMING_H
#define SIMUL_WORLD_WATERCONSUMING_H

#include "Attribute.h"

#include "../needs/NeedWater.h"

class WaterConsuming: public Attribute {
    // TODO: Add Need for water
private:
    std::string name="water consuming";
public:
    WaterConsuming(std::shared_ptr<World> world_in, double priority);

    const std::string &Name() override;
};


#endif //SIMUL_WORLD_WATERCONSUMING_H
