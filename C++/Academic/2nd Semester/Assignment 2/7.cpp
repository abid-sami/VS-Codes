//Write a C++ program to implement a class called Employee that has private member variables for name, employee ID, and salary. Include member functions to calculate and set salary based on employee performance.

#include<iostream>
using namespace std;
class Employee{
    string name;
    int id, rating;
    float salary,s;
public:
    void input(){
    cin>>name>>id>>salary>>rating;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        if(rating==5){
            s=salary*0.5;
        }
        else if(rating==4){
            s=salary*0.4;
        }
        else if(rating==3){
            s=salary*0.3;
        }
        else if(rating==2){
            s=salary*0.2;
        }
        else if(rating==1){
            s=salary*0.1;
        }
        cout<<"Salary: "<<salary+s<<endl;
    }

};

int main(){
    Employee e;
    e.input();
    e.display();
}
