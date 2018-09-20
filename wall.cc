#include "wall.h"

using namespace std;

wall::wall(int x, int y, ObjectType type): Object(x,y,type){}
  //:x{x},y{y},type{"wall"},isHorizontal{false} override  {}

wall::~wall() {}

void wall::setTag(bool tag) {
  this->isHorizontal = tag;
}

bool wall::horizontal () {
  return this->isHorizontal;
}
