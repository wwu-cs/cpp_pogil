#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> myVec = {25, 12, 73, 19, 42};

  myVec.pop_back();
  myVec.insert(myVec.begin() + 2, 55);
  myVec.erase(myVec.begin() + 1);

  vector<int> myVec = {25, 12, 73, 19, 42};

  myVec.resize(7);
  myVec.at(5) = 31;
  myVec.insert(myVec.end() - 3, 90);
  myVec.push_back(27);
}