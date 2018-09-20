#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(){}

TextDisplay::TextDisplay(Game *g): g{g}{
  /*
  for (int i = 0; i < 25; ++i) {
    vector<char> v;
    for (int j = 0; j < 79; ++j){
      ObjectType s;
      s = g.curLevel.theGrid[i][j]->getType();
      if (s == ObjectType::wall) {
        v.push_back('|');
      } else if ( s == ObjectType::door) {
        v.push_back('+');
      }  else if ( s == ObjectType::horizontalwall) {
        v.push_back('-');
      } else if (s == ObjectType::passage) {
        v.push_back('#');
      } else if (s == ObjectType::blank) {
        v.push_back('.');
      } else if (s == ObjectType::emptytile) {
        v.push_back(' ');
      }
    }
    theDisplay.push_back(v);
  } */
}

TextDisplay::~TextDisplay(){}


ostream &operator<<(ostream &out, const TextDisplay &td){
  for (int i = 0; i < 25; ++i) {
    for (int j = 0; j < 79; ++j){
      ObjectType s;
      floor *level = td.g->curLevel;
      s = level->theGrid[i][j]->getType();
      if (s == ObjectType::wall) {
        out << '|';
      } else if ( s == ObjectType::door) {
        out << '+';
      } else if ( s == ObjectType::horizontalwall) {
        out << '-';
      } else if (s == ObjectType::passage) {
        out << '#';
      } else if (s == ObjectType::blank) {
        out << '.';
      } else if (s == ObjectType::emptytile) {
        out << ' ';
      } else if (s == ObjectType::Dragon) {
        out << 'D';
      } else if (s == ObjectType::Dwarf) {
        out << 'W';
      } else if (s == ObjectType::Elf) {
        out << 'E';
      } else if (s == ObjectType::Halfling){
        out << 'L';
      } else if (s == ObjectType::Human){
        out << 'H';
      } else if (s == ObjectType::Merchant){
        out << 'M';
      } else if (s == ObjectType::Orcs){
        out << 'O';
      } else if (s==ObjectType::Shade||s==ObjectType::Vampire||s==ObjectType::Drow||s==ObjectType::Troll||s==ObjectType::Goblin) {
        out << '@';
      } else if (s == ObjectType::RH||s == ObjectType::BA||s == ObjectType::BD||s == ObjectType::PH||s == ObjectType::WA||s == ObjectType::WD) {
        out << 'P';
      } else if (s == ObjectType::Gold){
        out << 'G';
      } else if (s == ObjectType::stairs){
        out << '\\';
      }/*
      else {
        out << '4';
      }*/
    }
    out << endl;
  }
  std::string race;
    if(td.g->p->getType() == ObjectType::Shade) race = "Shade";
        else if(td.g->p->getType() == ObjectType::Drow) race = "Drow";
        else if(td.g->p->getType() == ObjectType::Vampire) race = "Vampire";
        else if(td.g->p->getType() == ObjectType::Troll) race = "Troll";
        else if(td.g->p->getType() == ObjectType::Goblin) race = "Goblin";
    out << "Race : " << race << "  Gold : " << td.g->gold << setw(30) << "Floor "<<td.g->level+1 << endl;
    out << "HP : " << (td.g->p->getStats()).hp  << endl;
    if(race == "Drow")
    {
        out << "Atk : " << ((td.g->p->getStats()).atk + (1.5 * (td.g->p->getStats()).potionAtk)) << endl;
        out << "Def : " << ((td.g->p->getStats()).def + (1.5 * (td.g->p->getStats()).potionDef))<< endl;
    }
    else
    {
        out << "Atk : " << ((td.g->p->getStats()).atk + (td.g->p->getStats()).potionAtk) << endl;
        out << "Def : " << ((td.g->p->getStats()).def + (td.g->p->getStats()).potionDef) << endl;
    }
    out << "Action : " << td.g->getAction() << endl;
  return out;
}
