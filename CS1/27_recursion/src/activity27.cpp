#include <iostream>

using namespace std;

int factorial(int n) {
  cout << "n is " << n << endl;
  if (n == 0) {
    return 1; // base case
  } else {
    cout << "need factorial of " << (n - 1) << endl;
    int answer = factorial(n - 1);
    cout << "factorial of " << (n - 1) << " is " << answer << endl;
    return n * answer;
  }
}

int main() {
  cout << "Testing 5!" << endl;
  int ans = factorial(5);
  cout << "5! = " << ans << endl;   
}