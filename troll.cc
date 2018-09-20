#include "troll.h"
#include "enemy.h"

Troll::Troll(int x, int y): Player(x, y,120,25,15, ObjectType::Troll){};

void Troll::getAttacked(Enemy &e)
{
    e.attack(*this);
}

void Troll::specialAbility() {
  if (this->hp <= 115) {
    this->hp += 5;
  } else {
    this->hp = 120;
  }
}
