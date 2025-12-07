#include <iostream>
using namespace std;

class Account {
protected:
    float balance;
public:
    Account() {
        balance = 0;
    }
};

class SavingsAccount : protected Account {
public:
    void deposit(float amount) {
        balance += amount;
    }

    void withdraw(float amount) {
        if(amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient Balance!\n";
    }

    void showBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    SavingsAccount s;
    s.deposit(1000);
    s.withdraw(300);
    s.showBalance();
    return 0;
}
