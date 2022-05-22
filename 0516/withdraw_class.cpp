#include <iostream>

class Deposit {
  private:
  int balance;
  public:
  Deposit(int init_balance) {
    balance = init_balance;
  }

  int withdraw(int amount) {
    if ( amount > balance ) {
      std::cerr << "Insufficient funds" << std::endl;
    } else {
      balance = balance - amount;
    }
    return balance;
  }
};

int main() {
  Deposit kei = Deposit(100);
  Deposit bill = Deposit(1000);

  //std::cout << "kei  :" << kei.balance << std::endl;
  std::cout << "kei  :" << kei.withdraw(25) << std::endl;
  std::cout << "bill :" << bill.withdraw(25) << std::endl;

  std::cout << "kei  :" << kei.withdraw(25) << std::endl;
  std::cout << "bill :" << bill.withdraw(25) << std::endl;

  std::cout << "kei  :" << kei.withdraw(60) << std::endl;
  std::cout << "bill :" << bill.withdraw(60) << std::endl;
}
