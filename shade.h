#ifndef SHADE_H
#define SHADE_H
#include "playerCharacter.h"
#include "enemy.h"

class Shade : public Player{
public:
    Shade(int x, int y);
    virtual ~Shade() = default;
    void getAttacked(Enemy &e) override;
    void specialAbility() override;
};
#endif
