#include<iostream>
using namespace std;

int remainder(int a, int b){
    if(b!=0){
        return a%b;
    }
    else{
        throw 0;
    }
}

int main(){
    int a,b,rem;
    cin>>a>>b;
    try{
        rem=remainder(a,b);
        cout<<"Remainder: "<<rem<<endl;
    }
    catch(int c){
        cout<<"Can't be divided by "<<c<<endl;
    }
}