//
// Created by David van der Zalm on 13-3-2021.
//

#ifndef KMINT_DAVID_JEROEN_UFO_SEARCHGRENADE_H
#define KMINT_DAVID_JEROEN_UFO_SEARCHGRENADE_H


#include "tankBaseState.h"

class searchGrenade : public tankBaseState {
public:
    void tick(tank& tank) override;
};


#endif //KMINT_DAVID_JEROEN_UFO_SEARCHGRENADE_H
