//Write a C++ program to implement a class called Employee that has private member variables for name, employee ID, and salary. Include member functions to calculate and set salary based on employee performance.

#include<iostream>
using namespace std;
class Person{
    string name;
    int id;
    float salary;
public:
    void input(){
    cin>>name>>id>>salary;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Country: "<<country<<endl;
    }

};
int main()
{
    Person p;
    p.input();
    p.display();

}
