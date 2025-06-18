/* Create a program that initializes an array of 5 integers. Ask the user to enter an index 
to access an element in the array. If the user enters an index out of bounds, throw an 
exception and catch it to display a message like "Array index out of bounds." Test this 
by entering indices within and outside the array bounds. */

#include <iostream>
using namespace std;

int main(){
    int a[5]={1,2,3,4,5};
    cout << "Enter between 0 to 4" << endl;
    int n;
    cin>>n;
    try{
        if(n<0 || n>=5){
            throw n;
        }
        cout<<"Found"<<endl;
    }
    catch(int){
        cout<<"Array index out of bounds."<<endl;
    }   

}