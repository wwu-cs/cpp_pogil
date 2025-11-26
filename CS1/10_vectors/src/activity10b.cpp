#include <iostream>
#include <vector>

using namespace std;

int main() {
  // put first 100 powers of two in x
  vector<double> x(100);
  for (int i = 0; i < x.size(); i++) {
    x.at(i) = pow(2, i);
  }

  // sum the elements of y
  int sum = 0;
  for (int i = 0; i < y.size(); i++) {
    sum += y.at(i);
  }
}