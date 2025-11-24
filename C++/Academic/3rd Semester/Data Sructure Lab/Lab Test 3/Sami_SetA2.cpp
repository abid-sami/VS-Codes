#include<iostream>
using namespace std;

int n=5;
int queue[5];
int front=-1;
int rear=-1;

void enqueue(int x){
    if(rear==n-1){
        cout<<"Overflow"<<endl;
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }

    cout<<"Queue after insertion: ";
    if(front== -1)
    cout<<"(empty)";
    else{
        for(int i=front; i<=rear; i++){
            cout<<queue[i]<<" ";
        }
    }
    cout<<endl;
}

void dequeue(){
    if(front==-1 && rear ==-1){
        cout<<"Queue is Empty"<<endl;
    }
    else if(front==rear){
cout<<"Queue after deletion:(empty):"<<endl;
        front=rear=-1;
    }
    else{
        front++;
        cout << "Queue after deletion: ";
        for(int i=front; i<=rear; i++){
            cout<<queue[i]<<" ";
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
        enqueue(x);
    }
    for(int i=0; i<n; i++){
        dequeue();
    }
}
