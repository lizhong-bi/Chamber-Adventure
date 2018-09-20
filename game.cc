#include "game.h"
#include "gold.h"
#include <stdlib.h>
#include <time.h>
#include "chamber.h"
#include <iostream>
#include "stairs.h"


using namespace std;

Game::Game():f{false}, action{""}{
  srand(time(nullptr));
}

Game::Game(string race){
  ifstream d{"default.txt"};
  for (int i = 0; i < 5; ++i){
    flrs.push_back(new floor());
  }
  level = 0;
  flrs[level]->init(0,25,d,race);
  curLevel = flrs[level];
  spawnPlayer(race);
  spawnStair();
  spawnItems();
  spawnEnemies();
  action += "Player character has spawned.";
}

Game::Game(string race, ifstream& file){
  for (int i = 0; i < 5; ++i){
    flrs.push_back(new floor());
  }
  level = 0;
  int start = 0;
  int end = 25;
  for (int i = 0; i < 5; ++i) {
    flrs[i]->init(start, end, file, race);
    start += 25;
    end += 25;
  }   curLevel = flrs[level];
  this->p = curLevel->p;
  action += "Player character has spawned.";
}

Game::~Game(){
  //delete p;
  for (int i = 0; i < 5; ++i) {
    delete flrs[i];
  }
  curLevel = nullptr;
}

void Game::nextlevel(bool noFile, string race) {
  ifstream d{"default.txt"};
  ++level;
  if (level <= 4) {
    int hp = p->getStats().hp;
    curLevel = flrs[level];
    if (noFile) {
      //set player randomly
      flrs[level]->init(0,25,d,race);
      spawnPlayer(race);
      curLevel->p->newHP(hp);
      p = curLevel->p;
      spawnStair();
      spawnItems();
      spawnEnemies();
    } else {
      curLevel->p->newHP(hp);
      p = curLevel->p;
    }
  }
}

void Game::spawnPlayer(string race){
  //generate random location
  int row, col;
  srand(time(nullptr));
  do{
    row = rand()%floor::HEIGHT;
    col = rand()%floor::WIDTH;
  } while(!curLevel->isEmpty(row, col)); // make sure the location is empty

  // create new player based  on race
  if(race=="s")
  p = new Shade(row, col);
  else if(race=="d")
  p = new Drow(row, col);
  else if(race=="v")
  p = new Vampire(row, col);
  else if(race=="g")
  p = new Goblin(row, col);
  else if(race=="t")
  p = new Troll(row, col);

  //add player to the floor
  curLevel->setPlayer(p, row, col);
}

void Game::spawnStair() {
  vector <chamber> c;
  c.push_back(chamber(3,6,3,16));
  c.push_back(chamber(3,6,17,28));
  c.push_back(chamber(3,6,39,60));
  c.push_back(chamber(7,12,31,75));//
  c.push_back(chamber(10,12,38,44));
  c.push_back(chamber(10,12,45,49));//
  c.push_back(chamber(15,21,4,14));
  c.push_back(chamber(15,21,15,24));//
  c.push_back(chamber(16,21,65,75));
  c.push_back(chamber(19,21,37,64));

  int random_index = rand()%10;
  int random_row;
  int random_col;

  int x1 = c[random_index].getstart_x();
  int x2 = c[random_index].getend_x();
  int y1 = c[random_index].getstart_y();
  int y2 = c[random_index].getend_y();
  do{
    random_row = (rand()%(x2-x1))+x1;
    random_col = (rand()%(y2-y1))+y1;
  } while(!curLevel->isEmpty(random_row, random_col)); // make sure the location is empty

  curLevel->setItems(new stairs(random_row, random_col), random_row, random_col);
}

