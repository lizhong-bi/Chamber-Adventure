#include "human.h"
#include "objecttype.h"
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include "shade.h"
#include "vampire.h"
#include "drow.h"
#include "troll.h"
#include "goblin.h"

Human::Human(int x, int y) : Enemy(x, y, 140, 20, 20, ObjectType::Human) {}

bool Human::getAttacked(Player &p){
    p.attack(*this);
    if(this->hp<=0) return true;
    return false;
}


void Human::attack(Player &p){
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "H deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "H missed.";
    }
}

void Human::attack(Shade &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "H deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "H missed.";
    }
}
void Human::attack(Drow &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+1.5*p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "H deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "H missed.";
    }
}
void Human::attack(Vampire &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "H deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "H missed.";
    }
}
void Human::attack(Troll &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "H deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "H missed.";
    }
}
void Human::attack(Goblin &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "H deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "H missed.";
    }
}
