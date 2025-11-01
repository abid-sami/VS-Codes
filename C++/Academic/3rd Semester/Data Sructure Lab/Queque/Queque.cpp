#include<iostream>
using namespace std;

int n=5;
int queue[5];
int front=-1;
int rear=-1;

void equeue(int x){
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
}

void dqueue(){
    if(front==-1 && rear ==-1){
        cout<<"Queue is Empty"<<endl;
    }
    else if(front==rear){
        cout<<"Dequeued: "<<queue[front]<<endl;
        front=rear=-1;
    }
    else{
        cout<<"Dequeued: "<<queue[front]<<endl;
        front++;
    }
}

void display(){
    if(front==-1 && rear==-1){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        cout<<"Queue: ";
        for(int i=front; i<=rear; i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}