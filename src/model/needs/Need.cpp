#include <utility>

//
// Created by Dusterwald, Thomas Karl on 2020-07-18.
//

#include "Need.h"

Need::Need(std::shared_ptr<World> world_in, double prioritisation_factor, double need):
priority(prioritisation_factor),
world(std::move(world_in)),
need_satisfied(need) {}