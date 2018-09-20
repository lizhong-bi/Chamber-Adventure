#ifndef A5_BD_H
#define A5_BD_H
#include "potion.h"
class BD : public Potion{
public:
    BD(int x, int y);
    virtual ~BD() = default;
    int getStat();
};
#endif

