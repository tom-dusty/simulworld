//
// Created by Dusterwald, Thomas Karl on 2020-07-18.
//

#include "WaterConsuming.h"


WaterConsuming::WaterConsuming(std::shared_ptr<World> world_in, double priority):
Attribute(std::move(world_in)){
    double degradeRate = 5;
    std::shared_ptr<Need> water = std::make_shared<NeedWater>(world, degradeRate, priority);
    v_Needs.push_back(water);
}

const std::string& WaterConsuming::Name() {
    return name;
}