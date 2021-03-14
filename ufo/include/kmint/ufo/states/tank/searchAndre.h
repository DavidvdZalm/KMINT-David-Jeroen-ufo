//
// Created by David van der Zalm on 13-3-2021.
//

#ifndef KMINT_DAVID_JEROEN_UFO_SEARCHANDRE_H
#define KMINT_DAVID_JEROEN_UFO_SEARCHANDRE_H

#include <kmint/ufo/states/tank/tankBaseState.h>

class searchAndre : public tankBaseState {
public:
    void tick(tank& tank) override;
};


#endif //KMINT_DAVID_JEROEN_UFO_SEARCHANDRE_H
