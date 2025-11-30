#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int number;
  cout << "Enter a positive integer: ";
  cin >> number;
  int x = 1;
  while (x <= number) {
    if (x % 10 == 0) {
      cout << setw(2) << x << endl;
    } else {
      cout << setw(2) << x << " ";
    }
    x = x + 1;
  }
}