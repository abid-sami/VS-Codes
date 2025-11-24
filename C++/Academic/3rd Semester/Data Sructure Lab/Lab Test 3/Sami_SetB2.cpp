#include<iostream>
using namespace std;

int n=100;
int Stack[100];
int top=-1;

void push(int x){
    if(top==n-1){
        cout<<"Overflow"<<endl;
    }else{
        top++;
        Stack[top]=x;
        cout<<"Stack after push: ";
        for(int i=0; i<=top; i++){
            cout<<Stack[i]<<" ";
        }
        cout<<endl;
    }
}

void pop(){
    if(top==-1){
        cout<<"Underflow" <<endl;
    }else{
        top--;
        cout<<"Stack after pop: ";
        if(top==-1){
            cout<<"(empty)";
        } else {
        for(int i=0; i<= top; i++){
        cout<<Stack[i] << " ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        push(x);
    }
    for(int i = 0; i<n; i++){
        pop();
    }
}
