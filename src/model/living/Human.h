//
// Created by Dusterwald, Thomas Karl on 2020-07-17.
//

#ifndef SIMUL_WORLD_HUMAN_H
#define SIMUL_WORLD_HUMAN_H

#include "Conscious.h"

class Human: public Conscious {
private:
    std::string name = "human";
    static const char symbol = '*';
public:
    Human(std::shared_ptr<World> world);
    const std::string &Name() override;
    const char Symbol() override;
    void DefaultAction() override ;
};


#endif //SIMUL_WORLD_HUMAN_H
