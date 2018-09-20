#include "merchant.h"
#include "objecttype.h"
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include "shade.h"
#include "vampire.h"
#include "drow.h"
#include "troll.h"
#include "goblin.h"

Merchant::Merchant(int x, int y) : Enemy(x, y, 30, 70, 5, ObjectType::Merchant) {}

bool Merchant::getAttacked(Player &p){
    p.attack(*this);
    if(this->hp<=0) return true;
    return false;
}


void Merchant::attack(Player &p){
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "M deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "M missed.";
    }
}

void Merchant::attack(Shade &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "M deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "M missed.";
    }
}
void Merchant::attack(Drow &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+1.5*p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "M deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "M missed.";
    }
}
void Merchant::attack(Vampire &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "M deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "M missed.";
    }
}
void Merchant::attack(Troll &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "M deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "M missed.";
    }
}
void Merchant::attack(Goblin &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "M deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "M missed.";
    }
}
