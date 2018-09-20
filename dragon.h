#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"
#include "playerCharacter.h"
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;

class Dragon : public Enemy
{
        int rowHoard=0;
        int colHoard=0;
    public:
        Dragon(int x, int y);
        virtual ~Dragon() = default;
        void notify(Player *who) override;
        bool getAttacked(Player &p) override;
        void attack(Player &p) override;
        void attack(Shade &p) override;
        void attack(Drow &p) override;
        void attack(Vampire &p) override;
        void attack(Troll &p) override;
        void attack(Goblin &p) override;
        void setHoard(int x, int y);
        int getHoard_x();
        int getHoard_y();
};

#endif
