#ifndef OBSERVER_H
#define OBSERVER_H
class Player;

class Observer
{
public:
    virtual void notify(Player *who) = 0;
    virtual void notify(Subject *who){}
    virtual ~Observer() = default;
};

#endif
