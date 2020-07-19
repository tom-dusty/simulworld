//
// Created by Dusterwald, Thomas Karl on 2020-07-18.
//

#include "Action.h"

Action::Action(std::shared_ptr<World> world_in):
world(std::move(world_in)){}