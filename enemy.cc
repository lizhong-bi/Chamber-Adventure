#include "enemy.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "playerCharacter.h"
#include "floor.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
enum class ObjectType;

Enemy::Enemy(int x, int y, int hp, int atk, int def, ObjectType t) : Character(x, y, hp, atk, def, t), aggro{false} {}


void Enemy::moveEnemy(int newRow, int newCol) {
    this->x = newRow;
    this->y = newCol;
    action = "";
}

// if player is within the range of enemy, aggro
void Enemy::notify(Player *who){
    if(-1<=who->getrow()-getrow() && who->getrow()-getrow()<=1 && -1<=who->getcol()-getcol()&&who->getcol()-getcol()<=1)
        aggro = true;
    else
        aggro = false;
}
bool Enemy::isAggroed(){
    return aggro;
}


void Enemy::attack(Player &p){
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "X deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "X missed.";
    }
}

void Enemy::attack(Shade &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "X deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "X missed.";
    }
}
void Enemy::attack(Drow &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+1.5*p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "X deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "X missed.";
    }
}
void Enemy::attack(Vampire &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "X deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "X missed.";
    }
}
void Enemy::attack(Troll &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "X deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "X missed.";
    }
}
void Enemy::attack(Goblin &p) {
    srand(time(nullptr));
    if(rand()%2){
        double damage = (100.0/(100+(p.getStats().def+p.getStats().potionDef)))*this->getStats().atk;
        p.takeDamage((int)ceil(damage));
        action = "X deals " + std::to_string((int)ceil(damage)) + " damage to PC.";
    } else {
        action = "X missed.";
    }
}
