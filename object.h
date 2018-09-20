#ifndef OBJECT_H
#define OBJECT_H
#include "objecttype.h"
#include "subject.h"
#include <string>

// struct Position {int x; int y;};
/*
struct Position {
  int x;
  int y;
  Position() {
    this->x = 0;
    this->y = 0;
  }
  Position &operator=(Position && other) {
    this->x = other.x;
    this->y = other.y;
    return *this;
  }
};*/

class Object: public Subject {
protected:
  int x;
  int y;
  ObjectType Type;
  int val;
  int potionAtk = 0;
  int potionDef = 0;
  std::string action = "";
  Object(int x, int y, ObjectType t);
  Object(int x, int y, ObjectType t, int val);
public:
  ObjectType getType();
  void setPos(int row, int col);
  // Position &getPos(); // commented out at 6:06 Jul23
  int &getrow();
  int &getcol();
  virtual ~Object() = 0;
  std::string getAction();
  void setPotionAtk (int val);
  void setPotionDef (int val);
  void clearPotionAtk ();
  void clearPotionDef ();
  virtual void setHP (int val);
  bool canPick();
  int getVal();
};

#endif
