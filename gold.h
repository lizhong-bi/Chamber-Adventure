#ifndef A5_GOLD_H
#define A5_GOLD_H
#include "item.h"

class Gold: public Item{
    bool isGuarded = false;
public:
    Gold(int x,int y,ObjectType t,int val);
    virtual ~Gold() = default;
    bool canPick();
    int getVal();
    void isHoard (bool b);

};
#endif
