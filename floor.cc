#include "floor.h"
#include "gold.h"
#include <vector>
#include "shade.h"
#include "vampire.h"
#include "goblin.h"
#include "troll.h"
#include "drow.h"
#include "stairs.h"

using namespace std;
struct Position;

floor::floor() {
  //  this->td = new TerowtDisplacol();
}

floor::~floor() {
    delete curTile;
    for(unsigned int i=0; i<theGrid.size(); i++){
        for(unsigned int j=0; j<theGrid[i].size(); j++){
            delete theGrid[i][j];
        }
    }
    curTile = nullptr;
    p = nullptr;
    stairway = nullptr;
}

bool floor::isEmpty(int row, int col){
  ObjectType type = theGrid[row][col]->getType();
  return (type == ObjectType::blank);
}

bool floor::isStairs(int row, int col) {
  ObjectType type = theGrid[row][col]->getType();
  return (type == ObjectType::stairs);
}

bool floor::canMove(int row, int col){
  ObjectType type = theGrid[row][col]->getType();
  if (type==ObjectType::blank||type==ObjectType::door||type==ObjectType::passage||
      type==ObjectType::stairs||type==ObjectType::Gold) { return true; }
  return false;
}

bool floor::isEnemy(int row, int col){
  ObjectType t = theGrid[row][col]->getType();
  if (t==ObjectType::Dragon||t==ObjectType::Dwarf||t==ObjectType::Elf||t==ObjectType::Halfling||
      t==ObjectType::Human||t==ObjectType::Merchant||t==ObjectType::Orcs) {return true;}
  else {return false;}
}

void floor::setPlayer(Player *p, int row, int col){
  curTile = theGrid[row][col];
  theGrid[row][col] = p; //o should be heap allocated
  // TO-DO: clear observers
  for(unsigned int i=0; i<enemies.size(); i++){
    p->attach(enemies[i]);
  }
  this->p = p;
}

void floor::setEnemy(Enemy *e, int row, int col){
  delete theGrid[row][col];
  theGrid[row][col] = e; //o should be heap allocated
  enemies.push_back(e);
  this->p->attach(e);
}

void floor::setItems(Object *p, int row, int col){
  delete theGrid[row][col];
  theGrid[row][col] = p; //o should be heap allocated
}


