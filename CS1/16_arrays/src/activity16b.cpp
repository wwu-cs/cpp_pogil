#include <iostream>

using namespace std;

int main() {
  int myTable[10][10];
  int v = 1;
  for (int row = 0; row < 10; ++row) {
    for (int col = 0; col < 10; ++col) {
      myTable[row][col] = v++;
    }
  }
}