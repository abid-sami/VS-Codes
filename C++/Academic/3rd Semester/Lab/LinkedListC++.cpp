//linked list using Class

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node*next;
};

int main(){
    Node*a=new Node();
    Node*b=new Node();
    Node*c=new Node();

    a->data=10;
    b->data=20;
    c->data=30;
    a->next=b;
    b->next=c;
    c->next=nullptr;
    Node*temp=a;

    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"null";
}
