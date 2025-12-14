#include <iostream>
using namespace std;

class Rectangle {
public:
  bool init(int xVal, int yVal, int wVal, int hVal);
  int getArea();
  int getPerimeter();
  void move(int dx, int dy);
  void draw();

private:
  int x; // (x,y) coords of bottom left corner
  int y;
  int width; // width (dx) and height (dy)
  int height;
};

int main() {

  /* Data for multiple rectangles */
  const int MAX_RECTANGLES = 100;
  Rectangle myRects[MAX_RECTANGLES];

  /* create a rectangle at point (1,1) with width 2 and height 3 */
  if (myRects[0].init(1, 1, 2, 3)) {

    /* move this rectangle up 2 and over 1 */
    myRects[0].move(1, 2);

    /* display its area and perimeter */
    cout << "Area: " << myRects[0].getArea()
         << ", Perimeter: " << myRects[0].getPerimeter() << endl;

    /* "draw" the rectangle */
    myRects[0].draw();

  } else {

    cout << "Invalid rectangle specified" << endl;
  }

  return 0;
}

bool Rectangle::init(int xVal, int yVal, int wVal, int hVal) {

  bool success = true;

  // x and y values can be anything
  x = xVal;
  y = yVal;

  // make sure width and height are not negative
  if (wVal > 0) {
    width = wVal;
  } else {
    width = 0;
    success = false;
  }
  if (hVal > 0) {
    height = hVal;
  } else {
    height = 0;
    success = false;
  }

  return success;
}

int Rectangle::getArea() { return width * height; }

int Rectangle::getPerimeter() { return 2 * width + 2 * height; }

void Rectangle::move(int dx, int dy) {
  x += dx;
  y += dy;
}

void Rectangle::draw() {
  cout << "Just drew a nice " << width << " by " << height
       << " rectangle at position (" << x << "," << y << ")!" << endl;
}