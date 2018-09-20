#include "drow.h"
#include "enemy.h"

Drow::Drow(int x, int y): Player(x, y,150,25,15, ObjectType::Drow){};

void Drow::getAttacked(Enemy &e)
{
    e.attack(*this);
}

void Drow::specialAbility() {
  // does nothing;
}
