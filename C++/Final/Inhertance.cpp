#include<iostream>
using namespace std;

class Parent{
    int z;
public:
int x,y;
};

class Child: private Parent{
    public:
    int a,b;
    void get_value(){
        cin>>x>>y;
    }
    void display(){
        cout<<x<<"---"<<y<<endl;
    }
};

int main(){
    Child c1;
    cin>>c1.a>>c1.b;
    cout<<c1.a<<"---"<<c1.b<<endl;

    c1.get_value();
    c1.display();

}
