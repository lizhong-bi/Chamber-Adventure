#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
/*
#include "passage.h"
#include "door.h"
#include "blank.h"
#include "wall.h"
#include "object.h"
#include "empty.h"
#include "objecttype.h"
#include "floor.h"
*/
#include "game.h"
#include "textdisplay.h"
#include <string>
#include <vector>
using namespace std;

string race;

string enterRace(){
    string in;
    cout << "Enter your race(s, d, v, t, g) or 'q' to quit: \n";
    cin >> in;
    while (!(in=="s"||in=="d"||in=="v"||in=="t"||in=="g"||in=="q")) {
    cout << "Enter your race(s, d, v, t, g) or 'q' to quit: \n";
    cin >> in;
  }
    /*
	if(in == "s") race = "Shade";
        else if(in == "d") race = "Drow";
        else if(in == "v") race = "Vampire";
        else if(in == "t") race = "Troll";
        else if(in == "g") race = "Goblin";
        */
    return in;
}

int main(int argc, char const *argv[]) {
  //vector <vector <Object * >> theGrid;
  bool noFile = false;
  Game *g;
  TextDisplay t;

  ifstream file;
  string in;
  string playerRace;
  // ask for race and starts the game, or quit
  playerRace = enterRace();
  if(playerRace=="q") exit(0);
  else if(argc==1){
    noFile = true;
    g = new Game(playerRace);
  }
  else {
    file.open(argv[1]);
    g = new Game(playerRace, file);
  }
  file.close();
  t = TextDisplay(g);
  cout << t;
  g->clearAction();
  // game loop starts here
  while(cin >> in){
    //special commands that doesn't count as a turn
    if(in=="f"){ //stop enemy movement
        g->toggleEnemyMovement();
        continue;
    }

    // handle commands
    if(in=="q") break;
    else if(in=="no" || in=="ne" || in=="ea" || in=="se" || in== "so" || in=="sw" || in=="we" || in=="nw"){
      g->movePlayer(in,noFile,playerRace);
    }
    else if(in=="u"){
      cin >> in;
      g->usePotion(in, noFile,playerRace);
    }
    else if(in=="a"){
      cin >> in;
      g->playerAttack(in);
    }
    else if(in=="r"){
      // ask for race and restarts the game, or quit
      delete g;
      playerRace = enterRace();
      if(playerRace=="q") break;
      else if(argc==1){
        noFile = true;
        g = new Game(playerRace);
      }
      else {
        file.open(argv[1]);
        g = new Game(playerRace, file);
      }
      file.close();
      t = TextDisplay(g);
      cout << t;
      g->clearAction();
      continue;
    }
    else{
      continue; // not a player action, don't
    }

    // do all the work that need to be done in a turn, like enemy movement, enemy attack, etc.
    g->moveEnemies();
    g->enemiesAttack();
    // output the textdisplay
    cout << t;
    /*
    cout << "Race : " << race << "  Gold : (amount you have)" << setw(30) << "Floor (current floor)" << endl;
    cout << "HP : " << (g->p->getStats()).hp  << endl;
    cout << "Atk : " << ((g->p->getStats()).atk + (g->p->getStats()).potionAtk) << endl;
    cout << "Def : " << ((g->p->getStats()).def + (g->p->getStats()).potionDef)<< endl;
    cout << "Action : current action" << endl;
    */
    g->clearAction();
    if(g->gameOver()){ // check if game is over
      cout << "Game Over. Your score is: " << std::to_string(g->getGold()) << endl;;
      delete g;
      g=nullptr;
        // ask for race and restarts the game, or quit
      playerRace = enterRace();
      if(playerRace=="q") break;
      else if(argc==1){
        noFile = true;
        g = new Game(playerRace);
      }
      else {
        file.open(argv[1]);
        g = new Game(playerRace, file);
      }
      file.close();
      t = TextDisplay(g);
      cout << t;
      g->clearAction();
    }
  }
  delete g;
  exit(0);
}
