#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class TempConvert {
public:
  double convertTemp(double temp, string inScale, string outScale) {
    inScale = normalizeScale(inScale);
    outScale = normalizeScale(outScale);
    if (inScale == outScale) {
      return temp;
    } else if (inScale == "C" && outScale == "F") {
      return cToF(temp);
    } else if (inScale == "F" && outScale == "C") {
      return fToC(temp);
    } else if (inScale == "K" && outScale == "C") {
      return kToC(temp);
    } else if (inScale == "K" && outScale == "F") {
      return cToF(kToC(temp));
    } else
      throw invalid_argument("Conversion Not Implemented");
  }

private:
  double cToF(double c) {
    if (c < -273.15)
      throw domain_error("Invalid Temp");
    return 32 + c * 9 / 5;
  }
  double fToC(double f) {
    if (f < -459.67)
      throw domain_error("Invalid Temp");
    return (f - 32) * 5 / 9;
  }
  double kToC(double k) {
    if (k < 0)
      throw domain_error("Invalid Temp");
    return k + 273.15;
  }
  string normalizeScale(string s) {
    for_each(s.begin(), s.end(), [](char &c) { c = ::tolower(c); });
    if (s == "c" || s.substr(0, 4) == "cels") {
      return "C";
    }
    if (s == "f" || s.substr(0, 4) == "fahr") {
      return "F";
    }
    if (s == "k" || s.substr(0, 4) == "kelv") {
      return "K";
    }
    throw domain_error("Invalid Scale");
  }
};

int main() {
  // variables
  TempConvert tc;

  double t[6] = {20, -30, 170, 25, -12, 14};
  string u[6] = {"C", "C", "K", "F", "K", "C"};
  double newT[6];

  for (int i = 0; i < 6; i++) {
    try {
      newT[i] = tc.convertTemp(t[i], u[i], "F");
    } catch (logic_error &except) {
      newT[i] = NAN;
    }
  }

  for (int i = 0; i < 6; i++) {
    cout << t[i] << u[i] << " = " << newT[i] << "F" << endl;
  }
}