#include<iostream>
using namespace std;
int max(int num[], int n){
    int m=num[0];
    for(int i=0; i<n; i++){
        if(m<num[i]){
            m=num[i];
        }
    }
    return m;
}
int min(int num[], int n){
    int m=num[0];
    for(int i=0; i<n; i++){
        if(m>num[i]){
            m=num[i];
        }
    }
    return m;
}

int main(){
    int n, i;
    cout<<"Enter amount: ";
    cin>>n;
    int num[n];
    cout<<"Enter Numbers: ";
    for(i=0; i<n; i++){
        cin>>num[i];
    }
    cout<<"Maximum: "<<max(num,n)<<endl;
    cout<<"Minimum: "<<min(num,n);

}