#ifndef CLOSESTPOINT_H
#define CLOSESTPOINT_H

class closestPoint
{
 public:

  // Default constructor
  closestPoint();
  
  //Constructor
  closestPoint(double new_x, double new_y);

  
  // Accessors
  double getX();
  double getY();

  //Mutators
  void setX();
  void setY();

 private:
  double x_coord;
  double y_coord;

};
#endif
