#ifndef FLOOR_H
#define FLOOR_H
#include <vector>
#include <fstream>
#include <sstream>
#include "objecttype.h"
#include "object.h"
#include "enemy.h"
#include "passage.h"
#include "door.h"
#include "blank.h"
#include "wall.h"
#include "object.h"
#include "empty.h"
#include "objecttype.h"
#include "dragon.h"
#include "dwarf.h"
#include "elf.h"
#include "halfling.h"
#include "human.h"
#include "merchant.h"
#include "orcs.h"
#include "playerCharacter.h"
#include "ba.h"
#include "bd.h"
#include "ph.h"
#include "rh.h"
#include "wa.h"
#include "wd.h"

class floor{
public:

  std::vector<std::vector<Object *>> theGrid;
  std::vector<Enemy *> enemies;
  Object *curTile = nullptr;
  Player *p;
  Object *stairway;
  //TextDisplay *td;
  // friend class TextDisplay::TextDisplay;
  // friend class Game::Game;


  static const int WIDTH = 79;
  static const int HEIGHT = 25;
  void init(int start, int end, std::ifstream& file, std::string race); //reads in from a file starting at line start
  // and stops at line end, fills up theGrid
  floor();
  ~floor();
  void setPlayer(Player *p, int row, int col);
  void setEnemy(Enemy *p, int row, int col);
  void setItems(Object *p, int row, int col);
  void movePlayer(Player *p, int otherRow, int otherCol);
  int playerAttack(Player &p, int row, int col);
  void moveEnemy(Enemy *e, int newRow, int newCol);
  bool isEmpty(int row, int col); // true if (x,y) is empty
  bool isStairs(int row, int col); // true if (x,y) is stairway to next level
  bool canMove(int row, int col); // true if player can move to (x,y)
  bool isEnemy(int row, int col);
  void replaceWithBlank(int row, int col);
// bool isWon() const; // Call to determine if grid is in a winning state.
// void turnOn(int r, int c);  // Sets cell at row r, col c to On.
// void toggle(int r, int c);  // Switches cell at (r, c) between On and Off.
// friend std::ostream &operator<<(std::ostream &out, const floor &f);

};

#endif

/*
create a chamber object that has the coordinates of chambers maybe
create a vector of chamber objects and spwn stuff in it
floor has to implement move as well
change the constructors for floor objects
*/
