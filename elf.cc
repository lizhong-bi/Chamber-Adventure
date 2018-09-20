#include "elf.h"
#include "objecttype.h"
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include "shade.h"
#include "vampire.h"
#include "drow.h"
#include "troll.h"
#include "goblin.h"
Elf::Elf(int x, int y) : Enemy(x, y, 140, 30, 10, ObjectType::Elf) {}


bool Elf::getAttacked(Player &p){
    p.attack(*this);
    if(this->hp<=0) return true;
    return false;
}

void Elf::attack(Drow &p){
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+1.5*p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "E deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "E missed.";
    }
}


void Elf::attack(Player &p){
    srand(time(nullptr));
    int total=0;
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        total += (int)ceil(damage);
        p.takeDamage(total);
    }
    if(rand()%2){
        double damage2 = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        total += (int)ceil(damage2);
        p.takeDamage((int)ceil(damage2));
    }
    action = "E deals " + std::to_string(total) + " damage to PC.";
}

void Elf::attack(Shade &p){
    srand(time(nullptr));
    int total=0;
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        total += (int)ceil(damage);
        p.takeDamage(total);
    }
    if(rand()%2){
        double damage2 = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        total += (int)ceil(damage2);
        p.takeDamage((int)ceil(damage2));
    }
    action = "E deals " + std::to_string(total) + " damage to PC.";
}
void Elf::attack(Vampire &p){
    srand(time(nullptr));
    int total=0;
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        total += (int)ceil(damage);
        p.takeDamage(total);
    }
    if(rand()%2){
        double damage2 = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        total += (int)ceil(damage2);
        p.takeDamage((int)ceil(damage2));
    }
    action = "E deals " + std::to_string(total) + " damage to PC.";
}
void Elf::attack(Troll &p){
    srand(time(nullptr));
    int total=0;
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        total += (int)ceil(damage);
        p.takeDamage(total);
    }
    if(rand()%2){
        double damage2 = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        total += (int)ceil(damage2);
        p.takeDamage((int)ceil(damage2));
    }
    action = "E deals " + std::to_string(total) + " damage to PC.";
}
void Elf::attack(Goblin &p){
    srand(time(nullptr));
    int total=0;
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        total += (int)ceil(damage);
        p.takeDamage(total);
    }
    if(rand()%2){
        double damage2 = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        total += (int)ceil(damage2);
        p.takeDamage((int)ceil(damage2));
    }
    action = "E deals " + std::to_string(total) + " damage to PC.";
}
