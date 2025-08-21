//linked list using struct (Maam's Tutorial)

#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
    int data;
    struct Node*next;
};

int main(){
    Node*a=nullptr;
    Node*b=nullptr;
    Node*c=nullptr;
    a=(Node*)malloc(sizeof(Node));
    b=(Node*)malloc(sizeof(Node));
    c=(Node*)malloc(sizeof(Node));

    a->data=10;
    b->data=20;
    c->data=30;

    a->next=b;
    b->next=c;
    c->next=nullptr;

    while(a!=nullptr){
        cout<<a->data<<"->";
        a=a->next;
    }
    cout<<"null";

}
