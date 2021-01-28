#include "StateChain.h"

StateChain::StateChain() : event(NULL), next(NULL)
{
}

StateChain::StateChain(Event<void(StateChain::States state)> *event) : event(event), next(NULL)
{
}

void StateChain::add(Event<void(StateChain::States state)> *event)
{
    if (this->event == NULL)
    {
        this->event = event;
    }
    else if (this->next == NULL)
    {
        this->next = new StateChain(event);
    }
    else
    {
        this->next->add(event);
    }
}

void StateChain::call(StateChain::States state)
{
    this->event->post(state);
    if (this->next != NULL)
    {
        this->next->call(state);
    }
}