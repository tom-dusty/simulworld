//
// Created by Dusterwald, Thomas Karl on 2020-07-18.
//

#ifndef SIMUL_WORLD_ATTRIBUTE_H
#define SIMUL_WORLD_ATTRIBUTE_H

#include <string>
#include <vector>

#include "../needs/Need.h"

class Need;
class World;

class Attribute {
protected:
    std::shared_ptr<World> world;
public:
    Attribute(std::shared_ptr<World> world_in);

    // Attributes provide needs
    std::vector<std::shared_ptr<Need>> v_Needs;
    virtual const std::string &Name() = 0;
};


#endif //SIMUL_WORLD_ATTRIBUTE_H
