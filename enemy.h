#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"
#include "observer.h"
class Player;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
enum class ObjectType;

class Enemy : public Character, public Observer {
    protected:
        Enemy(int x, int y, int hp, int atk, int def, ObjectType t);
        bool aggro;
        //void attackGeneric(Player &p);
    public:
        virtual ~Enemy() = default;
        void moveEnemy(int newRow, int newCol);
        bool isAggroed();
        virtual void notify(Player *who);
        //void notify(Subject *who) override;
        virtual void attack(Player &p);
        virtual void attack(Shade &p);
        virtual void attack(Drow &p);
        virtual void attack(Vampire &p);
        virtual void attack(Troll &p);
        virtual void attack(Goblin &p);
        virtual bool getAttacked(Player &p) = 0;
};

#endif // ENEMY_H
