//
// Created by David van der Zalm on 13-3-2021.
//

#ifndef KMINT_DAVID_JEROEN_UFO_TANKSTATEFACTORY_H
#define KMINT_DAVID_JEROEN_UFO_TANKSTATEFACTORY_H

#include <iostream>
#include <map>
#include <kmint/ufo/states/tank/tankBaseState.h>

class tankStateFactory {
private:
    std::map<std::string, std::unique_ptr<tankBaseState>> states_ = {};
public:
    void registerState(const std::string& stateId, std::unique_ptr<tankBaseState> state);
    void callTick(const std::string& state, tank& tank);
};


#endif //KMINT_DAVID_JEROEN_UFO_TANKSTATEFACTORY_H
