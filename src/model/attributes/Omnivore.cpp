//
// Created by Dusterwald, Thomas Karl on 2020-07-19.
//

#include "Omnivore.h"

#include "../needs/NeedFood.h"


Omnivore::Omnivore(std::shared_ptr<World> world_in, double priority):
        Attribute(std::move(world_in)){
    double degradeRate = 2;
    std::shared_ptr<Need> food = std::make_shared<NeedFood>(world, degradeRate, priority);
    v_Needs.push_back(food);
}

const std::string& Omnivore::Name() {
    return name;
}