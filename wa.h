#ifndef A5_WA_H
#define A5_WA_H
#include "potion.h"
class WA: public Potion{
public:
    WA(int x, int y);
    virtual ~WA() = default;
    int getStat();
};
#endif

