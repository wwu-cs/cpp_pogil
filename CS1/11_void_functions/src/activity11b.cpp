#include <iomanip>
#include <iostream>

using namespace std;

void printArea(double radius) {
  double area = 3.14159 * pow(radius,2);
  cout << fixed << setprecision(2);
  cout << "The area of a circle with radius "
       << radius << " is " << area << endl;
}

int main() {
  // Your code goes here
}