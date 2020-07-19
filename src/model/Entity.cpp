//
// Created by Dusterwald, Thomas Karl on 2020-07-17.
//

#include "Entity.h"

Entity::Entity(std::shared_ptr<World> world_in):
world(std::move(world_in)){}

bool Entity::operator<(const Entity &right) {
    return coord < right.coord;
}


std::vector<std::shared_ptr<Attribute>> & Entity::getAttributes(){
    return v_attributes;
}
