//Structure - Store & Print student ID, Name, 3 Subjects Marks
#include<iostream>
using namespace std;
struct student{
    int id;
    string name;
    float mark[3];
};

int main(){
    int i, n, j;
    cout<<"Enter Students Amount: "<<endl;
    cin>>n;
    struct student st[n];
    for(i=0; i<n; i++){
        cout<<"Enter ID: "<<endl;
        cin>>st[i].id;
        cout<<"Enter Name: "<<endl;
        getchar();
        getline(cin, st[i].name);
        for(j=0; j<3; j++){
            cout<<"Enter Marks: "<<j+1<<endl;
            cin>>st[i].mark[j];
        }
    }
    cout<<"\tStudent Info"<<endl;
    for(i=0; i<n; i++){
        cout<<"ID: "<<st[i].id<<endl;
        cout<<"Name: "<<st[i].name<<endl;
        for(j=0; j<3; j++){
            cout<<"Marks: "<<st[i].mark[j]<<endl;
        }
        
    }


}