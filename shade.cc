#include "shade.h"

Shade::Shade(int x, int y): Player(x, y,125,25,25, ObjectType::Shade) {};

void Shade::getAttacked(Enemy &e) {
    e.attack(*this);
}

void Shade::specialAbility() {
  // does nothing; no special ability
}
