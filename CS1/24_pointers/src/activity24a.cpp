#include <iostream>

using namespace std;

int main() {
  int myArray[] = {40, 30, 20, 10};
  int *p = myArray;

  cout << "Value of p: " << p << endl;
  cout << "Value of *p: " << *p << endl;
  cout << "Value of myArray: ";
  for (int i = 0; i < 3; i++) {
    cout << myArray[i] << ",";
  }
  cout << myArray[3] << endl;
}