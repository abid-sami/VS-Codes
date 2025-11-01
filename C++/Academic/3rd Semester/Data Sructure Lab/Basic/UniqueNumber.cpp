//Print all the unique elements

#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,2,3,4,4,5};
    for(int i=0; i<7; i++){
        bool unique=1;

        for(int j=i+1; j<7; j++){
            if(arr[i]==arr[j]){
                unique=0;
                break;
            }
        }
        if(unique){
            cout<<arr[i]<<" ";
        }
    }

}