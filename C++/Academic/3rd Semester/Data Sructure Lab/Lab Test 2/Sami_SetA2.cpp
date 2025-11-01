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
    void del(int key){
        while(head!=nullptr&&head->data==key){
            Node* delNode=head;
            head=head->next;
            delete delNode;
        }
        if(head==nullptr) return;
        Node* temp=head;
        while(temp->next!=nullptr){
            if(temp->next->data==key){
                Node* delNode=temp->next;
                temp->next=temp->next->next;
                delete delNode;
            }
            else{
                temp=temp->next;
            }
        }
    }
    void display(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    Link l;
    int n,x,delv;
    cout<<"Enter number of items:";
    cin>>n;
    cout<<"Enter batch IDs:";
    for(int i=0;i<n;i++){
        cin>>x;
        l.insert(x);
    }
    cout<<"Current Inventory List:"<<endl;
    l.display();
    cout<<"Enter faulty batch ID to remove:";
    cin>>delv;
    l.del(delv);
    cout<<"Updated Inventory:"<<endl;
    l.display();
}
