#include<iostream>
using namespace std;
 
class A {
    int a;
public:
    A(int x) {
        a=x;
        cout << "Constructor of A Called" << endl;
    }
    ~A() {
        cout << "Destructor of class A Called" << endl;
        cout << "Destructor a = " <<a<< endl;
    }
};
 
class B: public A {
    int b;
public:
    B(int y):A(y) {
        b=y;
        cout << "Constructor of class B Called" << endl;
    }
    ~B()
    {
        cout<<"Destructor of Class B Called " <<endl;
    }
};
 
int main(){
    B b(5);

 return 0;
}