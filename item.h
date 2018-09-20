#ifndef A5_ITEM_H
#define A5_ITEM_H
#include "object.h"
enum class ObjectType;

class Item : public Object{
protected:
    int val;
    Item(int x, int y, ObjectType t, int val);
public:
    virtual ~Item() = 0;
    virtual void usedUp();
    void setHP(int val) override ;
};
#endif

