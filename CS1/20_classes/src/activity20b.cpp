#include <iostream>

using namespace std;

class Rectangle {
public:
  int x; // (x,y) coords of bottom left corner
  int y;
  int width; // width (dx) and height (dy)
  int height;
  int getArea();
  int getPerimeter();
  void move(int dx, int dy);
  void draw();
};

int main() {

  /* Data for multiple rectangles */
  const int MAX_RECTANGLES = 100;
  Rectangle myRects[MAX_RECTANGLES];

  /* create a rectangle at point (1,1) with width 2 and height 3 */
  myRects[0].x = 1;
  myRects[0].y = 1;
  myRects[0].width = 2;
  myRects[0].height = 3;

  /* move this rectangle up 2 and over 1 */
  myRects[0].move(1, 2);

  /* display its area and perimeter */
  cout << "Area: " << myRects[0].getArea()
       << ", Perimeter: " << myRects[0].getPerimeter() << endl;

  /* "draw" the rectangle */
  myRects[0].draw();

  return 0;
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
