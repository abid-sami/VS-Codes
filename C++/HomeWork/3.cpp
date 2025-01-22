//Write a C++ program to find the largest of three numbers provided by the user.
#include<iostream>
using namespace std;
int main(){
    int i, n[3];
    cout<<"Enter 3 Numbers: ";
    for(i=0; i<3; i++){
        cin>>n[i];
    }
    int max=n[0];
    for(i=0; i<3; i++){
        if(max<n[i]){
            max=n[i];
        }
    }
    cout<<"Maximum Number: "<<max<<endl;

} 