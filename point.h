#ifndef POINT_H
#define POINT_H

class point
{

public:

  // Constructor(s)
  point();
  //precondition: default constructor
  point(int xc, int yc);
  //precondition: constructor that takes parameters
    
  // Accessors
  int getXC();
  //precondition: gets the X-coordinate from the constructor
  //postcondition: stores the X-coordinate and processes it
  int getYC();
  //precondition: gets the Y-coordinate from the constructor
  //postcondition: stores the Y-coordinate and processes it
  
  // Mutators
  void setC();
  //precondition: gets both coordinates from the "get functions"
  //postcondition: Processes the coordinates and sets them
  void show();
  //precondition: gets the set values of X and Y from the "setC" function
  //postcondition: Prints the X and Y positions
private:
  // member data
  int x;
  int y;

};
#endif
