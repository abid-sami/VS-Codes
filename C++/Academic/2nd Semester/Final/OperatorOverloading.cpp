/* Write a C++ program that overloads the function findMax() to:
Return the maximum of two integers.
Return the maximum of two floats.
Return the maximum of three integers.
Demonstrate the function calls in the main() function.*/

#include<iostream>
using namespace std;

int findMax(int a, int b){

    if(a>b){
        return a;
    }
}

int findMax(float a, float b){

    if(a>b){
        return a;
    }
}

int findMax(int a, int b, int c){

    if(a>b && a>c){
        return a;
    }
    else if(b>a && b>c){
        return b;
    }
    else{
        return c;
    }
}

int main(){
    cout<<findMax(1,2)<<endl;
}
