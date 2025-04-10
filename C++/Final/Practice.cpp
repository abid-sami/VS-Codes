#include<iostream>
using namespace std;

class Parent{
    public:
    int x,y;
};

class Child:Parent{
    public:
    int a,b;

    void input(){
        cin>>x>>y;
    }
    void display(){
        cout<<x<<"..."<<y<<endl;
    }

};


int main(){
  Child c1;
  cin>>c1.a>>c1.b;
  cout<<c1.a<<"..."<<c1.b<<endl;

  c1.input();
  c1.display();

}