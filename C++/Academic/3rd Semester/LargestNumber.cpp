//Find the largest number from 3 numbers

#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    if(a >= b && a >= c){
        cout << "A is the Largest number"<<endl;
    }
    else if(b >= a && b >= c){
        cout << "B is the Largest number"<<endl;
    }
    else{
        cout << "C is the Largest number"<<endl;
    }
}
