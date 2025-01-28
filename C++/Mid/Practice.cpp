#include<iostream>
using namespace std;
class student{
    private:
    int id;
    string name;
    float cgpa;
    public:
    void valu(){
        cin>>id>>name>>cgpa;
    }
    void displa(){
        cout<<"Id "<<id<<endl;
        cout<<"Name "<<name<<endl;
        cout<<"Cgpa "<<cgpa<<endl;
    }
};
int main(){
    student st1;
    st1.valu();
    st1.displa();
}