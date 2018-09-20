#include "wa.h"

WA::WA(int x, int y): Potion{x,y,ObjectType::WA,-5} {}

int WA::getStat() {
    return -5l;
}
