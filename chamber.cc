#include "chamber.h"
int chamber::getstart_x() {
  return this->start_x;
}
int chamber::getstart_y() {
  return this->start_y;
}
int chamber::getend_x() {
  return this->end_x;
}
int chamber::getend_y() {
  return this->end_y;
}
chamber::chamber(int x1, int x2, int y1, int y2) {
  this->start_x = x1;
  this->end_x = x2;
  this->start_y = y1;
  this->end_y = y2;
}
/*
we can create following chambers for level 1:
chamber c1 = chamber(3,28,3,6);
chamber c2 = chamber(39,61,3,4);
chamber c3 = chamber(39,69,5,5);
chamber c4 = chamber(39,73,6,6);
chamber c5 = chamber(61,75,7,12);
chamber c6 = chamber(38,49,10,12);
chamber c7 = chamber(65,75,16,18);
chamber c8 = chamber(37,75,19,21);
chamber c9 = chamber(4,24,15,21);
select a chamber randomly and get the bounds and use the random
function to generate coordinates. Use these coordinates to spawn stuff
randomly
*/
