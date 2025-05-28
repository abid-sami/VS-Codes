#include<iostream>
using namespace std;

int main(){
    int a,b, rem;
    cin>>a>>b;
    try{
        if(b!=0){
            rem=a%b;
        }
        else{
            throw 0;
        }
        cout<<"Remainder "<<rem<<endl;
    }
    catch(int e){
        cout<<"Can't be divided by "<<e<<endl;
    }
    cout<<"Hello World"<<endl;
}