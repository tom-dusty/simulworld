#include <iostream>
#include "src/util/Coordinate.h"
#include "src/model/inanimate/Water.h"
#include "src/model/living/Human.h"
#include "src/model/living/ShortSightedHuman.h"
#include "src/renderer/World.h"
#include "src/model/inanimate/Food.h"
#include "src/model/inanimate/Water.h"

int main() {
    std::shared_ptr<World> world = std::make_shared<World>(20);
    Coordinate coord1 = Coordinate(1, 3);
    Coordinate coord2 = Coordinate(1, 2);
    Coordinate coord3 = Coordinate(2, 3);
    Coordinate coord4 = Coordinate(4, 2);
    Coordinate coord5 = Coordinate(5, 5);
    Coordinate coord6 = Coordinate(6, 6);

    std::cout << coord1 - coord2 << std::endl;
    std::cout << coord1 + coord2 << std::endl;
    std::cout << coord1.distanceFrom(coord2) << std::endl;

    std::shared_ptr<Entity> john = std::make_shared<Human>(world);
    john->coord = coord1;
    std::shared_ptr<Entity> sam = std::make_shared<ShortSightedHuman>(world);
    sam->coord = coord2;
    std::shared_ptr<Entity> john1 = std::make_shared<Human>(world);
    john1->coord = coord3;
    std::shared_ptr<Entity> sam1 = std::make_shared<Human>(world);
    sam1->coord = coord4;
    std::shared_ptr<Entity> john2 = std::make_shared<ShortSightedHuman>(world);
    john2->coord = coord5;
    std::shared_ptr<Entity> sam2 = std::make_shared<ShortSightedHuman>(world);
    sam2->coord = coord6;
    std::cout << john->Name() << std::endl;
    std::cout << john->Symbol() << std::endl;

    for(int i = 4; i < 7; i++){
        std::shared_ptr<Entity> water = std::make_shared<Water>(world);
        water->coord = Coordinate(10, i);
        world->addEntity(water);
    }

    // add some food
    for(int i = 4; i < 7; i++){
        std::shared_ptr<Entity> food = std::make_shared<Food>(world, 200);
        food->coord = Coordinate(14, i);
        world->addEntity(food);
    }

    world->addEntity(sam);

    world->addEntity(john);
    world->addEntity(sam1);
    world->addEntity(john1);
    world->addEntity(sam2);
    world->addEntity(john2);
    world->render();
    int input = 1;
    while(input != 0){
        for(int i = 0; i < input; i++)
            world->step();
        world->render();
        std::cin >> input;
    }
    return 0;
}