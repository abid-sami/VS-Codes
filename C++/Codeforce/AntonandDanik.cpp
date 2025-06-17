#include<iostream>
using namespace std;

int main(){
    int n, anton=0, danik=0;
    cin >> n;
    char a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]=='A'){
            anton++;
        }
        if(a[i]=='D'){
            danik++;
        }
    }
    if(anton > danik){
        cout << "Anton" << endl;
    } else if(danik > anton){
        cout << "Danik" << endl;
    } else {
        cout << "Friendship" << endl;
    }

}