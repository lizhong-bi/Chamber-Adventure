#include "wd.h"

WD::WD(int x, int y): Potion(x,y,ObjectType::WD,-5){}

int WD::getStat() {
    return -5;
}
