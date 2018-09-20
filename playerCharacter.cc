#include "playerCharacter.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "dragon.h"
#include "dwarf.h"
#include "elf.h"
#include "halfling.h"
#include "human.h"
#include "merchant.h"
#include "orcs.h"
enum class ObjectType;


Player::Player(int x, int y, int hp, int atk, int def, ObjectType t) : Character(x, y, hp, atk, def, t) {}

void Player::movePlayer(int newRow, int newCol){
    x = newRow;
    y = newCol;
    // notify enemies that the player moved here
    this->notifyObservers();
}
void Player::notifyObservers(){
    for (Observer *ob: observers){
        ob->notify(this);
    }
}

/*
void Player::setPotionAtk (int val)
{
    this->potionAtk += val;
}


void Player::setPotionDef (int val)
{
    this->potionDef += val;
}

*/
void Player::attack(Enemy &e)
{
    ObjectType type = this->getType();
    double damage;
    if(type == ObjectType::Drow)
    damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+(1.5 * this->getStats().potionAtk));
    else
    damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+this->getStats().potionAtk);
    e.takeDamage((int)ceil(damage));
    notifyObservers();
}

void Player::attack(Halfling &e)
{
    srand(time(nullptr));
    if(rand()%2){
        double damage;
        ObjectType type = this->getType();
        if(type == ObjectType::Drow)
            damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+(1.5 * this->getStats().potionAtk));
        else
            damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+this->getStats().potionAtk);
        e.takeDamage((int)ceil(damage));
    }
    notifyObservers();
}

void Player::attack(Human &e)
{
    ObjectType type = this->getType();
    double damage;
    if(type == ObjectType::Drow)
    damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+(1.5 * this->getStats().potionAtk));
    else
    damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+this->getStats().potionAtk);
    e.takeDamage((int)ceil(damage));
    notifyObservers();
}

void Player::attack(Dwarf &e)
{
    ObjectType type = this->getType();
    double damage;
    if(type == ObjectType::Drow)
    damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+(1.5 * this->getStats().potionAtk));
    else
    damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+this->getStats().potionAtk);
    e.takeDamage((int)ceil(damage));
    notifyObservers();
}

void Player::attack(Elf &e)
{
    ObjectType type = this->getType();
    double damage;
    if(type == ObjectType::Drow)
    damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+(1.5 * this->getStats().potionAtk));
    else
    damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+this->getStats().potionAtk);
    e.takeDamage((int)ceil(damage));
    notifyObservers();
}

void Player::attack(Orcs &e)
{
    ObjectType type = this->getType();
    double damage;
    if(type == ObjectType::Drow)
    damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+(1.5 * this->getStats().potionAtk));
    else
    damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+this->getStats().potionAtk);
    e.takeDamage((int)ceil(damage));
    notifyObservers();
}

void Player::attack(Merchant &e)
{
    ObjectType type = this->getType();
    double damage;
    if(type == ObjectType::Drow)
    damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+(1.5 * this->getStats().potionAtk));
    else
    damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+this->getStats().potionAtk);
    e.takeDamage((int)ceil(damage));
    notifyObservers();
}

void Player::attack(Dragon &e)
{
    ObjectType type = this->getType();
    double damage;
    if(type == ObjectType::Drow)
    damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+(1.5 * this->getStats().potionAtk));
    else
    damage = (100.0/(100+e.getStats().def))*(this->getStats().atk+this->getStats().potionAtk);
    e.takeDamage((int)ceil(damage));
    notifyObservers();
}
