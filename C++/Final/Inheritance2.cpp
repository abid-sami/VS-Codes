#include<iostream>
using namespace std;

class Parent{
    int x,y;
    public:
    int a,b;
    void set_value_parent(int p, int q){
        x=p, y=q, a=2*p, b=2*q;
    }
    void display_parent(){
        cout<<"Parent Class "<<x<<" "<<y<<' '<<a<<' '<<b<<endl;

    }
};

class Child:public Parent{
    int m,n;
    public:

    void set_value_child(int p, int q){
        m=p, n=q;
        set_value_parent(p,q);
    }
    
    void display_child(){
        cout<<"Child class "<<m<<" "<<n<<endl;
    }
};

int main(){
    Child c1;
    c1.set_value_child(7,8);
    c1.display_child();
    c1.set_value_parent(300,67);
    c1.display_parent();


    Parent p1;
    p1.set_value_parent(78, 89);
    p1.display_parent();
}