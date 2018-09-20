#ifndef A5_POTION_H
#define A5_POTION_H
#include "item.h"

class Potion: public Item{
public:
    Potion(int x, int y, ObjectType t, int val);
    virtual ~Potion() = 0;

};
#endif
