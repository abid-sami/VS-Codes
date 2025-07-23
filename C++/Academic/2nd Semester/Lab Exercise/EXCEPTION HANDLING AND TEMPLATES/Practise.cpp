#include <iostream>
using namespace std;

class BankAccount{
    public:
    double balance=0;

    void deposit(){
        double amount;
        cout<<"Enter Deposit amount: "<<endl;
        cin>>amount;
        balance+=amount;        
    }

    void withdraw(){
        double amount;
        cout<<"Enter Withdraw amount: "<<endl;
        cin>>amount;
        if(balance<amount){
            throw "Insufficient Funds";
        }
        cout<<"Withdraw Successful"<<endl;;
        balance-=amount;
        cout<<"balance: "<<balance<<endl;
    }

};

int main(){
    BankAccount b1;
    b1.deposit();
    try{
        b1.withdraw();
    }
    catch(const char* i){
        cout<<i<<endl;
    }
}