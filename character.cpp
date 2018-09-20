#include "character.h"

Character::Character(int x, int y, int hp, int atk, int def, ObjectType t) : Object(x, y, t), hp{hp}, atk{atk}, def{def}{ hpMax = hp;}

bool Character::takeDamage(int damage){
    if(hp-damage<0){
        hp=0;
        return true;
    }
    hp-=damage;
    return false;
}

Character::~Character()
{
    //dtor
}
void Character::setHP(int val){
    ObjectType type = this->getType();
    if(type == ObjectType::Drow)
    {
       this->hp += (1.5 * val);
       if(this->hp > this->hpMax) this->hp = hpMax;
    }
    else if(type == ObjectType::Vampire)
    {
        this->hp += val;
    }
    else
      {
       this->hp += val;
       if(this->hp > this->hpMax) this->hp = hpMax;
      }
}

void Character::newHP(int val)
{
    this->hp = val;
}

Stats Character::getStats(){
    Stats s{this->hp, this->atk, this->def,this->potionAtk,this->potionDef};
    return s;
}
