//Write a C++ program to generate the first n numbers of the Fibonacci sequence, where n is provided by the user.
#include<iostream>
using namespace std;
int main(){
    int i, n, f=0, l=1, a;
    cout<<"Enter Number: ";
    cin>>n;
    cout<<"Fibonacci Sequence: "<<endl;
    for(i=1; i<=n; i++){
        cout<<f<<endl;
        a=f+l;
        f=l;
        l=a;
    }

}