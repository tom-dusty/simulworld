//
// Created by Dusterwald, Thomas Karl on 2020-07-19.
//

#include "EatFood.h"

#include "../inanimate/Food.h"

EatFood::EatFood(std::shared_ptr<World> world, double priority_in):
    Action(std::move(world)) {
    priority = priority_in;
}

double EatFood::doAction(Coordinate &coord, double sensoryRadius, double need) {
    std::cout << "Eating food" << std::endl;
    // Search for nearest food
    std::shared_ptr<Entity> food = world->searchForNearestEntityType(Food::name, coord, sensoryRadius);
    std::cout << "Looking for food" << std::endl;

    if (food == nullptr) {
        std::cout << "No food found before cast" << std::endl;
        // None found - wander randomly
        Coordinate toMoveTo = Coordinate::wander(coord);
        if(!world->isOccupiedBySolid(toMoveTo))
            coord = toMoveTo;
        return false;
    }

    std::shared_ptr<Food> foodPtr = std::dynamic_pointer_cast<Food>(food);

    if(foodPtr == nullptr) {
        std::cout << "No food found after cast" << std::endl;
        // None found - wander randomly
        Coordinate toMoveTo = Coordinate::wander(coord);
        if(!world->isOccupiedBySolid(toMoveTo))
            coord = toMoveTo;
        return 0.0;
    }

    std::cout << "FOUND FOOD" << std::endl;

    if(coord.distanceFrom(food->coord) < 1.5) {
        // We made it to the water and drunk
        return foodPtr->consumeNutrition(need);
    }

    // Move towards water
    Coordinate toMoveTo = coord.moveTowardsCoordinate(foodPtr->coord);
    if(!world->isOccupiedBySolid(toMoveTo))
        coord = toMoveTo;
    else {
        toMoveTo = Coordinate::wander(coord);
        if(!world->isOccupiedBySolid(toMoveTo))
            coord = toMoveTo;
    }
    return 0.0;
}