#include "orcs.h"
#include "objecttype.h"
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include "shade.h"
#include "vampire.h"
#include "drow.h"
#include "troll.h"
#include "goblin.h"
Orcs::Orcs(int x, int y) : Enemy(x, y, 180, 30, 25, ObjectType::Orcs) {}

void Orcs::attack(Goblin &p){
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk*1.5;
        p.takeDamage((int)ceil(damage));
        action = "O deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "O missed.";
    }
}

void Orcs::attack(Player &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "O deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "O missed.";
    }
}

void Orcs::attack(Shade &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "O deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "O missed.";
    }
}
void Orcs::attack(Drow &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+1.5*p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "O deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "O missed.";
    }
}
void Orcs::attack(Vampire &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "O deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "O missed.";
    }
}
void Orcs::attack(Troll &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "O deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "O missed.";
    }
}

bool Orcs::getAttacked(Player &p){
    p.attack(*this);
    if(this->hp<=0) return true;
    return false;
}
