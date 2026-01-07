#include <iomanip>
#include <iostream>

using namespace std;

// class for a deposit account
//   at a bank
class Account {
public:
  Account(double balance);
  void deposit(double amount);
  virtual bool withdraw(double amount);
  double getBalance() const { return balance; };

private:
  double balance = 0;
};

// class for a savings account
class Savings : public Account {
public:
  Savings(double balance, double rate);
  void setRate(double rate);
  void newMonth();
  int getWithdrawls() const { return numWithdrawls; };

private:
  double rate;
  int numWithdrawls;
};

void testAccount(Account &toTest) {
  cout << fixed << showpoint << setprecision(2) << "Initial Balance: $"
       << toTest.getBalance() << endl;
  toTest.deposit(50);
  cout << "After $50 Deposit: $" << toTest.getBalance() << endl;
  for (int i = 0; i < 10; i++) {
    if (toTest.withdraw(10)) {
      cout << "Successfully withdrew $10.00" << endl;
    } else {
      cout << "Failed to withdraw $10.00" << endl;
    }
  }
  cout << "Final Balance: $" << toTest.getBalance() << endl;
}

int main() {
  Account checking(100);
  Savings savings(80, 0.01);

  cout << "Checking Test:" << endl << "==============" << endl;
  testAccount(checking);

  cout << endl << "Savings Test:" << endl << "=============" << endl;
  testAccount(savings);
  cout << "-> New Month <-" << endl;
  savings.newMonth();
  testAccount(savings);
}

/**************************************/

Account::Account(double balance) { this->balance = balance; }

void Account::deposit(double amount) { balance += amount; }

bool Account::withdraw(double amount) {
  if (amount <= this->balance) {
    this->balance -= amount;
    return true;
  } else {
    return false;
  }
}

Savings::Savings(double balance, double rate) : Account(balance) {
  this->rate = rate;
  this->numWithdrawls = 0;
}

void Savings::setRate(double rate) { this->rate = rate; }

void Savings::newMonth() {
  this->numWithdrawls = 0;
  this->deposit(this->balance * this->rate);
}