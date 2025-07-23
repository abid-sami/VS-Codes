//Write a C++ program to implement a class called BankAccount that has private member variables for account number and balance. Include member functions to deposit and withdraw money from the account. 
#include<iostream>
using namespace std;
class BankAccount{
    float balance=0, deposit, withdraw;
    int account;
public:
    void input(){
    cin>>account>>deposit>>withdraw;
    }
    void cal(){
        balance+=deposit-withdraw;
    }
    void display(){
        cout<<"Account No: "<<account<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

};
int main()
{
    BankAccount b;
    b.input();
    b.cal();
    b.display();

}



