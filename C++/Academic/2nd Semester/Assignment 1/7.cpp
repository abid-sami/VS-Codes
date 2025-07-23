//Write a C++ program that checks whether a given number is prime. 
#include<iostream>
using namespace std;
int main(){
    int i, n, p=1;
    cout<<"Enter Number: ";
    cin>>n;
    if(n<2){
        cout<<"Error";
    }
    else{
        for(i=2; i<=n/2; i++){
            if(n%i==0){
                p=0;
                break;
            }
        }
        if(p==1){
            cout<<"Prime Number"<<endl;
        }
        else{
            cout<<"Not Prime Number"<<endl;
        }
    }

}