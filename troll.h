#ifndef A5_TROLL_H
#define A5_TROLL_H
#include "playerCharacter.h"

class Troll : public Player
{
public:
    Troll(int x, int y);
    virtual ~Troll() = default;
    void getAttacked(Enemy &e) override;
    void specialAbility() override; 
};
#endif
