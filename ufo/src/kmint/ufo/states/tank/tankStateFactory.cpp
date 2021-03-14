//
// Created by David van der Zalm on 13-3-2021.
//

#include "kmint/ufo/states/tank/tankStateFactory.h"

void tankStateFactory::registerState(const std::string& stateId, std::unique_ptr<tankBaseState> state)
{
    this->states_.insert_or_assign(stateId, std::move(state));
}

void tankStateFactory::callTick(const std::string& state, tank& tank)
{
    if (this->states_.count(state) != 0)
    {
        this->states_[state]->tick(tank);
    }
}