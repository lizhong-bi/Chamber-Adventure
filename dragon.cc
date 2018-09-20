#include "dragon.h"
#include "objecttype.h"
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include "shade.h"
#include "vampire.h"
#include "drow.h"
#include "troll.h"
#include "goblin.h"
Dragon::Dragon(int x, int y) : Enemy(x, y, 150, 20, 20, ObjectType::Dragon) {}

void Dragon::setHoard(int x, int y) {
  this->rowHoard = x;
  this->colHoard = y;
}

int Dragon::getHoard_x() {
  return this->rowHoard;
}

int Dragon::getHoard_y() {
  return this->colHoard;
}
void Dragon::notify(Player *who){
    if(-1<=who->getrow()-getrow() && who->getrow()-getrow()<=1 && -1<=who->getcol()-getcol()&&who->getcol()-getcol()<=1)
        aggro = true;
    else if(-1<=who->getrow()-rowHoard && who->getrow()-rowHoard<=1 && -1<=who->getcol()-colHoard&&who->getcol()-colHoard<=1)
        aggro = true;
    else
        aggro = false;
}

bool Dragon::getAttacked(Player &p){
    p.attack(*this);
    if(this->hp<=0) return true;
    return false;
}

void Dragon::attack(Player &p){
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "D deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "D missed.";
    }
}

void Dragon::attack(Shade &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "D deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "D missed.";
    }
}
void Dragon::attack(Drow &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+1.5*p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "D deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "D missed.";
    }
}
void Dragon::attack(Vampire &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "D deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "D missed.";
    }
}
void Dragon::attack(Troll &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "D deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "D missed.";
    }
}
void Dragon::attack(Goblin &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "D deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "D missed.";
    }
}
