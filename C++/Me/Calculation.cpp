#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter 2 Numbers: ";
    cin>>a>>b;

    int sum=a+b;
    cout<<"Sum: "<<sum;

    int sub=a-b;
    cout<<"\nSubtraction: "<<sub;

    int mul=a*b;
    cout<<"\nMultiplication: "<<mul;

    float div=(float)a/b;
    cout<<"\nDivision: "<<div;

    int rem=a%b;
    cout<<"\nReminder: "<<rem;

}