#include "vampire.h"
#include "enemy.h"
#include "dragon.h"
#include "dwarf.h"
#include "elf.h"
#include "halfling.h"
#include "human.h"
#include "merchant.h"
#include "orcs.h"
#include <math.h>

Vampire::Vampire(int x, int y): Player(x, y,50,25,25, ObjectType::Vampire){};

void Vampire::specialAbility() {
  // does nothing, no special Ability
}

void Vampire::attack(Enemy &e)
{
    double damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+this->getStats().potionAtk);
    e.takeDamage((int)ceil(damage));
}

void Vampire::attack(Halfling &e)
{
    double damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+this->getStats().potionAtk);
    e.takeDamage((int)ceil(damage));
    this->hp += 5;
}

void Vampire::attack(Human &e)
{
    double damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+this->getStats().potionAtk);
    e.takeDamage((int)ceil(damage));
    this->hp += 5;
}

void Vampire::attack(Dwarf &e)
{
    double damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+this->getStats().potionAtk);
    e.takeDamage((int)ceil(damage));
    if(this->hp <= 5) this->hp = 0;
    else this->hp -= 5;
}

void Vampire::attack(Elf &e)
{
    double damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+this->getStats().potionAtk);
    e.takeDamage((int)ceil(damage));
    this->hp += 5;
}

void Vampire::attack(Orcs &e)
{
    double damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+this->getStats().potionAtk);
    e.takeDamage((int)ceil(damage));
    this->hp += 5;
}

void Vampire::attack(Merchant &e)
{
    double damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+this->getStats().potionAtk);
    e.takeDamage((int)ceil(damage));
    this->hp += 5;
}

void Vampire::attack(Dragon &e)
{
    double damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+this->getStats().potionAtk);
    e.takeDamage((int)ceil(damage));
    this->hp += 5;
}

void Vampire::getAttacked(Enemy &e)
{
    e.attack(*this);
}
