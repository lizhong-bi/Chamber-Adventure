#include "goblin.h"
#include "enemy.h"

Goblin::Goblin(int x, int y): Player(x, y,110,15,20, ObjectType::Goblin){};

void Goblin::getAttacked(Enemy &e)
{
    e.attack(*this);
}

void Goblin::specialAbility() {
// does nothing
return;
}
