//
// Created by Dusterwald, Thomas Karl on 2020-07-17.
//

#ifndef SIMUL_WORLD_LIVING_H
#define SIMUL_WORLD_LIVING_H

#include "../Entity.h"
#include "../attributes/WaterConsuming.h"

class Living: public Entity{
protected:
    // TODO: Make actual dates
    double birthDate;
    double deathDate;
    bool isAlive;

    double movementRate; // Rate (in cells/iteration) that an living organism can move. Non-living organisms can't move.
    double sensoryRadius; // Radius in which this entity can sense other organisms

    bool actionInProgress = false;

    std::shared_ptr<Action> currentAction;
    std::shared_ptr<Need> currentNeed;
public:
    Living(std::shared_ptr<World> world_in, double movementRate_in, double sensoryRadius_in);

    void doStuff();

    bool BlocksMovement() override;
};


#endif //SIMUL_WORLD_LIVING_H
