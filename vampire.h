#ifndef A5_VAMPIRE_H
#define A5_VAMPIRE_H
#include "playerCharacter.h"

class Vampire : public Player
{
public:
    Vampire(int x, int y);
    virtual ~Vampire() = default;
    void attack (Enemy &e);
    void attack(Halfling &Halfling) override;
    void attack(Human &Human) override;
    void attack(Dwarf &Dwarf) override;
    void attack(Elf &Elf) override;
    void attack(Orcs &Orcs) override;
    void attack(Merchant &Merchant)override;
    void attack(Dragon &Dragon) override;
    void getAttacked(Enemy &e) override;
    void specialAbility() override;
};
#endif
