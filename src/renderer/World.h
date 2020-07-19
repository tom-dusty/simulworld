//
// Created by Dusterwald, Thomas Karl on 2020-07-17.
//

#ifndef SIMUL_WORLD_WORLD_H
#define SIMUL_WORLD_WORLD_H

#include "../model/Entity.h"
#include <vector>
#include <algorithm>

class Action;
class Need;
class Entity;

class World {
private:
    // The vector of all entities
    std::vector<std::shared_ptr<Entity>> v_activeEntities;

    unsigned u_size;
public:
    World(unsigned u_size_in);

    void addEntity(std::shared_ptr<Entity> &entity);

    // Render the world and returns an ascii representation of it
    bool render();

    // Get all the entities to do what they do
    void step();

    std::shared_ptr<Entity> searchForNearestEntityType(const std::string &Name, const Coordinate &coordCentre, double radiusSearch);

    bool isOccupiedBySolid(Coordinate coord);
};


#endif //SIMUL_WORLD_WORLD_H
