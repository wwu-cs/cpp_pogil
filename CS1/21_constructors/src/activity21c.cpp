#include <iomanip>
#include <iostream>

using namespace std;

class Matrix {
public:
  Matrix();
  Matrix(int);
  Matrix(int, int, int, int);
  void setValues(int, int, int, int);
  void print();
  int getTrace();
  int getDeterminant();
  Matrix operator+(Matrix);

private:
  int a, b, c, d; // Entries in | a b |
                  // matrix     | c d |
};

Matrix::Matrix() {
  a = 1;
  b = 0;
  c = 0;
  d = 1;
}

Matrix::Matrix(int x) {
  a = x;
  b = x;
  c = x;
  d = x;
}

Matrix::Matrix(int a, int b, int c, int d) {
  this->a = a;
  this->b = b;
  this->c = c;
  this->d = d;
}

Matrix Matrix::operator+(Matrix rhs) {
  Matrix Sum;
  Sum.a = a + rhs.a;
  Sum.b = a + rhs.b;
  Sum.c = a + rhs.c;
  Sum.d = a + rhs.d;
  return Sum;
}

int main() {
  Matrix A(2), B(1, 2, 3, 4);
  Matrix C = A + B;
  C.print();
}

void Matrix::setValues(int x, int y, int z, int w) {
  a = x;
  b = y;
  c = z;
  d = w;
}

int Matrix::getTrace() { return a + d; }

int Matrix::getDeterminant() { return a * d - b * c; }

void Matrix::print() {
  cout << "| " << setw(2) << a << " " << setw(2) << b << " |" << endl
       << "| " << setw(2) << c << " " << setw(2) << d << " |" << endl
       << endl;
  ;
}
