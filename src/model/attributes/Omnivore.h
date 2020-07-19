//
// Created by Dusterwald, Thomas Karl on 2020-07-19.
//

#ifndef SIMUL_WORLD_OMNIVORE_H
#define SIMUL_WORLD_OMNIVORE_H

#include "Attribute.h"

/**
 * An omnivore consumes anything in the "Food" class
 */

class Omnivore : public Attribute {
    // TODO: Add Need for water
private:
    std::string name="omnivore";
public:
    Omnivore(std::shared_ptr<World> world_in, double priority);

    const std::string &Name() override;
};


#endif //SIMUL_WORLD_OMNIVORE_H
