#ifndef GAME_H
#define GAME_H
#include "floor.h"
#include "playerCharacter.h"
#include <fstream>
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "gold.h"
#include <string>


class Game {
public:
  std::vector <floor *> flrs;
/*  floor *level1;
  floor *level2;
  floor *level3;
  floor *level4;
  floor *level5;*/
  floor *curLevel;  // points to a current level
  int level;        // current level number
  Player *p;        // player
  bool f = false;   // if true, pause all enemy movement
  bool merchantHostile = false;
  std::string action;
  int gold = 0;
  int newGold = 0;

  Game();
  Game(std::string race);                    // starts the game with empty layout, spawns everything
  Game(std::string race, std::ifstream& file);    // starts the game based on a layout, spawns player
  ~Game();
  bool gameOver();  // check if game is over
  int getGold();
  void spawnPlayer(std::string race); // spawns player with specific race
  void spawnEnemies();         // spawns enemies (only use if using default layout)
  void spawnItems();           // spawns items (only use if using default layout)
  void spawnStair();
  void movePlayer(std::string dir, bool noFile, std::string race);
  void usePotion(std::string dir, bool noFile, std::string race);
  void moveEnemies();           //randomly move all enemies as long as "f" is not true, and
  void toggleEnemyMovement();   //toggles f
  void nextlevel(bool noFile, std::string race);
  bool playerAttack(std::string dir);//player attacks a direction
  bool enemiesAttack();         //find enemies for which "aggro" is true, and let them attack players
  std::string getAction();      //get action for the current turn
  void clearAction();           //clears action string, only use at end of turn
};

#endif