void floor::init (int start, int end, ifstream& file, string race) {
  // ifstream file {argv[1]};
  char c;
  string s;
  for (int i = start,u = 0; i < end; ++i,++u) {
    getline (file, s);
    istringstream iss{s};
    vector <Object * > v;
    int j = 0;
    while (iss >> noskipws >> c){
      if (c == '|') {
        Object * obj = new wall(u,j, ObjectType::wall);
        v.push_back (obj);
      } else if (c == '-') {
        Object * obj = new wall(u,j,ObjectType::horizontalwall);
        v.push_back (obj);
      } else if ((c == 32)||(c == 9)) {
        Object * obj = new emptytile(u,j, ObjectType::emptytile);
        v.push_back (obj);
      } else if ( c == '+') {
        Object * obj = new door(u,j, ObjectType::door);
        v.push_back (obj);
      } else if (c == '#') {
        Object * obj = new passage(u,j, ObjectType::passage);
        v.push_back (obj);
      } else if (c == '.') {
        Object * obj = new blank(u,j, ObjectType::blank);
        v.push_back (obj);
      } else if (c == 'H'){
        Enemy * obj = new Human(u,j);
        enemies.push_back(obj);
        v.push_back (obj);// character class goes here
      } else if (c == 'W'){
        Enemy * obj = new Dwarf (u,j);
        enemies.push_back(obj);
        v.push_back (obj);// character class goes here
      } else if (c == 'E'){
        Enemy * obj = new Elf (u,j);
        enemies.push_back(obj);
        v.push_back (obj);// character class goes here
      } else if (c == 'O'){
        Enemy * obj = new Orcs (u,j);
        enemies.push_back(obj);
        v.push_back (obj);// character class goes here
      } else if (c == 'M'){
        Enemy * obj = new Merchant (u,j);
        enemies.push_back(obj);
        v.push_back (obj);// character class goes here
      } else if (c == 'D'){
        Enemy * obj = new Dragon (u,j);
        enemies.push_back(obj);
        v.push_back (obj);// character class goes here
      } else if (c == 'L'){
        Enemy * obj = new Halfling (u,j);
        enemies.push_back(obj);
        v.push_back (obj);// character class goes here
      } else if (c == '0') {
        Object * obj = new RH(u,j);
        v.push_back (obj);
      } else if (c == '1') {
        Object * obj = new BA(u,j);
        v.push_back (obj);
      } else if (c == '2') {
        Object * obj = new BD(u,j);
        v.push_back (obj);
      } else if (c == '3') {
        Object * obj = new PH(u,j);
        v.push_back (obj);
      } else if (c == '4') {
        Object * obj = new WA(u,j);
        v.push_back (obj);
      } else if (c == '5') {
        Object * obj = new WD(u,j);
        v.push_back (obj);
      } else if (c == '6') {
        Object * obj = new Gold(u,j,ObjectType::Gold,2);
        v.push_back (obj);
      } else if (c == '7') {
        Object * obj = new Gold(u,j,ObjectType::Gold,1);
        v.push_back (obj);
      }  else if (c == '8') {
        Object * obj = new Gold(u,j,ObjectType::Gold,4);
        v.push_back (obj);
      }  else if (c == '9') {
        Object * obj = new Gold(u,j,ObjectType::Gold,6);
        v.push_back (obj);
      } else if (c == '@') {
        curTile = new blank(u,j,ObjectType::blank);
        if(race=="s"){
          Player *obj = new Shade(u,j);
          v.push_back (obj);
          this->p = obj;
        } else if(race=="v"){
          Player *obj = new Vampire(u,j);
          v.push_back (obj);
          this->p = obj;
        } else if(race=="t"){
          Player *obj = new Troll(u,j);
          v.push_back (obj);
          this->p = obj;
        } else if(race=="d"){
          Player *obj = new Drow(u,j);
          v.push_back (obj);
          this->p = obj;
        } else if(race=="g"){
          Player *obj = new Goblin(u,j);
          v.push_back (obj);
          this->p = obj;
        }
      } else if (c == '\\') {
        Object *obj = new stairs(u,j);
        v.push_back(obj);
        this->stairway = obj;
      } else {
        ++j;
        continue;
      }
      ++j;
    } //while ends
    theGrid.push_back (v);
  } //for ends
  // cout << "Done adding objects" << endl;
  for(unsigned int i=0; i<enemies.size(); i++){
    p->attach(enemies[i]);
    /*
    if(enemies[i]->getType()==ObjectType::Dragon){
        Dragon *d = static_cast<Dragon *>(enemies[i]);
        int r = enemies[i]->getrow();
        int c = enemies[i]->getcol();
        for(int j=-1; j<=1; j++){
            for(int k=-1; k<=1; k++){
                if(theGrid[r+j][c+k]->getType() == ObjectType::Gold){
                    Gold *temp = static_cast<Gold *>(theGrid[r+j][c+k]);
                    if(temp->getVal()==6){
                        d->setHoard(temp->getcol(), temp->getcol());
                    }
                }
            }
        }
    }
    */
  }
}

// u(row) refers to row and j(col) refers to an element in that row.
////////////////////////////////////////////////////////////////////
void floor::movePlayer(Player *p, int otherRow, int otherCol) {
    swap(curTile, theGrid[p->getrow()][p->getcol()]);
    swap(curTile, theGrid[otherRow][otherCol]);
    p->movePlayer(otherRow, otherCol);
}
int floor::playerAttack(Player &p, int row, int col){
    Enemy *e = static_cast<Enemy *>(theGrid[row][col]);
    //attack, and then check if enemy is dead
    if(e->getAttacked(p)){
        replaceWithBlank(row, col);
        return 0;
    }
    return e->getStats().hp;
}
////////////////////////////////////////////////////////////////////

void floor::moveEnemy(Enemy *e, int newRow, int newCol){
    theGrid[newRow][newCol]->setPos(e->getrow(), e->getcol());
    swap(theGrid[e->getrow()][e->getcol()], theGrid[newRow][newCol]);
    e->moveEnemy(newRow, newCol);
}

void floor::replaceWithBlank(int row, int col){
    if(isEnemy(row, col)){
        for(unsigned int i=0; i<enemies.size(); i++){
            if(enemies[i]->getrow() == row && enemies[i]->getcol()==col){
                p->detach(enemies[i]);
                enemies.erase(enemies.begin()+i);
                break;
            }
        }
    }
    delete theGrid[row][col];
    theGrid[row][col] = new blank(row,col, ObjectType::blank);
}
