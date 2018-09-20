#ifndef PASSAGE_H
#define PASSAGE_H
#include "object.h"

class passage:public Object{
public:
  passage(int x, int y, ObjectType type);
  ~passage() override;
};

#endif
