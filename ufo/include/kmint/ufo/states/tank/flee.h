//
// Created by David van der Zalm on 13-3-2021.
//

#ifndef KMINT_DAVID_JEROEN_UFO_FLEE_H
#define KMINT_DAVID_JEROEN_UFO_FLEE_H

#include "tankBaseState.h"

class flee : public tankBaseState {
public:
    void tick(tank& tank) override;
};



#endif //KMINT_DAVID_JEROEN_UFO_FLEE_H
