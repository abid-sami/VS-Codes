#include<iostream>
using namespace std;

int remainder(int a, int b){
    int rem;
    if(b!=0){
        rem=a%b;
    }
    else{
        throw 0;
        return rem;
    }
}

int main(){
    int a,b,rem;
    cin>>a>>b;
    try{
        rem=remainder(a,b);
        cout<<"Remainder "<<rem<<endl;
    }
    catch(int a){
        cout<<"Can't be divided by "<<b<<endl;
    }
}