//Constructor
#include<iostream>
using namespace std;
class Student{
    int ID;
    string Name;
public:
    Student(int id, string name);
    void display(){
    cout<<"ID: "<<ID<<endl;
    cout<<"Name: "<<Name<<endl;
    }
};
Student::Student(int id, string name){
ID=id, Name=name;
}
int main(){
    Student st1(70,"Varendra"),
    st2(80,"Sami");
    st1.display();
    st2.display();
}
