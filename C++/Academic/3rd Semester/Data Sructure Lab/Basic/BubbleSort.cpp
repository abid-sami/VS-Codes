//BubbleSort

#include<iostream>
using namespace std;

void bubblesort(int A[], int n){
    for(int i=0; i<n-1; i++){
        bool flag=0;
        for(int j=0; j<n-1-i; j++){
            if(A[j]>A[j+1]){
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    bubblesort(A,n);
    cout<<"Result"<<endl;
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}