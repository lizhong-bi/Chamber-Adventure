#ifndef A5_PH_H
#define A5_PH_H
#include "potion.h"

class PH:public Potion{
public:
    PH(int x, int y);
    virtual ~PH() = default;
};
#endif

