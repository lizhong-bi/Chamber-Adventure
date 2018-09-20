#ifndef CHARACTER_H
#define CHARACTER_H
#include "object.h"

struct Stats {
    int hp, atk, def,potionAtk,potionDef;
};


class Character : public Object
{
    public:
        Character(int x, int y, int hp, int atk, int def, ObjectType t);
        virtual ~Character();
        bool takeDamage(int damage);
        Stats getStats();
	int getGold();
	void setHP(int val) override;
	void newHP(int val);
    protected:
        int hp, atk, def, hpMax;
};

#endif // CHARACTER_H
