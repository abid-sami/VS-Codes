#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};
class Link{
    Node* head;
public:
    Link(){
        head=nullptr;
    }
    void insert(int v){
        Node* newNode=new Node(v);
        if(head==nullptr){
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    void replace(int key,int v){
        Node* temp=head;
        while(temp!=nullptr){
            if(temp->data==key){
                temp->data=v;
            }
            temp=temp->next;
        }
    }
    void display(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Link l;
    int n,x,key,val;
    cout<<"Enter number of nodes:";
    cin>>n;
    cout<<"Enter values:";
    for(int i=0; i<n; i++){
        cin>>x;
        l.insert(x);
    }
    cout<<"Current Student ID List:"<<endl;
    l.display();
    cout<<"Enter value to replace:";
    cin>>key;
    cout<<"Enter new value:";
    cin>>val;
    l.replace(key,val);
    cout<<"After replacement:"<<endl;
    l.display();
}
