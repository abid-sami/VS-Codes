// Write a C++ program to implement a class called Student that has private member variables for name, class, roll number, and marks. Include member functions to calculate the grade based on the marks and display the student's information.
#include<iostream>
using namespace std;
class Student{
    string name;
    int sclass, roll;
    float marks;
public:
    void input(){
        cin>>name>>sclass>>roll>>marks;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Class: "<<sclass<<endl;
        cout<<"Roll: "<<roll<<endl;
    }
    void grade(){
        if(marks>=80){
            cout<<"Grade: A+"<<endl;
        }
        else if(marks>=75){
            cout<<"Grade: A"<<endl;
        }
        else if(marks>=70){
            cout<<"Grade: A-"<<endl;
        }
        else if(marks>=65){
            cout<<"Grade: B+"<<endl;
        }
        else if(marks>=60){
            cout<<"Grade: B-"<<endl;
        }
        else if(marks>=55){
            cout<<"Grade: C+"<<endl;
        }
        else if(marks>=50){
            cout<<"Grade: C+"<<endl;
        }
        else if(marks>=45){
            cout<<"Grade: C"<<endl;
        }
        else if(marks>=40){
            cout<<"Grade: D"<<endl;
        }
        else if(marks<40){
            cout<<"Grade: F"<<endl;
        }
    }
};

int main(){
    Student s1;
    s1.input();
    s1.display();
    s1.grade();

}