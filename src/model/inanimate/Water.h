//
// Created by Dusterwald, Thomas Karl on 2020-07-18.
//

#ifndef SIMUL_WORLD_WATER_H
#define SIMUL_WORLD_WATER_H

#include "../Entity.h"

class Water: public Entity {
private:
    char symbol = '#';

public:
    Water(std::shared_ptr<World> world);

    const static std::string name;
    // What the name of this entity is
    const std::string &Name() override;

    // The character representation of this object
    const char Symbol() override;

    void doStuff() override;

    void DefaultAction() override ;
};


#endif //SIMUL_WORLD_WATER_H
