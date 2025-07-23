//Bank Account Management System (Account Number, Deposit, Withdraw)
#include<iostream>
using namespace std;
class BankAccount{
    int accountNumber;
    float balance=0,w;
    static int totalAccounts;
public:
   void deposit(){
       cin>>accountNumber;
       totalAccounts+=1;
       cin>>balance;
   }
   void withdraw(){
        cin>>w;
   }
   void displayAccount(){
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Balance: "<<balance-w<<endl;
   }
    static void getTotalAccount(){
         cout<<"Total Accounts: "<<totalAccounts<<endl;
   }

};
int BankAccount::totalAccounts;
  
int main(){
   BankAccount b1;
   b1.deposit();
   b1.withdraw();
   b1.displayAccount();
   BankAccount::getTotalAccount();
}

