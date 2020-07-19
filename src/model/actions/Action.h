//
// Created by Dusterwald, Thomas Karl on 2020-07-18.
//

#ifndef SIMUL_WORLD_ACTION_H
#define SIMUL_WORLD_ACTION_H

#include "../../util/Coordinate.h"

#include "../../renderer/World.h"

class World;

class Action {
protected:
    std::shared_ptr<World> world;
public:
    Action(std::shared_ptr<World> world_in);

    // Priority of action from 0 to 100
    double priority;

    // Return a positive number if action is complete and 0 otherwise
    virtual double doAction(Coordinate &coord, double sensoryRadius, double need) = 0;
};

#endif //SIMUL_WORLD_ACTION_H
