//
// Created by Dusterwald, Thomas Karl on 2020-07-19.
//

#ifndef SIMUL_WORLD_FOOD_H
#define SIMUL_WORLD_FOOD_H

#include "../Entity.h"

class Food : public Entity {
private:
    char symbol = 'f';

    char symbolNoNutrition = '~';

protected:
    double nutritionValue; // Value in need satisfaction / nutrition point / kg of animal weight

    double nutritionValueRemaining;

public:
    Food(std::shared_ptr<World> world, double nutritionValue);

    // What the name of this entity is
    const static std::string name;

    const static std::string nameNoNutrition;

    // What the name of this entity is
    const std::string &Name() override;

    // The character representation of this object
    const char Symbol() override;

    void doStuff() override;

    void DefaultAction() override;

    double consumeNutrition(double need);

    bool BlocksMovement() override;

    OutputColour::Colour Colour();
};


#endif //SIMUL_WORLD_FOOD_H