void Game::spawnItems() {
  vector <ObjectType> Potions;
  Potions.push_back(ObjectType::RH);
  Potions.push_back(ObjectType::PH);
  Potions.push_back(ObjectType::BA);
  Potions.push_back(ObjectType::BD);
  Potions.push_back(ObjectType::WA);
  Potions.push_back(ObjectType::WD);

  vector <chamber> c;
  c.push_back(chamber(3,6,3,16));
  c.push_back(chamber(3,6,17,28));
  c.push_back(chamber(3,6,39,60));
  c.push_back(chamber(7,12,31,75));//
  c.push_back(chamber(10,12,38,44));
  c.push_back(chamber(10,12,45,49));//
  c.push_back(chamber(15,21,4,14));
  c.push_back(chamber(15,21,15,24));//
  c.push_back(chamber(16,21,65,75));
  c.push_back(chamber(19,21,37,64));

  for (int i = 0; i < 10; ++i) {
    int random_index = rand()%10;
    int random_row;
    int random_col;

    int x1 = c[random_index].getstart_x();
    int x2 = c[random_index].getend_x();
    int y1 = c[random_index].getstart_y();
    int y2 = c[random_index].getend_y();
    do{
      random_row = (rand()%(x2-x1))+x1;
      random_col = (rand()%(y2-y1))+y1;
    } while(!curLevel->isEmpty(random_row, random_col)); // make sure the location is empty

    random_index = rand()%6;
    ObjectType type = Potions[random_index];

    if (type == ObjectType::RH) {
      curLevel->setItems(new RH(random_row, random_col), random_row, random_col);
    } else if (type == ObjectType::PH){
      curLevel->setItems(new PH(random_row, random_col), random_row, random_col);
    } else if (type == ObjectType::BA) {
      curLevel->setItems(new BA(random_row, random_col), random_row, random_col);
    } else if (type == ObjectType::BD){
      curLevel->setItems(new BD(random_row, random_col), random_row, random_col);
    } else if (type == ObjectType::WA) {
      curLevel->setItems(new WA(random_row, random_col), random_row, random_col);
    } else if (type == ObjectType::WD) {
      curLevel->setItems(new WD(random_row, random_col), random_row, random_col);
    }
  }
  vector <string> gold;
  gold.push_back("normal");
  gold.push_back("normal");
  gold.push_back("normal");
  gold.push_back("normal");
  gold.push_back("normal");
  gold.push_back("dragon");
  gold.push_back("small");
  gold.push_back("small");

  for (int i = 0; i < 10; ++i) {
    int random_index = rand()%10;
    int random_row;
    int random_col;

    int x1 = c[random_index].getstart_x();
    int x2 = c[random_index].getend_x();
    int y1 = c[random_index].getstart_y();
    int y2 = c[random_index].getend_y();
    do{
      random_row = (rand()%(x2-x1))+x1;
      random_col = (rand()%(y2-y1))+y1;
    } while(!curLevel->isEmpty(random_row, random_col)); // make sure the location is empty

    random_index = rand()%8;
    string type = gold[random_index];

    if (type == "normal") {
      curLevel->setItems(new Gold(random_row, random_col,ObjectType::Gold,2), random_row, random_col);
    } else if (type == "small"){
      curLevel->setItems(new Gold(random_row, random_col,ObjectType::Gold,1), random_row, random_col);
    } else if (type == "dragon") {
      curLevel->setItems(new Gold(random_row, random_col,ObjectType::Gold,6), random_row, random_col);
        int dragon_row=0;
        int dragon_col=0;

      do{
        dragon_row = (rand()%((random_row+1)-(random_row-1)))+(random_row-1);
        dragon_col = (rand()%((random_col+1)-(random_col-1)))+(random_col-1);
      } while(!curLevel->isEmpty(dragon_row, dragon_col)); // make sure the location is empty
      Dragon *e = new Dragon(dragon_row,dragon_col);
      e->setHoard(random_row,random_col);
      curLevel->setEnemy(e,dragon_row,dragon_col);
    }
  }
}




void Game::spawnEnemies() {
  vector <ObjectType> EnemyRace;
  EnemyRace.push_back(ObjectType::Human);
  EnemyRace.push_back(ObjectType::Human);
  EnemyRace.push_back(ObjectType::Human);
  EnemyRace.push_back(ObjectType::Human);
  EnemyRace.push_back(ObjectType::Dwarf);
  EnemyRace.push_back(ObjectType::Dwarf);
  EnemyRace.push_back(ObjectType::Dwarf);
  EnemyRace.push_back(ObjectType::Halfling);
  EnemyRace.push_back(ObjectType::Halfling);
  EnemyRace.push_back(ObjectType::Halfling);
  EnemyRace.push_back(ObjectType::Halfling);
  EnemyRace.push_back(ObjectType::Halfling);
  EnemyRace.push_back(ObjectType::Elf);
  EnemyRace.push_back(ObjectType::Elf);
  EnemyRace.push_back(ObjectType::Orcs);
  EnemyRace.push_back(ObjectType::Orcs);
  EnemyRace.push_back(ObjectType::Merchant);
  EnemyRace.push_back(ObjectType::Merchant);

  vector <chamber> c;
  c.push_back(chamber(3,6,3,16));
  c.push_back(chamber(3,6,17,28));
  c.push_back(chamber(3,6,39,60));
  c.push_back(chamber(7,12,31,75));//
  c.push_back(chamber(10,12,38,44));
  c.push_back(chamber(10,12,45,49));//
  c.push_back(chamber(15,21,4,14));
  c.push_back(chamber(15,21,15,24));//
  c.push_back(chamber(16,21,65,75));
  c.push_back(chamber(19,21,37,64));
  /*
  c.push_back(chamber(10,12,38,49));
  c.push_back(chamber(7,12,61,75));
  c.push_back(chamber(10,12,38,49));
  c.push_back(chamber(16,18,65,75));
  c.push_back(chamber(19,21,37,75));
  c.push_back(chamber(15,21,4,24));*/

  srand(time(nullptr));
  // spawning Human enemies
  for (int i = 0; i < 20; ++i) {
    int random_index = rand()%10;
    int random_row;
    int random_col;

    int x1 = c[random_index].getstart_x();
    int x2 = c[random_index].getend_x();
    int y1 = c[random_index].getstart_y();
    int y2 = c[random_index].getend_y();
    do{
      random_row = (rand()%(x2-x1))+x1;
      random_col = (rand()%(y2-y1))+y1;
    } while(!curLevel->isEmpty(random_row, random_col)); // make sure the location is empty

    random_index = rand()%18;
    ObjectType type = EnemyRace[random_index];

    if (type == ObjectType::Human) {
      curLevel->setEnemy(new Human(random_row, random_col), random_row, random_col);
    } else if (type == ObjectType::Dwarf){
      curLevel->setEnemy(new Dwarf(random_row, random_col), random_row, random_col);
    } else if (type == ObjectType::Halfling) {
      curLevel->setEnemy(new Halfling(random_row, random_col), random_row, random_col);
    } else if (type == ObjectType::Elf){
      curLevel->setEnemy(new Elf(random_row, random_col), random_row, random_col);
    } else if (type == ObjectType::Orcs) {
      curLevel->setEnemy(new Orcs(random_row, random_col), random_row, random_col);
    } else if (type == ObjectType::Merchant) {
      curLevel->setEnemy(new Merchant(random_row, random_col), random_row, random_col);
    }
  }
}



