#ifndef ACTIONLISTENER_HPP_INCLUDED
#define ACTIONLISTENER_HPP_INCLUDED
#include "hero.hpp"

using namespace sf;

class ActionListener
{
private:
    Event event;
    RenderWindow* window;
    Hero* hero;
    Map* map_base;
public:
    ActionListener(RenderWindow*,Hero*,Map*);
    void listen();
};

#endif // ACTIONLISTENER_HPP_INCLUDED
