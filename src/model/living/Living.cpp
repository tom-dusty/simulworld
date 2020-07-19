//
// Created by Dusterwald, Thomas Karl on 2020-07-17.
//

#include "Living.h"


Living::Living(std::shared_ptr<World> world_in, double movementRate_in, double sensoryRadius_in):
Entity(std::move(world_in)),
movementRate(movementRate_in),
sensoryRadius(sensoryRadius_in),
isAlive(true)
{
    std::shared_ptr<Attribute> waterConsumption = std::make_shared<WaterConsuming>(world, 80.0);
    v_attributes.push_back(waterConsumption);
}

void Living::doStuff() {
    if(!isAlive){
        return;
    }
    std::cout << Name() << " is Alive" << std::endl;
    // Degrade all needs and apply all attribute modifiers
    for(auto && attribute: v_attributes){
        for(auto && need: attribute->v_Needs){
            need->degrade();
            if(need->need_satisfied <= 0){
                // You die :(
                isAlive = false;
                return;
            }
            std::cout << need->need_satisfied << " is this satisfied" << std::endl;
        }
    }

    if(actionInProgress) {
        // complete action
        if (currentAction->doAction(coord, sensoryRadius, currentNeed->need_satisfied)) {
            currentNeed->need_satisfied = 100.0;
            actionInProgress = false;
        }
        return;
    }

    // First priority is needs from attributes.
    double maxNeed = 0.0;
    for(auto && attribute: v_attributes){
        for(auto && need: attribute->v_Needs){
            double needChance = (100.0 - need->need_satisfied) * (need->priority / 100.0) + (rand() % 20 - 20);
            if(needChance > maxNeed){
                maxNeed = needChance;
                currentNeed = need;
            }
        }
    }

    // Calculate a chance of doing a need based on need level and priority.
    if((rand() % 100) < maxNeed){
        std::cout << currentNeed->v_actions.size() << std::endl;
        // Do one of the actions according to priority TODO
        if(currentNeed->v_actions.front()->doAction(coord, sensoryRadius, currentNeed->need_satisfied)){
            std::cout << "Satisfied need" << std::endl;
            currentNeed->need_satisfied = 100.0;
        }
        else {
            currentAction = currentNeed->v_actions.front();
            actionInProgress = true;
        }
    }
    else
        this->DefaultAction();

    // Otherwise do default action.
}