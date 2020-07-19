//
// Created by Dusterwald, Thomas Karl on 2020-07-19.
//

#include "Conscious.h"


Conscious::Conscious(std::shared_ptr<World> world, double movementRate, double sensoryRadius):
Living(std::move(world), movementRate, sensoryRadius){}