#include<iostream>
using namespace std;

class student{
    int id;
    static int count;
    public:
    void input(){
        cin>>id;
        count++;
    }
    void display(){
        cout<<"Students ID: "<<id<<endl;
    }
    static void total(){
        cout<<"Total Student: "<<count<<endl;
    }
};
int student::count;
int main(){
    student st1, st2;
    st1.input();
    st2.input();
    st1.display();
    st2.display();
    st2.total();
   
}