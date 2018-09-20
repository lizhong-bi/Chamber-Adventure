#include "item.h"

Item::Item(int x, int y,ObjectType t, int val): Object(x,y,t,val){};

void Item::usedUp() {
    delete this;
}

Item::~Item(){}

void Item::setHP(int val){
    //does nothing
}
