//
// Created by Dusterwald, Thomas Karl on 2020-07-19.
//

#ifndef SIMUL_WORLD_SHORTSIGHTEDHUMAN_H
#define SIMUL_WORLD_SHORTSIGHTEDHUMAN_H

#include "Conscious.h"

class ShortSightedHuman: public Conscious {
private:
    std::string name = "Short Sighted Human";
    static const char symbol = '&';
public:
    ShortSightedHuman(std::shared_ptr<World> world);
    const std::string &Name() override;
    const char Symbol() override;
    void DefaultAction() override ;
};


#endif //SIMUL_WORLD_SHORTSIGHTEDHUMAN_H
