#ifndef WALL_H
#define WALL_H
#include "object.h"

class wall: public Object {
  bool isHorizontal; // true if the wall is a horizontal
                     // wall otherwise false
public:
  wall(int x, int y, ObjectType type);
  ~wall() override;
  void setTag(bool tag);
  bool horizontal ();
};

#endif
