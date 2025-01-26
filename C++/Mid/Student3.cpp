#include<iostream>
using namespace std;
class Student{
    private:
    int ID;
    string Name;
    public:
    void set_value(int id, string name){
        ID=id, Name=name;
    }
    void get_value(){
        cout<<"ID: "<<ID<<endl;
        cout<<"Name: "<<Name<<endl;
    }
};
int main(){
    Student stu1;
    stu1.set_value(242311070,"Abid Sami");
    stu1.get_value();
}