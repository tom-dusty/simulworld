//
// Created by Dusterwald, Thomas Karl on 2020-07-17.
//

#include "World.h"

World::World(unsigned u_size_in) {
    u_size = u_size_in;
}

bool World::render() {
    // sort using a custom function object
    struct {
        bool operator()(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b) const
        {
            return *a < *b;
        }
    } customLess;
    // sort entities into ascending order
    std::sort(v_activeEntities.begin(), v_activeEntities.end(), customLess);

    auto itr = v_activeEntities.begin();
    std::cout << itr->get()->coord << std::endl;
    for(unsigned y = 0; y < u_size; y++) {
        for(unsigned x = 0; x < u_size; x++) {
            if(itr == v_activeEntities.end())
                break;
            if(itr->get()->coord < Coordinate(x, y)){
                itr++;
                x--;
                continue;
            }
            if(itr->get()->coord == Coordinate(x, y)){
                std::cout << itr->get()->Symbol();
                itr++;
                if(itr != v_activeEntities.end() && itr->get()->coord == Coordinate(x, y)){
                    x--;
                    std::cout << "Found duplicate " << itr->get()->coord;
                }
            }
            else
                std::cout << ' ';
        }
        std::cout << std::endl;
    }
    return true;
}

void World::step() {
    for(auto && entity: v_activeEntities){
        entity->doStuff();
    }
}

void World::addEntity(std::shared_ptr<Entity> &entity) {
    v_activeEntities.push_back(entity);
}

std::shared_ptr<Entity> World::searchForNearestEntityType(const std::string &Name, const Coordinate &coordCentre, double radiusSearch) {
    // Optimise later
    std::shared_ptr<Entity> nearest = nullptr;
    for (auto && entity: v_activeEntities) {
        if(entity->Name() != Name)
            continue;
        if(entity->coord.distanceFrom(coordCentre) > radiusSearch)
            continue;
        if(nearest == nullptr || nearest->coord.distanceFrom(coordCentre) > entity->coord.distanceFrom(coordCentre))
            nearest = entity;
    }
    return nearest;
}

bool World::isOccupiedBySolid(Coordinate coord)
{
    for(auto && entity: v_activeEntities) {
        if(entity->coord == coord && entity->BlocksMovement())
            return true;
    }
    return false;
}