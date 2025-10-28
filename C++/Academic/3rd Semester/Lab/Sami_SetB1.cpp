#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data=value;
        next=nullptr;
    }
};
Node* ticket(int arr[], int size){
    Node* head = nullptr;
    Node* current=nullptr;

    for(int i=0; i<size; i++){
        Node* temp=new Node(arr[i]);

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

void display(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
Node* deleteNode(Node* head, int data){
    if (head!=nullptr && head->data==data){
        head=head->next;
        return head;
    }
    Node* temp=head;
    while(temp!=nullptr && temp->next!=nullptr){
        if(temp->next->data==data){
            temp->next=temp->next->next;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    int n, del;
    cout<<"Enter ticket amount: "<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter ticket numbers: "<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    Node* head=ticket(a, n);
    cout<<"Enter Deleting number: "<<endl;
    cin>>del;
    head=deleteNode(head,del);
    cout<<"Updated Queue: "<<endl;
    display(head);

}
