//
// Created by Dusterwald, Thomas Karl on 2020-07-19.
//

#include "Food.h"

const std::string Food::name = "food";
const std::string Food::nameNoNutrition = "no food";

Food::Food(std::shared_ptr<World> world, double nutritionValue_in):
        nutritionValue(nutritionValue_in),
        nutritionValueRemaining(nutritionValue_in),
        Entity(std::move(world)){}

// What the name of this entity is
const std::string &Food::Name() {
    if(nutritionValueRemaining > 0)
        return name;
    else
        return nameNoNutrition;
}

// The character representation of this object
const char Food::Symbol() {
    if(nutritionValueRemaining > 0)
        return symbol;
    else
        return symbolNoNutrition;
}

void Food::doStuff() {
    // Food loses nutrition over time
    DefaultAction();
}

double Food::consumeNutrition(double need){
    if(need > nutritionValueRemaining){
        nutritionValueRemaining = 0;
        return nutritionValueRemaining;
    }
    double nutritionRequired = 100.0 - need;

    nutritionValueRemaining -= nutritionRequired;
    return nutritionRequired;
}

void Food::DefaultAction() {
    // Food loses nutrition over time TODO: later - for now nutrition lasts forever
}