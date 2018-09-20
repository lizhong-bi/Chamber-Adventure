#ifndef ELF_H
#define ELF_H
#include "enemy.h"
#include "playerCharacter.h"
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;

class Elf : public Enemy
{
    public:
        Elf(int x, int y);
        virtual ~Elf() = default;
        bool getAttacked(Player &p) override;
        void attack(Player &p) override;
        void attack(Shade &p) override;
        void attack(Drow &p) override;
        void attack(Vampire &p) override;
        void attack(Troll &p) override;
        void attack(Goblin &p) override;
};

#endif // ELF_H
