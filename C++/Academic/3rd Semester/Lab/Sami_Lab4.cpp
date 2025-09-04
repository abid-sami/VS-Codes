#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter array Amount: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter Scores: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Sorting Method: Bubble Sort (Descending Order)"<<endl;
    cout<<"Scores before sorting: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    for(int i=0; i<n-1; i++){
        bool flag=0;
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
    cout<<"Scores after sorting: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Analysis:"<<endl;
    cout<<"Number of passes in worst case = n - 1 = "<<n-1<<endl;
    for(int i=1; i<n; i++){
        cout<<"Number of comparisons in pass "<<i<<" = "<<n-i<<endl;
    }

}