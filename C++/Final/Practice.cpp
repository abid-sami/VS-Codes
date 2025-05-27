#include<iostream>
using namespace std;

class student{
    int id;
    static int count;
public:
    void input(){
        cin>>id;
        count+=1;
    }
    void display(){
        cout<<"ID: "<<id<<endl;
    }
    static void scount(){
        cout<<"Total Student: "<<count<<endl;
    }
};
int student::count;

int main(){
    student s1, s2;
    s1.input();
    s2.input();
    s1.display();
    s2.display();
    student::scount();
}