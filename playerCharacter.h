#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#include "character.h"
#include "enemy.h"
enum class ObjectType;
class Dragon;
class Halfling;
class Human;
class Orcs;
class Dwarf;
class Elf;
class Merchant;

class Player : public Character{
    //int potionAtk = 0;
    //int potionDef = 0;
protected:
    Player(int x, int y, int hp, int atk, int def, ObjectType t);
public:
    virtual ~Player() = default;
    void movePlayer(int newRow, int newCol);
    virtual void notifyObservers() override;
    virtual void attack(Enemy &e);
    virtual void attack(Halfling &Halfling);
    virtual void attack(Human &Human);
    virtual void attack(Dwarf &Dwarf);
    virtual void attack(Elf &Elf);
    virtual void attack(Orcs &Orcs);
    virtual void attack(Merchant &Merchant);
    virtual void attack(Dragon &Dragon);
    virtual void getAttacked(Enemy &e) = 0;
    virtual void specialAbility() = 0;
    //void setPotionAtk (int val);
    //void setPotionDef (int val);
};

#endif
