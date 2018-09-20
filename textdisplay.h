#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include <iomanip>
#include "game.h"

class TextDisplay {//: public Observer {
  std::vector<std::vector<char>> theDisplay;
  
 public:
  Game *g;
  TextDisplay();
  TextDisplay(Game *g);
/*
  void notify(Subject &whoNotified) override;
  SubscriptionType subType() const override;*/

  ~TextDisplay();

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
