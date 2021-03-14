//
// Created by David van der Zalm on 13-3-2021.
//

#ifndef KMINT_DAVID_JEROEN_UFO_TANKBASESTATE_H
#define KMINT_DAVID_JEROEN_UFO_TANKBASESTATE_H

class tank;

class tankBaseState {
public:
    virtual void tick(tank& tank);
};


#endif //KMINT_DAVID_JEROEN_UFO_TANKBASESTATE_H
