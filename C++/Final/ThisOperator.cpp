//This Operator Tutorial

#include<iostream>
using namespace std;

class Test{
    int a,b;
    public:
    void set_value(int a, int b){
        this->a=a;
        this->b=b;
    }
    void display(){
        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;
    }
};

int main(){
    Test t;
    t.set_value(3,7);
    t.display();

}
