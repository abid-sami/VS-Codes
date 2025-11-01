#include<iostream>
using namespace std;

int n=5;
int queue[5];
int front=-1;
int rear=-1;

void equeue(int x){
    if((front == 0 && rear == n-1) || (rear + 1 == front)){ // Fixed: Correctly check if queue is full
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

int main() {
    int choice, value;

    while (true) {
        cout << "\nSelect Operations: " << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                equeue(value);
                break;
            case 2:
                dqueue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
}