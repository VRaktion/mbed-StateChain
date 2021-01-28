#ifndef STATE_CHAIN_H
#define STATE_CHAIN_H

#include "mbed.h"

class StateChain
{
public:
    enum class States
    {
        Off = 0,
        Standby = 1,
        On = 2,
        Undefined = 99
    };

    StateChain();
    StateChain(Event<void(States state)> *event);
    void add(Event<void(States state)> *event);
    void call(States state);

private:
    Event<void(States state)> *event;
    StateChain *next;
};

#endif //STATE_CHAIN_H