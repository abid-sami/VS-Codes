#include<iostream>
using namespace std;

class faculty{
private:
    int fid;
    char name[20];
public:
    void getdata(){
        cout<<"Enter faculty id: \t";
        cin>>fid;
        cout<<"Enter Name: \t";
        cin>>name;
    }
    void fdisplay(){
        cout<<"Faculty ID: "<<fid<<endl;
        cout<<"Name of Faculty: "<<name<<endl;
    }
};

class details:public faculty{
public:
    int age, exp;
    void getdetails(){
        getdata();
        cout<<"Enter age: \t";
        cin>>age;
        cout<<"Enter years of experience: \t";
        cin>>exp;
    }
    void display(){
        fdisplay();
        cout<<"Faculty Age: "<<age<<endl;
        cout<<"Faculty Experience: "<<exp<<endl;
    }
};

int main() {
    details m;
    m.getdetails();
    m.display();
    
}