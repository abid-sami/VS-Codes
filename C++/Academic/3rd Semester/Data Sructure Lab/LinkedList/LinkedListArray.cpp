//LinkedList with Array (Maam's Tutorial)

#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
    int data;
    struct Node*next;
};
struct Node*LinkList(int arr[], int size){
struct Node*head=nullptr;
struct Node*current=nullptr;
struct Node*temp=nullptr;
for(int i=0; i<size; i++){
    temp=(struct Node*)malloc(sizeof(Node));
    temp->data=arr[i];
    temp->next=nullptr;

    if(head==nullptr){
        head=temp;
        current=temp;
    }
    else{
        current->next=temp;
        current=current->next;
    }
}
return head;

}

int main(){
    int a[]={15, 30, 45, 60, 100};
    Node*head=LinkList(a,5);
    Node*current=head;
    while(current!=nullptr){
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<"null";

}
