#ifndef A5_RH_H
#define A5_RH_H
#include "potion.h"

class RH:public Potion{
public:
    RH(int x, int y);
    virtual ~RH() = default;
};
#endif

