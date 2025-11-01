//LinkedList with Array using Class

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node*next;
};

Node*LinkList(int arr[],int size){
    Node*head=nullptr;
    Node*current=nullptr;
    Node*temp=nullptr;
    for(int i=0;i<size;i++){
        temp=new Node();
        temp->data=arr[i];
        temp->next=nullptr;
        if(head==nullptr){
            head=temp;
            current=temp;
        }else{
            current->next=temp;
            current=current->next;
        }
    }
    return head;
}

int main(){
    int a[]={15,30,45,60,100};
    Node*head=LinkList(a,5);
    Node*current=head;
    while(current!=nullptr){
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<"null\n";
    while(head!=nullptr){
        Node*next=head->next;
        delete head;
        head=next;
    }
}
