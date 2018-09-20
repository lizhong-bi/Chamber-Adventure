#ifndef CHAMBER_H
#define CHAMBER_H
//chamber is a rectangular area in the floor
class chamber {
  int start_x; //upper bound for x-coordinate
  int end_x;   //lower bound for x-coordinate
  int start_y; //upper bound for y-coordinate
  int end_y;   //lower bound for y-coordinate
public:
  int getstart_x();
  int getend_x();
  int getstart_y();
  int getend_y();
  chamber(int x1, int x2, int y1, int y2);
};
#endif
