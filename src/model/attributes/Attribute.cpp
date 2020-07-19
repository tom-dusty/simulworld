//
// Created by Dusterwald, Thomas Karl on 2020-07-18.
//

#include "Attribute.h"

Attribute::Attribute(std::shared_ptr<World> world_in):
world(std::move(world_in)){}