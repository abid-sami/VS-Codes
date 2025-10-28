#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* InsertBook(Node *head, int value){
    Node *newNode=new Node;
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
void display(Node *head){
    Node *temp=head;
    cout<<"Books: ";
    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
int countBooks(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head=NULL;
    int n, nn, id;
    cout<<"Enter number of books: ";
    cin>>n;
    if(n>0){
        cout<<"Enter the books IDs: " << endl;
        for(int i=0; i<n; i++) {
            cin>>id;
            head=InsertBook(head, id);
        }
    }
    cout<<"Before adding new books:" <<endl;
    display(head);

    cout<<"New arrivals: ";
    cin>>nn;

    if(nn>0){
        cout<<"Enter the new book IDs: "<<endl;
        for(int i = 0; i<nn; i++) {
            cin>>id;
            head=InsertBook(head, id);
        }
    }
    cout<<"After insertion:" <<endl;
    display(head);
    cout<<"Total number of books: "<<countBooks(head)<<endl;
}