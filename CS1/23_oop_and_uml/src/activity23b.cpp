#include <iostream>
#include <math.h>

using namespace std;

// class for a Point
class Point {
public:
  Point(double x, double y) {
    this->xPos = x;
    this->yPos = y;
  };
  void setX(double x) { this->xPos = x; }
  void setY(double y) { this->yPos = y; }
  double getX() { return this->xPos; }
  double getY() { return this->yPos; }

private:
  double xPos;
  double yPos;
};

// class for a Circle

int main() {

  // define a unit circle
  Circle unit(1);

  // move it to the point (1,1)
  unit.setX(1);
  unit.setY(1);

  // print out its information
  cout << "Location: (" << unit.getX() << "," << unit.getY() << ")" << endl;
  cout << "Area: " << unit.area() << " square units" << endl;
  cout << "Circumference: " << unit.circumference() << " units" << endl;
}