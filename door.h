#ifndef DOOR_H
#define DOOR_H
#include "object.h"

class door:public Object{
public:
  door(int x, int y, ObjectType type);
  ~door() override;
};

#endif
