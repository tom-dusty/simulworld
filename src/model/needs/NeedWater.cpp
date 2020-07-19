//
// Created by Dusterwald, Thomas Karl on 2020-07-19.
//

#include "NeedWater.h"

NeedWater::NeedWater(std::shared_ptr<World> world_in, double degradeFactor, double prioritisationFactor):
Need(std::move(world_in), prioritisationFactor),
degradeRate(degradeFactor)
{
    std::shared_ptr<Action> drinkWater = std::make_shared<DrinkWater>(world, prioritisationFactor);
    v_actions.push_back(drinkWater);
}

void NeedWater::degrade() {
    // Linear for now.
    need_satisfied -= degradeRate;
}