//
// Created by Dusterwald, Thomas Karl on 2020-07-17.
//

#include "Human.h"
#include "../attributes/Omnivore.h"

Human::Human(std::shared_ptr<World> world_in):
Conscious(std::move(world_in), 1.0, 10.0) {
    std::shared_ptr<Attribute> omnivore = std::make_shared<Omnivore>(world, 80.0);

    v_attributes.push_back(omnivore);
}

const std::string &Human::Name(){
    return name;
}

const char Human::Symbol(){
    if(isAlive)
        return symbol;
    else
        return 'x';
}

void Human::DefaultAction() {
    // By default we wander around
    coord = Coordinate::wander(coord);
}
