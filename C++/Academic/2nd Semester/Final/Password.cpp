//Password input check using Exception Handling

#include<iostream>
using namespace std;

int main(){
    string p;
    cin>>p;
    bool up=0;
    bool low=0;
    bool digit=0;
    try{
        if(p.length()<8){
            throw "Minimum 8 Character";
        }
        for(int i=0; i<p.length(); i++){
            if(p[i]>='A' && p[i]<='Z'){
                up=1;
            }
            if(p[i]>='A' && p[i]<='Z'){
                low=1;
            }
            if(p[i]>='0' && p[i]<='9'){
                digit=1;
            }
        }
        if(!up){
            throw "At least one Uppercase";
        }
        if(!low){
            throw "At least one Lowercase";
        }
        if(!digit){
            throw "At least one digit";
        }
        cout<<"Password is valid"<<endl;
    }
    catch(const char* c){
        cout<<"Invalid Password\n"<<c<<endl;
    }
}