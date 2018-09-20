#ifndef BLANK_H
#define BLANK_H
#include "object.h"

class blank:public Object{
public:
  blank(int x,int y, ObjectType type);
  ~blank() override;
};

#endif
