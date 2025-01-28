//Input using class
#include<iostream>
using namespace std;
class student{
    private:
    int id;
    string name;
    float cgpa;
    public:
    void set_value(){
        cin>>id>>name>>cgpa;
    }
    void set_display(){
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"CGPA: "<<cgpa<<endl;
    }
};
int main(){
    student st1;
    st1.set_value();
    st1.set_display();
}