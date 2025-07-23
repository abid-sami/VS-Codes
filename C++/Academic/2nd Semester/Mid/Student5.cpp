//Class - Count using Static
#include<iostream>
using namespace std;
class Student{
    int id;
    static int count;
    public:
    void set_value(){
        cin>>id;
        count+=1;
    }
    void display(){
        cout<<"ID: "<<id<<endl;
    }
    void total(){
        cout<<"Total Student: "<<count<<endl;
    }
};
int Student::count;
int main(){
    Student st1, st2;
    st1.set_value();
    st2.set_value();
    st1.display();
    st2.display();
    st2.total();
}