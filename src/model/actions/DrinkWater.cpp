//
// Created by Dusterwald, Thomas Karl on 2020-07-18.
//

#include "DrinkWater.h"
#include "../../util/Coordinate.h"
#include "../inanimate/Water.h"

DrinkWater::DrinkWater(std::shared_ptr<World> world, double priority_in):
        Action(std::move(world)) {
    priority = priority_in;
}

double DrinkWater::doAction(Coordinate &coord, double sensoryRadius, double need) {
    // Search for nearest water
    std::shared_ptr<Entity> water = world->searchForNearestEntityType(Water::name, coord, sensoryRadius);


    if (water == nullptr) {
        std::cout << "No water found" << std::endl;
        // None found - wander randomly
        Coordinate toMoveTo = Coordinate::wander(coord);
        if(!world->isOccupiedBySolid(toMoveTo))
            coord = toMoveTo;
        return 0;
    }
    std::cout << "FOUND WATER" << std::endl;

    if(coord.distanceFrom(water->coord) < 1.5) {
        // We made it to the water and drunk we are completely satisfied
        return 100.0 - need;
    }

    // Move towards water
    Coordinate toMoveTo = coord.moveTowardsCoordinate(water->coord);
    if(!world->isOccupiedBySolid(toMoveTo))
        coord = toMoveTo;
    else {
        Coordinate toMoveTo = Coordinate::wander(coord);
        if(!world->isOccupiedBySolid(toMoveTo))
            coord = toMoveTo;
    }
    return 0;
}