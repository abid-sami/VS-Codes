//Write a C++ program that prints your name, id, department, semester, and section. 
#include<iostream>
using namespace std;
struct student{
    string name;
    int id;
    string dept;
    int sem;
    char sec;
};
int main(){
    int n, i;
    cout<<"Enter Student Amount: "<<endl;
    cin>>n;
    struct student st[n];
    for(i=0; i<n; i++){
        cout<<"Enter Name: "<<endl;
        getchar();
        getline(cin,st[i].name);
        cout<<"Enter ID: "<<endl;
        cin>>st[i].id;
        cout<<"Enter Department: "<<endl;
        cin>>st[i].dept;
        cout<<"Enter Semester: "<<endl;
        cin>>st[i].sem;
        cout<<"Enter Section: "<<endl;
        cin>>st[i].sec;
    }
    cout<<"\tStudent Info"<<endl;
    for(i=0; i<n; i++){
        cout<<"Name: "<<st[i].name<<endl;
        cout<<"ID: "<<st[i].id<<endl;
        cout<<"Department: "<<st[i].dept<<endl;
        cout<<"Semester: "<<st[i].sem<<endl;
        cout<<"Section: "<<st[i].sec<<endl;

    }

}
