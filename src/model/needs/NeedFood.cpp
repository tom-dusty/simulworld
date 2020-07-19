//
// Created by Dusterwald, Thomas Karl on 2020-07-19.
//

#include "NeedFood.h"
#include "../actions/EatFood.h"

NeedFood::NeedFood(std::shared_ptr<World> world_in, double degradeFactor, double prioritisationFactor):
        Need(std::move(world_in), prioritisationFactor),
        degradeRate(degradeFactor)
{
    std::shared_ptr<Action> eatFood = std::make_shared<EatFood>(world, prioritisationFactor);
    v_actions.push_back(eatFood);
}

void NeedFood::degrade() {
    // Linear for now.
    need_satisfied -= degradeRate;
}