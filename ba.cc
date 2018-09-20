#include "ba.h"

BA::BA(int x, int y): Potion{x,y,ObjectType::BA,5} {}

int BA::getStat() {
    return 5;
}
