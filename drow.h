#ifndef A5_DROW_H
#define A5_DROW_H
#include "playerCharacter.h"

class Drow : public Player
{
public:
    Drow(int x, int y);
    virtual ~Drow() = default;
    void getAttacked(Enemy &e) override;
    void specialAbility() override;
};

#endif
