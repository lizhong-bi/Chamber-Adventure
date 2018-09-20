#include "halfling.h"
#include "objecttype.h"
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include "shade.h"
#include "vampire.h"
#include "drow.h"
#include "troll.h"
#include "goblin.h"
Halfling::Halfling(int x, int y) : Enemy(x, y, 100, 15, 20, ObjectType::Halfling) {}

bool Halfling::getAttacked(Player &p){
    p.attack(*this);
    if(this->hp<=0) return true;
    return false;
}


void Halfling::attack(Player &p){
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "L deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "L missed.";
    }
}

void Halfling::attack(Shade &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "L deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "L missed.";
    }
}
void Halfling::attack(Drow &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+1.5*p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "L deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "L missed.";
    }
}
void Halfling::attack(Vampire &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "L deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "L missed.";
    }
}
void Halfling::attack(Troll &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "L deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "L missed.";
    }
}
void Halfling::attack(Goblin &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "L deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "L missed.";
    }
}
