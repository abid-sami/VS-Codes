//Find the number of odd and even numbers in an array.

#include<iostream>
using namespace std;

int main(){
    int arr[]={10,3,5,6,8,9};
    int odd=0, even=0;
    for(int i=0; i<6; i++){
        if(arr[i]%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    cout<<"Even: "<<even<<endl;
    cout<<"Odd: "<<odd<<endl;

}