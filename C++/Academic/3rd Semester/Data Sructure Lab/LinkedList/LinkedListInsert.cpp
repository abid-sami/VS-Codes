#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* Insert(Node* head, int value){
    Node* newNode=new Node;
    newNode->data=value;
    newNode->next=NULL;

    if(head==NULL){
        head=newNode;
    }
    else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    return head;

}

void display(Node* head){
    Node* temp=head;
    cout<<"Linkedlist: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head=NULL;
    int n, value;

    cout<<"Enter amount of Nodes: "<<endl;
    cin>>n;

    cout<<"Enter values: "<<endl;
    for(int i=0; i<n; i++){
        cin>>value;
        head=Insert(head, value);
    }
    display(head);
}