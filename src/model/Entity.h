//
// Created by Dusterwald, Thomas Karl on 2020-07-17.
//

#ifndef SIMUL_WORLD_ENTITY_H
#define SIMUL_WORLD_ENTITY_H

#include <vector>

#include "../util/Coordinate.h"
#include "attributes/Attribute.h"

class Attribute;
class World;

class Entity {
private:

protected:
    // The attributes of the entity
    std::vector<std::shared_ptr<Attribute>> v_attributes;
    std::shared_ptr<World> world;

public:
    Entity(std::shared_ptr<World> world_in);
    // Where this entity resides in space
    Coordinate coord;
    // What the name of this entity is
    virtual const std::string &Name() = 0;

    // The character representation of this object
    virtual const char Symbol() = 0;

    virtual bool BlocksMovement() = 0;

    // Do stuff
    virtual void doStuff() = 0;

    // Default action
    virtual void DefaultAction() = 0;

    // Sort by coordinates by default
    bool operator<(const Entity &right);

    std::vector<std::shared_ptr<Attribute>> & getAttributes();
};


#endif //SIMUL_WORLD_ENTITY_H
