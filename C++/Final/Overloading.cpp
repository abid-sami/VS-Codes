//Function Overloading Example

#include<iostream>
using namespace std;

class Parent{
    public:
    void display(){
        cout<<"Parent"<<endl;
    }
};

class Child:public Parent{
    public:
    void display(){
        cout<<"Child"<<endl;
    }
};

int main(){
    Child c1;
    c1.Parent::display();
}