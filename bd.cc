#include "bd.h"

BD::BD(int x, int y): Potion{x,y,ObjectType::BD,5} {}

int BD::getStat() {
    return this->val;
}
