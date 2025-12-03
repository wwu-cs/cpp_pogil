#include <iostream>

using namespace std;

int sum(int a, int b = 0, int c = 0, int d = 0);

int main() {
  cout << "Test One: " << sum(1, 2, 3, 4) << endl;
  cout << "Test Two: " << sum(1, 2, 3) << endl;
  cout << "Test Three: " << sum(1, 2) << endl;
}