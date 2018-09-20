#ifndef ORCS_H
#define ORCS_H
#include "enemy.h"
#include "playerCharacter.h"
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;

class Orcs : public Enemy
{
    public:
        Orcs(int x, int y);
        virtual ~Orcs() = default;
        bool getAttacked(Player &p) override;
        void attack(Player &p) override;
        void attack(Shade &p) override;
        void attack(Drow &p) override;
        void attack(Vampire &p) override;
        void attack(Troll &p) override;
        void attack(Goblin &p) override;
};

#endif // ORCS_H
