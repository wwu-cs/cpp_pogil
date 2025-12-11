#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ofstream fout;
  fout.open("studentInfo.txt", ofstream::app);

  string firstName, lastName, studentID;

  cout << "Enter first name: ";
  cin >> firstName;

  cout << "Enter last name: ";
  cin >> lastName;

  cout << "Enter student ID: ";
  cin >> studentID;

  fout << "Name: " << firstName << " " << lastName << endl;
  fout << "Student ID: " << studentID << endl;
  fout << endl;

  fout.close();

  cout << "Done! Data is saved in: studentInfo.txt" << endl;
}