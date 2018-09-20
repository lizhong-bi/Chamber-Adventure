#include "gold.h"

Gold::Gold(int x, int y,ObjectType t, int val): Item(x,y,t,val){};

bool Gold::canPick() {
    return (!this->isGuarded);
}

int Gold::getVal() {
    return this->val;
}

void Gold::isHoard(bool b){
    this->isGuarded = b;
}
