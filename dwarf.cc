#include "dwarf.h"
#include "objecttype.h"
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include "shade.h"
#include "vampire.h"
#include "drow.h"
#include "troll.h"
#include "goblin.h"
Dwarf::Dwarf(int x, int y) : Enemy(x, y, 100, 20, 30, ObjectType::Dwarf) {}
bool Dwarf::getAttacked(Player &p){
    p.attack(*this);
    if(this->hp<=0) return true;
    return false;
}

void Dwarf::attack(Player &p){
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "W deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "W missed.";
    }
}

void Dwarf::attack(Shade &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "W deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "W missed.";
    }
}
void Dwarf::attack(Drow &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+1.5*p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "X deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "X missed.";
    }
}
void Dwarf::attack(Vampire &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "W deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "W missed.";
    }
}
void Dwarf::attack(Troll &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "W deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "W missed.";
    }
}
void Dwarf::attack(Goblin &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "W deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "W missed.";
    }
}
