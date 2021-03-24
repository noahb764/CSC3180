#ifndef CLOSESTPOINT_H
#define CLOSESTPOINT_H
#include "closestPoint.h"
using namespace std;

class closestPoint
{
 public:

  // Default constructor
  closestPoint()
  {
     x = 0;
     y = 0;
  }
  
  //Constructor
  closestPoint(double new_x, double new_y)
  {
    x = new_x;
    y = new_y;
  }

  
  // Accessors
  double getX()
  {
    return x;
  }
  
  double getY()
  {
    return y;
  }

  //Mutators
  void setX(double new_x)
  {
    x = new_x;
  }
  
  void setY(double new_y)
  {
    y = new_y;
  }
  
 private:
  double x;
  double y;

};
#endif
