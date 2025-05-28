/*Create a BankAccount class with a balance attribute and a withdraw function. In the withdraw 
function, throw an exception if the withdrawal amount exceeds the balance, with a message 
like "Insufficient funds." Write a program to create a BankAccount object, deposit some 
money, and try to withdraw an amount greater than the balance to test the exception handling. */

#include<iostream>
using namespace std;

class BankAccount{
    public:
    double balance=0;
   
    void deposit(){
        double amount;
        cout<<"Enter Deposit Amount: "<<endl;
        cin>>amount;
        balance+=amount;
    }
    void withdraw(){
        double amount;
        cout<<"Enter Withdraw Amount: "<<endl;
        cin>>amount;
        if(amount>balance){
            throw "Insufficient funds.";
        }
        balance-=amount;
        cout<<"Withdraw Succesful"<<endl;
        cout<<"New Balance: "<<balance<<endl;
    }
    
};

int main(){
    BankAccount b1; 
    b1.deposit(); 
    try{
        b1.withdraw();
    }
    catch(const char* s){
        cout<<s<<endl;
    }

}

