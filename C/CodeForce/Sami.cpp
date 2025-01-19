#include<bits/stdc++.h>
using namespace std;
int main(){
    char n[100];
    cin>>n;
    int len=0;
    for(int i=0; n[i]!='\0'; i++){
        len++;
    }
    
    if(len%2==0){
        cout<<"CHAT WITH HER!"<<endl;
    }
    else {
       cout<<"IGNORE HIM!"<<endl;
    }
    return 0;
}