//
// Created by Dusterwald, Thomas Karl on 2020-07-18.
//

#ifndef SIMUL_WORLD_NEED_H
#define SIMUL_WORLD_NEED_H

#include "../actions/Action.h"

#include <vector>

class Action;
class World;

class Need {
protected:
    std::shared_ptr<World> world;
public:
    // How much this need will need to be satisfied.
    double need_satisfied;

    double priority;

    // actions that can be performed to satisfy this need - randomize actions priority per individual?
    std::vector<std::shared_ptr<Action>> v_actions;

    Need(std::shared_ptr<World> world_in, double prioritisation_factor, double need = 100.0);

    // Function which degrades the need over one timestep
    virtual void degrade() = 0;
};

#endif //SIMUL_WORLD_NEED_H