void Game::movePlayer(string direction, bool noFile,string race){
  /*  Position p;
  p = o->getPos();*/
  int row = p->getrow(); // row number
  int col = p->getcol(); // colth element in rowth row

  p->specialAbility();

  if (direction == "no"){
    if (curLevel->canMove(row-1, col)){
      if(curLevel->theGrid[row-1][col]->getType() == ObjectType::Gold)
      {
        if(curLevel->theGrid[row-1][col]->canPick())
        {
          newGold = curLevel->theGrid[row-1][col]->getVal();
          gold += newGold;
          curLevel->replaceWithBlank(row-1, col);
          curLevel->movePlayer(p, row-1, col);
          action += "PC moves North. PC picked up " + std::to_string(newGold) + " gold. ";
          newGold = 0;
        }

      } else if (curLevel->isStairs(row-1, col)) {
        nextlevel(noFile,race);
      }
      else
      {
        curLevel->movePlayer(p, row-1, col);
        action += "PC moves North.";
      }
    }
  } else if (direction == "ne"){
    // ObjectType type = theGrid[row-1][col+1]->gettype();
    if (curLevel->canMove(row-1, col+1)){
      if(curLevel->theGrid[row-1][col+1]->getType() == ObjectType::Gold)
      {
        if(curLevel->theGrid[row-1][col+1]->canPick())
        {
          newGold = curLevel->theGrid[row-1][col+1]->getVal();
          gold += newGold;
          curLevel->replaceWithBlank(row-1, col+1);
          curLevel->movePlayer(p, row-1, col+1);
          action += "PC moves North East. PC picked up " + std::to_string(newGold) + " gold. ";
          newGold = 0;
        }

      } else if (curLevel->isStairs(row-1, col+1)) {
        nextlevel(noFile,race);
      }
      else
      {
        curLevel->movePlayer(p, row-1, col+1);
        action += "PC moves North East.";
      }
    }
  } else if (direction == "ea"){
    // ObjectType type = theGrid[row][col+1]->gettype();
    //add cases
    if (curLevel->canMove(row, col+1)){
      if(curLevel->theGrid[row][col+1]->getType() == ObjectType::Gold)
      {
        if(curLevel->theGrid[row][col+1]->canPick())
        {
          newGold = curLevel->theGrid[row][col+1]->getVal();
          gold += newGold;
          curLevel->replaceWithBlank(row, col+1);
          curLevel->movePlayer(p, row, col+1);
          action += "PC moves East. PC picked up " + std::to_string(newGold) + " gold. ";
          newGold = 0;
        }

      } else if (curLevel->isStairs(row, col+1)) {
        nextlevel(noFile,race);
      }
      else
      {
        curLevel->movePlayer(p, row, col+1);
        action += "PC moves East.";
      }
    }
  } else if (direction == "se"){
    // ObjectType type = theGrid[row+1][col+1]->gettype();
    //add cases
    if (curLevel->canMove(row+1, col+1)){
      if(curLevel->theGrid[row+1][col+1]->getType() == ObjectType::Gold)
      {
        if(curLevel->theGrid[row+1][col+1]->canPick())
        {
          newGold = curLevel->theGrid[row+1][col+1]->getVal();
          gold += newGold;
          curLevel->replaceWithBlank(row+1, col+1);
          curLevel->movePlayer(p, row+1, col+1);
          action += "PC moves South East. PC picked up " + std::to_string(newGold) + " gold. ";
          newGold = 0;
        }

      } else if (curLevel->isStairs(row+1, col+1)) {
        nextlevel(noFile,race);
      }
      else
      {
        curLevel->movePlayer(p, row+1, col+1);
        action += "PC moves South East.";
      }
    }
  } else if (direction == "so"){
    // ObjectType type = theGrid[row+1][col]->gettype();
    //add cases
    if (curLevel->canMove(row+1, col)){
      if(curLevel->theGrid[row+1][col]->getType() == ObjectType::Gold)
      {
        if(curLevel->theGrid[row+1][col]->canPick())
        {
          newGold = curLevel->theGrid[row+1][col]->getVal();
          gold += newGold;
          curLevel->replaceWithBlank(row+1, col);
          curLevel->movePlayer(p, row+1, col);
          action += "PC moves South. PC picked up " + std::to_string(newGold) + " gold. ";
          newGold = 0;
        }

      } else if (curLevel->isStairs(row+1, col)) {
        nextlevel(noFile,race);
      }
      else
      {
        curLevel->movePlayer(p, row+1, col);
        action += "PC moves South.";
      }
    }
  } else if (direction == "sw"){
    // ObjectType type = theGrid[row+1][col-1]->gettype();
    //add cases
    if (curLevel->canMove(row+1, col-1)){
      if(curLevel->theGrid[row+1][col-1]->getType() == ObjectType::Gold)
      {
        if(curLevel->theGrid[row+1][col-1]->canPick())
        {
          newGold = curLevel->theGrid[row+1][col-1]->getVal();
          gold += newGold;
          curLevel->replaceWithBlank(row+1, col-1);
          curLevel->movePlayer(p, row+1, col-1);
          action += "PC moves South West. PC picked up " + std::to_string(newGold) + " gold. ";
          newGold = 0;
        }

      } else if (curLevel->isStairs(row+1, col-1)) {
        nextlevel(noFile,race);
      }
      else
      {
        curLevel->movePlayer(p, row+1, col-1);
        action += "PC moves South West.";
      }
    }
  } else if (direction == "we"){
    // ObjectType type = theGrid[row][col-1]->gettype();
    //add cases
    if (curLevel->canMove(row, col-1)){
      if(curLevel->theGrid[row][col-1]->getType() == ObjectType::Gold)
      {
        if(curLevel->theGrid[row][col-1]->canPick())
        {
          newGold = curLevel->theGrid[row][col-1]->getVal();
          gold += newGold;
          curLevel->replaceWithBlank(row, col-1);
          curLevel->movePlayer(p, row, col-1);
          action += "PC moves West. PC picked up " + std::to_string(newGold) + " gold. ";
          newGold = 0;
        }

      } else if (curLevel->isStairs(row, col-1)) {
        nextlevel(noFile,race);
      }
      else
      {
        curLevel->movePlayer(p, row, col-1);
        action += "PC moves West.";
      }
    }
  } else if (direction == "nw"){
    // ObjectType type = theGrid[row-1][col-1]->gettype();
    //add cases
    if (curLevel->canMove(row-1, col-1)){
      if(curLevel->theGrid[row-1][col-1]->getType() == ObjectType::Gold)
      {
        if(curLevel->theGrid[row-1][col-1]->canPick())
        {

          newGold = curLevel->theGrid[row-1][col-1]->getVal();
          gold += newGold;
          curLevel->replaceWithBlank(row-1, col-1);
          curLevel->movePlayer(p, row-1, col-1);
          action += "PC moves North East. PC picked up " + std::to_string(newGold) + " gold. ";
          newGold = 0;
        }

      } else if (curLevel->isStairs(row-1, col-1)) {
        nextlevel(noFile,race);
      }
      else
      {
        curLevel->movePlayer(p, row-1, col-1);
        action += "PC moves North West.";
      }
    }
  }

}




