#ifndef EMPTY_H
#define EMPTY_H
#include "object.h"

class emptytile:public Object{
public:
  emptytile(int x,int y, ObjectType type);
  ~emptytile() override;
};

#endif
