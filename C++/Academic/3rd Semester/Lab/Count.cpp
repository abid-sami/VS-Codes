//Count the number of times each elements appears in the array

#include<iostream>
using namespace std;

int main(){
    int arr[]={2,3,2,4,3,3};
    int a=0,  b=0, c=0;
    for(int i=0; i<4; i++){
        if(arr[i]==2){
            a++;
        }
        else if(arr[i]==3){
            b++;
        }
        else if(arr[i]==4){
            c++;
        }
    }
    cout<<"2:"<<a<<" "<<"3:"<<b<<" "<<"4:"<<c<<endl;
}