//Write a C++ program to create a class called Car that has private member variables for company, model, and year. Implement member functions to get and set these variables
#include<iostream>
using namespace std;
class Car{
    string company;
    string model;
    int year;
public:
    void input(){
    cin>>company>>model>>year;
    }
    void display(){
        cout<<"Company: "<<company<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Year: "<<year<<endl;
    }

};
int main()
{
    Car p;
    p.input();
    p.display();

}

