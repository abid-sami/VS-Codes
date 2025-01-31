// Write a C++ program to create a class called Person that has private member variables for name, age and country. Implement member functions to set and get the values of these variables. 
#include<iostream>
using namespace std;
class Person{
    string name;
    int age;
    string country;
public:
    void input(){
    cin>>name>>age>>country;
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
