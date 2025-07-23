#include <iostream>
using namespace std;

class BankAccount
{
    int acc;
    string name;
    float balance;

public:
    void input(int a, string n, float b)
    {
        acc = a;
        name = n;
        balance = b;
    }

    void deposit(float amount)
    {
        balance += amount;
        cout << "Deposited Balance: " << amount << endl;
    }

    void withdraw(float amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn Balance: " << amount << endl;
        }
        else
        {
            cout << "Not enough balance" << endl;
        }
    }

    void display()
    {
        cout << "Account No: " << acc << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount sami;
    sami.input(46634, "Sami", 500);
    sami.display();
    sami.deposit(500);
    sami.withdraw(300);
    sami.display();
}
