#include <iostream>

using namespace std;

/* Functions to use with rectangles */
int getArea(int length, int width);
int getPerimeter(int length, int width);
void move(int &x, int &y, int dx, int dy);
void draw(int x, int y, int wd, int ht);

int main() {

  /* Data for multiple rectangles */
  const int MAX_RECTANGLES = 100;
  int rectX[MAX_RECTANGLES];
  int rectY[MAX_RECTANGLES];
  int rectWidth[MAX_RECTANGLES];
  int rectHeight[MAX_RECTANGLES];

  /* create a rectangle at point (1,1) with width 2 and height 3 */
  rectX[0] = 1;
  rectY[0] = 1;
  rectWidth[0] = 2;
  rectHeight[0] = 3;

  /* move this rectangle up 2 and over 1 */
  move(rectX[0], rectY[0], 1, 2);

  /* display its area and perimeter */
  cout << "Area: " << getArea(rectWidth[0], rectHeight[0])
       << ", Perimeter: " << getPerimeter(rectWidth[0], rectHeight[0]) << endl;

  /* "draw" the rectangle */
  draw(rectX[0], rectY[0], rectWidth[0], rectHeight[0]);

  return 0;
}

int getArea(int width, int height) { return width * height; }

int getPerimeter(int width, int height) { return 2 * width + 2 * height; }

void move(int &x, int &y, int dx, int dy) {
  x += dx;
  y += dy;
}

void draw(int x, int y, int wd, int ht) {
  cout << "Just drew a nice " << wd << " by " << ht
       << " rectangle at position (" << x << "," << y << ")!" << endl;
}
