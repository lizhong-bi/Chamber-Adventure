#include "object.h"

using namespace std;

Object::Object(int x, int y, ObjectType t):x{x},y{y},Type{t}{}
Object::Object(int x, int y, ObjectType t,int val):x{x},y{y},Type{t},val{val}{}

ObjectType Object::getType() {
  return this->Type;
}

void Object::setPos(int row, int col) {
  this->x = row;
  this->y = col;
}

string Object::getAction(){
    return action;
}

/*
Position &Object::getPos() {
  Position p;
  p.x = this->x;
  p.y = this->y;
  return p;
}*/

int &Object::getrow() {
  return this->x;
}

int &Object::getcol() {
  return this->y;
}

void Object::setPotionAtk (int val)
{
    this->potionAtk += val;
}

void Object::setPotionDef (int val)
{
    this->potionDef += val;
}

void Object::clearPotionAtk () {
  this->potionDef = 0;
}
void Object::clearPotionDef () {
  this->potionAtk = 0;
}

void Object::setHP(int val)
{
    //waiting for override
}

bool Object::canPick()
{
    return true;
}

int Object::getVal()
{
    return this->val;
}

Object::~Object() {}
