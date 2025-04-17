#include<iostream>
using namespace std;

class Person{
    int id;
    int roll;
    string name;
    string dept;
    string designation;
    float gpa;

public:
    void input(int ID, int ROLL, string NAME, string DEPT, string DESIGNATION, float GPA){
        id=ID, roll=ROLL, name=NAME, dept=DEPT, designation=DESIGNATION, gpa=GPA;
    }

    void student_input(){
        cin.ignore();
        cout<<"Enter Student Name: "<<endl;
        getline(cin,name);
        cout<<"Enter Roll: "<<endl;
        cin>>roll;
        cin.ignore();
        cout<<"Enter Dept: "<<endl;
        getline(cin, dept);
        cout<<"Enter GPA: "<<endl;
        cin>>gpa;
    }

    void display_student(){
        cout<<"Student Name: "<<name<<endl;
        cout<<"Roll: "<<roll<<endl;
        cout<<"Dept: "<<dept<<endl;
        cout<<"GPA: "<<gpa<<endl;
        
    }

    void teacher_input(){
        cin.ignore();
        cout<<"Enter Teacher Name: "<<endl;
        getline(cin,name);
        cout<<"Enter ID: "<<endl;
        cin>>id;
        cin.ignore();
        cout<<"Enter Designation: "<<endl;
        getline(cin,designation);

    }

    void display_teacher(){
        cout<<"Teacher Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Designation: "<<designation<<endl;
        
    }
};

class Student:public Person{
    public:
    void student_call(){
        student_input();
        display_student();
    }
    
};

class Teacher:public Person{
    public:
    void teacher_call(){
        teacher_input();
        display_teacher();
    }

    
};

int main(){
    int t;
    cout<<"Enter Amount: "<<endl;
    cin>>t;

    for(int i=0; i<t; i++){
    
        Student s1;
        s1.student_call();
        //s1.display_student();
        
        Teacher t1;
        t1.teacher_call();
        //t1.display_teacher();
    
    }
 
}