#include <iostream>

using namespace std;

int main() {
  int numOne = 1892;
  int numTwo = 1973;
  int numThree = 2008;
  int *numArray[3] = {&numOne, &numTwo, &numThree};
  int *p;

  p = &numOne;
  cout << "Number: " << *p << endl;
  p = &numTwo;
  cout << "Number: " << *p << endl;
  p = &numThree;
  cout << "Number: " << *p << endl;
}