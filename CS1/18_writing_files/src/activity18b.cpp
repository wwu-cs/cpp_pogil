#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Configuration function
void getSetup(int &rows, int &cols, char &charOne, char &charTwo) {
  ifstream configIn;
  configIn.open("gameBoard.cfg");
  if (configIn.is_open()) {
    configIn >> rows;
    configIn >> cols;
    configIn >> charOne;
    configIn >> charTwo;
    configIn.close();
  } else {
    cout << "Enter Number of Rows: ";
    cin >> rows;
    cout << "Enter Number of Columns: ";
    cin >> cols;
    cout << "Enter Player One Symbol: ";
    cin >> charOne;
    cout << "Enter Player Two Symbol: ";
    cin >> charTwo;
  }
}

// Function to print the checkerboard
void printBoard(int rows, int cols, char charOne, char charTwo) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if ((i + j) % 2 == 0) {
        cout << charOne;
      } else {
        cout << charTwo;
      }
    }
    cout << endl;
  }
}

int main() {
  int rows, cols;
  char charOne, charTwo;

  getSetup(rows, cols, charOne, charTwo);
  printBoard(rows, cols, charOne, charTwo);
}