void Game::usePotion(string direction, bool noFile, string race){
  /*  Position p;
  p = o->getPos();*/
  int row = p->getrow(); // row number
  int col = p->getcol(); // colth element in rowth row
  p->specialAbility();
  if (direction == "no"){
    if(curLevel->theGrid[row-1][col]->getType() == ObjectType::WA)
    {
      curLevel->theGrid[row][col]->setPotionAtk(-5);
      curLevel->replaceWithBlank(row-1, col);
      movePlayer(direction, noFile, race);
      action += "PC uses WA.";
    }
    else if(curLevel->theGrid[row-1][col]->getType() == ObjectType::BA)
    {
      curLevel->theGrid[row][col]->setPotionAtk(5);
      curLevel->replaceWithBlank(row-1, col);
      movePlayer(direction, noFile, race);
      action += "PC uses BA.";
    }
    else if(curLevel->theGrid[row-1][col]->getType() == ObjectType::WD)
    {
      curLevel->theGrid[row][col]->setPotionDef(-5);
      curLevel->replaceWithBlank(row-1, col);
      movePlayer(direction, noFile, race);
      action += "PC uses WD.";
    }
    else if(curLevel->theGrid[row-1][col]->getType() == ObjectType::BD)
    {
      curLevel->theGrid[row][col]->setPotionDef(5);
      curLevel->replaceWithBlank(row-1, col);
      movePlayer(direction, noFile, race);
      action += "PC uses BD.";
    }
    else if(curLevel->theGrid[row-1][col]->getType() == ObjectType::RH)
    {
      if(curLevel->theGrid[row][col]->getType() == ObjectType::Drow)
      curLevel->theGrid[row][col]->setHP(15);
      else
      curLevel->theGrid[row][col]->setHP(10);
      curLevel->replaceWithBlank(row-1, col);
      movePlayer(direction, noFile, race);
      action += "PC uses RH.";
    }
    else if(curLevel->theGrid[row-1][col]->getType() == ObjectType::PH)
    {
      if(curLevel->theGrid[row][col]->getType() == ObjectType::Drow)
      curLevel->theGrid[row][col]->setHP(-15);
      else
      curLevel->theGrid[row][col]->setHP(-10);
      curLevel->replaceWithBlank(row-1, col);
      movePlayer(direction, noFile, race);
      action += "PC uses PH.";
    }
    //else if (type == gold){
    //pick up the gold and move placoler
  } else if (direction == "ne"){
    if(curLevel->theGrid[row-1][col+1]->getType() == ObjectType::WA)
    {
      curLevel->theGrid[row][col]->setPotionAtk(-5);
      curLevel->replaceWithBlank(row-1, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses WA.";
    }
    else if(curLevel->theGrid[row-1][col+1]->getType() == ObjectType::BA)
    {
      curLevel->theGrid[row][col]->setPotionAtk(5);
      curLevel->replaceWithBlank(row-1, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses BA.";
    }
    else if(curLevel->theGrid[row-1][col+1]->getType() == ObjectType::WD)
    {
      curLevel->theGrid[row][col]->setPotionDef(-5);
      curLevel->replaceWithBlank(row-1, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses WD.";
    }
    else if(curLevel->theGrid[row-1][col+1]->getType() == ObjectType::BD)
    {
      curLevel->theGrid[row][col]->setPotionDef(5);
      curLevel->replaceWithBlank(row-1, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses BD.";
    }
    else if(curLevel->theGrid[row-1][col+1]->getType() == ObjectType::RH)
    {
      if(curLevel->theGrid[row][col]->getType() == ObjectType::Drow)
      curLevel->theGrid[row][col]->setHP(15);
      else
      curLevel->theGrid[row][col]->setHP(10);
      curLevel->replaceWithBlank(row-1, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses RH.";
    }
    else if(curLevel->theGrid[row-1][col+1]->getType() == ObjectType::PH)
    {
      if(curLevel->theGrid[row][col]->getType() == ObjectType::Drow)
      curLevel->theGrid[row][col]->setHP(-15);
      else
      curLevel->theGrid[row][col]->setHP(-10);
      curLevel->replaceWithBlank(row-1, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses PH.";
    }
  } else if (direction == "ea"){
    if(curLevel->theGrid[row][col+1]->getType() == ObjectType::WA)
    {
      curLevel->theGrid[row][col]->setPotionAtk(-5);
      curLevel->replaceWithBlank(row, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses WA.";
    }
    else if(curLevel->theGrid[row][col+1]->getType() == ObjectType::BA)
    {
      curLevel->theGrid[row][col]->setPotionAtk(5);
      curLevel->replaceWithBlank(row, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses BA.";
    }
    else if(curLevel->theGrid[row][col+1]->getType() == ObjectType::WD)
    {
      curLevel->theGrid[row][col]->setPotionDef(-5);
      curLevel->replaceWithBlank(row, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses WD.";
    }
    else if(curLevel->theGrid[row][col+1]->getType() == ObjectType::BD)
    {
      curLevel->theGrid[row][col]->setPotionDef(5);
      curLevel->replaceWithBlank(row, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses BD.";
    }
    else if(curLevel->theGrid[row][col+1]->getType() == ObjectType::RH)
    {
      if(curLevel->theGrid[row][col]->getType() == ObjectType::Drow)
      curLevel->theGrid[row][col]->setHP(15);
      else
      curLevel->theGrid[row][col]->setHP(10);
      curLevel->replaceWithBlank(row, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses RH.";
    }
    else if(curLevel->theGrid[row][col+1]->getType() == ObjectType::PH)
    {
      if(curLevel->theGrid[row][col]->getType() == ObjectType::Drow)
      curLevel->theGrid[row][col]->setHP(-15);
      else
      curLevel->theGrid[row][col]->setHP(-10);
      curLevel->replaceWithBlank(row, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses PH.";
    }
  } else if (direction == "se"){
    if(curLevel->theGrid[row+1][col+1]->getType() == ObjectType::WA)
    {
      curLevel->theGrid[row][col]->setPotionAtk(-5);
      curLevel->replaceWithBlank(row+1, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses WA.";
    }
    else if(curLevel->theGrid[row+1][col+1]->getType() == ObjectType::BA)
    {
      curLevel->theGrid[row][col]->setPotionAtk(5);
      curLevel->replaceWithBlank(row+1, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses BA.";
    }
    else if(curLevel->theGrid[row+1][col+1]->getType() == ObjectType::WD)
    {
      curLevel->theGrid[row][col]->setPotionDef(-5);
      curLevel->replaceWithBlank(row+1, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses WD.";
    }
    else if(curLevel->theGrid[row+1][col+1]->getType() == ObjectType::BD)
    {
      curLevel->theGrid[row][col]->setPotionDef(5);
      curLevel->replaceWithBlank(row+1, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses BD.";
    }
    else if(curLevel->theGrid[row+1][col+1]->getType() == ObjectType::RH)
    {
      if(curLevel->theGrid[row][col]->getType() == ObjectType::Drow)
      curLevel->theGrid[row][col]->setHP(15);
      else
      curLevel->theGrid[row][col]->setHP(10);
      curLevel->replaceWithBlank(row+1, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses RH.";
    }
    else if(curLevel->theGrid[row+1][col+1]->getType() == ObjectType::PH)
    {
      if(curLevel->theGrid[row][col]->getType() == ObjectType::Drow)
      curLevel->theGrid[row][col]->setHP(-15);
      else
      curLevel->theGrid[row][col]->setHP(-10);
      curLevel->replaceWithBlank(row+1, col+1);
      movePlayer(direction, noFile, race);
      action += "PC uses PH.";
    }
  } else if (direction == "so"){

    if(curLevel->theGrid[row+1][col]->getType() == ObjectType::WA)
    {
      curLevel->theGrid[row][col]->setPotionAtk(-5);
      curLevel->replaceWithBlank(row+1, col);
      movePlayer(direction, noFile, race);
      action += "PC uses WA.";
    }
    else if(curLevel->theGrid[row+1][col]->getType() == ObjectType::BA)
    {
      curLevel->theGrid[row][col]->setPotionAtk(5);
      curLevel->replaceWithBlank(row+1, col);
      movePlayer(direction, noFile, race);
      action += "PC uses BA.";
    }
    else if(curLevel->theGrid[row+1][col]->getType() == ObjectType::WD)
    {
      curLevel->theGrid[row][col]->setPotionDef(-5);
      curLevel->replaceWithBlank(row+1, col);
      movePlayer(direction, noFile, race);
      action += "PC uses WD.";
    }
    else if(curLevel->theGrid[row+1][col]->getType() == ObjectType::BD)
    {
      curLevel->theGrid[row][col]->setPotionDef(5);
      curLevel->replaceWithBlank(row+1, col);
      movePlayer(direction, noFile, race);
      action += "PC uses BD.";
    }
    else if(curLevel->theGrid[row+1][col]->getType() == ObjectType::RH)
    {
      if(curLevel->theGrid[row][col]->getType() == ObjectType::Drow)
      curLevel->theGrid[row][col]->setHP(15);
      else
      curLevel->theGrid[row][col]->setHP(10);
      curLevel->replaceWithBlank(row+1, col);
      movePlayer(direction, noFile, race);
      action += "PC uses RH.";
    }
    else if(curLevel->theGrid[row+1][col]->getType() == ObjectType::PH)
    {
      if(curLevel->theGrid[row][col]->getType() == ObjectType::Drow)
      curLevel->theGrid[row][col]->setHP(-15);
      else
      curLevel->theGrid[row][col]->setHP(-10);
      curLevel->replaceWithBlank(row+1, col);
      movePlayer(direction, noFile, race);
      action += "PC uses PH.";
    }
  } else if (direction == "sw"){
    if(curLevel->theGrid[row+1][col-1]->getType() == ObjectType::WA)
    {
      curLevel->theGrid[row][col]->setPotionAtk(-5);
      curLevel->replaceWithBlank(row+1, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses WA.";
    }
    else if(curLevel->theGrid[row+1][col-1]->getType() == ObjectType::BA)
    {
      curLevel->theGrid[row][col]->setPotionAtk(5);
      curLevel->replaceWithBlank(row+1, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses BA.";
    }
    else if(curLevel->theGrid[row+1][col-1]->getType() == ObjectType::WD)
    {
      curLevel->theGrid[row][col]->setPotionDef(-5);
      curLevel->replaceWithBlank(row+1, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses WD.";
    }
    else if(curLevel->theGrid[row+1][col-1]->getType() == ObjectType::BD)
    {
      curLevel->theGrid[row][col]->setPotionDef(5);
      curLevel->replaceWithBlank(row+1, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses BD.";
    }
    else if(curLevel->theGrid[row+1][col-1]->getType() == ObjectType::RH)
    {
      if(curLevel->theGrid[row][col]->getType() == ObjectType::Drow)
      curLevel->theGrid[row][col]->setHP(15);
      else
      curLevel->theGrid[row][col]->setHP(10);
      curLevel->replaceWithBlank(row+1, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses RH.";
    }
    else if(curLevel->theGrid[row+1][col-1]->getType() == ObjectType::PH)
    {
      if(curLevel->theGrid[row][col]->getType() == ObjectType::Drow)
      curLevel->theGrid[row][col]->setHP(-15);
      else
      curLevel->theGrid[row][col]->setHP(-10);
      curLevel->replaceWithBlank(row+1, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses PH.";
    }
  } else if (direction == "we"){
    if(curLevel->theGrid[row][col-1]->getType() == ObjectType::WA)
    {
      curLevel->theGrid[row][col]->setPotionAtk(-5);
      curLevel->replaceWithBlank(row, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses WA.";
    }
    else if(curLevel->theGrid[row][col-1]->getType() == ObjectType::BA)
    {
      curLevel->theGrid[row][col]->setPotionAtk(5);
      curLevel->replaceWithBlank(row, col-1);
      //curLevel->replaceWithBlank(row, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses BA.";
    }
    else if(curLevel->theGrid[row][col-1]->getType() == ObjectType::WD)
    {
      curLevel->theGrid[row][col]->setPotionDef(-5);
      curLevel->replaceWithBlank(row, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses WD.";
    }
    else if(curLevel->theGrid[row][col-1]->getType() == ObjectType::BD)
    {
      curLevel->theGrid[row][col]->setPotionDef(5);
      curLevel->replaceWithBlank(row, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses BD.";
    }
    else if(curLevel->theGrid[row][col-1]->getType() == ObjectType::RH)
    {
      if(curLevel->theGrid[row][col]->getType() == ObjectType::Drow)
      curLevel->theGrid[row][col]->setHP(15);
      else
      curLevel->theGrid[row][col]->setHP(10);
      curLevel->replaceWithBlank(row, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses RH.";
    }
    else if(curLevel->theGrid[row][col-1]->getType() == ObjectType::PH)
    {
      if(curLevel->theGrid[row][col]->getType() == ObjectType::Drow)
      curLevel->theGrid[row][col]->setHP(-15);
      else
      curLevel->theGrid[row][col]->setHP(-10);
      curLevel->replaceWithBlank(row, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses PH.";
    }
  } else if (direction == "nw"){
    if(curLevel->theGrid[row-1][col-1]->getType() == ObjectType::WA)
    {
      curLevel->theGrid[row][col]->setPotionAtk(-5);
      curLevel->replaceWithBlank(row-1, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses WA.";
    }
    else if(curLevel->theGrid[row-1][col-1]->getType() == ObjectType::BA)
    {
      curLevel->theGrid[row][col]->setPotionAtk(5);
      curLevel->replaceWithBlank(row-1, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses BA.";
    }
    else if(curLevel->theGrid[row-1][col-1]->getType() == ObjectType::WD)
    {
      curLevel->theGrid[row][col]->setPotionDef(-5);
      curLevel->replaceWithBlank(row-1, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses WD.";
    }
    else if(curLevel->theGrid[row-1][col-1]->getType() == ObjectType::BD)
    {
      curLevel->theGrid[row][col]->setPotionDef(5);
      curLevel->replaceWithBlank(row-1, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses BD.";
    }
    else if(curLevel->theGrid[row-1][col-1]->getType() == ObjectType::RH)
    {
      if(curLevel->theGrid[row][col]->getType() == ObjectType::Drow)
      curLevel->theGrid[row][col]->setHP(15);
      else
      curLevel->theGrid[row][col]->setHP(10);
      curLevel->replaceWithBlank(row-1, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses RH.";
    }
    else if(curLevel->theGrid[row-1][col-1]->getType() == ObjectType::PH)
    {
      if(curLevel->theGrid[row][col]->getType() == ObjectType::Drow)
      curLevel->theGrid[row][col]->setHP(-15);
      else
      curLevel->theGrid[row][col]->setHP(-10);
      curLevel->replaceWithBlank(row-1, col-1);
      movePlayer(direction, noFile, race);
      action += "PC uses PH.";
    }
  }
}


void Game::moveEnemies(){
  if(this->f) return; // do no move any enemies
  for(Enemy *e : curLevel->enemies){
    if(e->isAggroed()||e->getType()==ObjectType::Dragon) continue;
    //generate random direction
    int deltaX, deltaY, dirMap;
    int newRow, newCol;
    do {
      dirMap = rand() % 8; // map 0-7 to the 8 directions
      switch(dirMap){
        case 0 : deltaX=0; deltaY=1; break;     // N
        case 1 : deltaX=1; deltaY=1; break;     // NE
        case 2 : deltaX=1; deltaY=0; break;     // E
        case 3 : deltaX=1; deltaY=-1; break;    // SE
        case 4 : deltaX=0; deltaY=-1; break;    // S
        case 5 : deltaX=-1; deltaY=-1; break;   // SW
        case 6 : deltaX=-1; deltaY=0; break;    // W
        case 7 : deltaX=-1; deltaY=1; break;    // NW
      }
      newRow = e->getrow()+deltaX;
      newCol = e->getcol()+deltaY;
    } while(!curLevel->isEmpty(newRow, newCol));
    curLevel->moveEnemy(e, newRow, newCol);
  }
}


bool Game::playerAttack(string direction){
  bool attacked = false;
  int row = p->getrow();
  int col = p->getcol();
  int targetR, targetC;
  if (direction == "no"){
    //curLevel->player
    targetR = row-1;
    targetC = col;
  } else if (direction == "ne"){
    // ObjectType type = theGrid[row-1][col+1]->gettype();
    targetR = row-1;
    targetC = col+1;
  } else if (direction == "ea"){
    // ObjectType type = theGrid[row][col+1]->gettype();
    //add cases
    targetR = row;
    targetC = col+1;
  } else if (direction == "se"){
    // ObjectType type = theGrid[row+1][col+1]->gettype();
    //add cases
    targetR = row+1;
    targetC = col+1;
  } else if (direction == "so"){
    // ObjectType type = theGrid[row+1][col]->gettype();
    //add cases
    targetR = row+1;
    targetC = col;
  } else if (direction == "sw"){
    // ObjectType type = theGrid[row+1][col-1]->gettype();
    //add cases
    targetR = row+1;
    targetC = col-1;
  } else if (direction == "we"){
    // ObjectType type = theGrid[row][col-1]->gettype();
    //add cases
    targetR = row;
    targetC = col-1;
  } else if (direction == "nw"){
    // ObjectType type = theGrid[row-1][col-1]->gettype();
    //add cases
    targetR = row-1;
    targetC = col-1;
  }
  if(curLevel->isEnemy(targetR, targetC)){
    attacked = true;
    Enemy *temp = static_cast<Enemy *>(curLevel->theGrid[targetR][targetC]);
    ObjectType type = temp->getType();
    int hpBefore = temp->getStats().hp;
    int hpAfter = curLevel->playerAttack(*p, targetR, targetC);
    int damage = hpBefore-hpAfter;
    //action
    if(type == ObjectType::Dragon){
      action += "PC deals " + to_string(damage) + " damage to D (" + to_string(hpAfter) + " HP).";
    } else if(type == ObjectType::Dwarf){
      action += "PC deals " + to_string(damage) + " damage to W (" + to_string(hpAfter) + " HP).";
    } else if(type == ObjectType::Elf){
      action += "PC deals " + to_string(damage) + " damage to E (" + to_string(hpAfter) + " HP).";
    } else if(type == ObjectType::Human){
      action += "PC deals " + to_string(damage) + " damage to H (" + to_string(hpAfter) + " HP).";
      if(hpAfter<=0) gold+=4;
    } else if(type == ObjectType::Halfling){
      action += "PC deals " + to_string(damage) + " damage to L (" + to_string(hpAfter) + " HP).";
    } else if(type == ObjectType::Merchant){
      action += "PC deals " + to_string(damage) + " damage to M (" + to_string(hpAfter) + " HP).";
      merchantHostile = true;
      if(hpAfter<=0) gold+=4;
    } else if(type == ObjectType::Orcs){
      action += "PC deals " + to_string(damage) + " damage to O (" + to_string(hpAfter) + " HP).";
    }
    if(hpAfter<=0&&type!=ObjectType::Dragon&&type!=ObjectType::Human&&type!=ObjectType::Merchant){
        srand(time(nullptr));
        if(rand()%2) gold+=2;
        else gold+=1;
    }
  }
  return attacked;
}
bool Game::enemiesAttack(){
  bool attacked = false;
  for(Enemy *e : curLevel->enemies){
    if(e->isAggroed()){
      if(e->getType()==ObjectType::Merchant){
        if(merchantHostile){
          p->getAttacked(*e);
          action+= " " + e->getAction();
        }
      } else {
        p->getAttacked(*e);
        action+= " " + e->getAction();
      }
      attacked = true;
    }
  }
  return attacked;
}
  bool Game::gameOver() {
    if(level>5 || p->getStats().hp<=0){
        if(p->getType()==ObjectType::Shade) gold += gold/2;
        return true;
    }
    return false;
  }
  int Game::getGold(){
    return gold;
  }

  void Game::toggleEnemyMovement() {
    if(f) {f=false;}
    else {f=true;}
  }

std::string Game::getAction() { return action; }
void Game::clearAction(){ action = ""; }
