#ifndef A5_BA_H
#define A5_BA_H
#include "potion.h"
class BA: public Potion{
public:
    BA(int x, int y);
    virtual ~BA() = default;
    int getStat();
};
#endif

