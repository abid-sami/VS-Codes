#include<iostream>
using namespace std;

class Car{
    public:
    int year;
    string name;
    string company;

};

int main(){
    int n;
    cin>>n;
    Car c[n];
    for(int i=0; i<n; i++){
        cin>>c[i].year;
        cin>>c[i].name;
        cin>>c[i].company;
    }
    for(int i=0; i<n; i++){
        cout<<"Year: "<<c[i].year<<endl;
        cout<<"Name: "<<c[i].name<<endl;
        cout<<"Company: "<<c[i].company<<endl;
    } 

}