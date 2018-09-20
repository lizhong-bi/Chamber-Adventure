#ifndef A5_GOBLIN_H
#define A5_GOBLIN_H
#include "playerCharacter.h"

class Goblin : public Player
{
public:
    Goblin(int x, int y);
    virtual ~Goblin() = default;
    void getAttacked(Enemy &e) override;
    void specialAbility() override;
};

#endif
