#ifndef A5_WD_H
#define A5_WD_H
#include "potion.h"
class WD : public Potion{
public:
    WD(int x, int y);
    virtual ~WD() = default;
    int getStat();
};
#endif

