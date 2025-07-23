#include <iostream>
using namespace std;

class Account
{
protected:
    string name;
    float bal;
    int no;

public:
    Account(string na, float b, int n)
    {
        name = na;
        bal = b;
        no = n;
    }
    void deposit(float total)
    {
        bal += total;
        cout << "Deposited Balance: " << total << endl;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Account No: " << no << endl;
        cout << "Balance: " << bal << endl;
    }
};

class cur_acct : public Account
{
    float minbal, charge;

public:
    cur_acct(string na, float b, int n, float mb, float c)
        : Account(na, b, n)
    {
        minbal = mb;
        charge = c;
    }
    void withdraw(float total)
    {
        if (bal >= total)
        {
            bal -= total;
            if (bal < minbal)
            {
                bal -= charge;
                cout << "Service Charge Applied: " << charge << endl;
            }
            cout << "Withdrawn Balance: " << total << endl;
        }
        else
        {
            cout << "Not enough Balance" << endl;
        }
    }
};

class sav_acct : public Account
{
    float interest;

public:
    sav_acct(string na, float b, int n, float i)
        : Account(na, b, n)
    {
        interest = i;
    }

    void cinterest()
    {
        float interest_amt = bal * (interest / 100);
        bal += interest_amt;
        cout << "Interest Added: " << interest_amt << endl;
    }
    void withdraw(float total)
    {
        if (bal >= total)
        {
            bal -= total;
            cout << "Withdrawn Balance: " << total << endl;
        }
        else
        {
            cout << "Not enough Balance!" << endl;
        }
    }
};

int main()
{
    cout << "Savings Account....." << endl;
    sav_acct s("Sami", 1000, 464646, 5.0);
    s.display();
    s.cinterest();
    s.withdraw(200);
    s.display();
    cout << "Current Account...." << endl;
    cur_acct c("Ragib", 500, 789456, 300, 50);
    c.display();
    c.withdraw(200);
    c.display();
}
