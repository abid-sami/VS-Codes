//Store Student Details
#include<iostream>
#include<string.h>
using namespace std;
 
struct student{
    char name[50];
    int roll;
    float gpa;
};

int main(){
    int n,i;
    cout<<"Enter Student Amount :";
    cin>>n;
    struct student st[n];
    for(i=0; i<n; i++){
        cout<<"Enter Name: ";
        getline(cin, st[i].name);
        cout<<"Enter Roll: ";
        cin>>st[i].roll;
        cout<<"Enter GPA: ";
        cin>>st[i].gpa;
    }
    for(i=0; i<n; i++){
        cout<<"\tStudent Info"<<endl;
        cout<<"Name: "<<st[i].name<<endl;
        cout<<"Roll: "<<st[i].roll<<endl;
        cout<<"GPA: "<<st[i].gpa<<endl;
    }

}