#include <algorithm>
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
    } else if (inScale == "C") {
      return cToF(temp);
    } else {
      return fToC(temp);
    }
  }

private:
  double cToF(double c) { return 32 + c * 9 / 5; }
  double fToC(double f) { return (f - 32) * 5 / 9; }
  string normalizeScale(string s) {
    for_each(s.begin(), s.end(), [](char &c) { c = ::tolower(c); });
    if (s == "c" || s.substr(0, 4) == "cels") {
      return "C";
    }
    if (s == "f" || s.substr(0, 4) == "fahr") {
      return "F";
    }
    return "?";
  }
};

int main() {
  // variables
  double iTemp, oTemp;
  string iUnit, oUnit;
  TempConvert tc;

  // get input temperature and units
  cout << "I am the Temperature Converter." << endl;
  cout << "  Input Temp: ";
  cin >> iTemp;
  cout << "  Input Units: ";
  cin >> iUnit;
  cout << "  Output Units: ";
  cin >> oUnit;
  oTemp = tc.convertTemp(iTemp, iUnit, oUnit);
  cout << endl << "The answer is: " << oTemp << endl;
}