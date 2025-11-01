#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTree(){
    int value;
    cout<<"Enter node value: ";
    cin>>value;

    Node* newNode=new Node(value);

    char choice;
    cout<<"Does "<<value<<" have a left child? ";
    cin>>choice;
    if (choice == 'y'){
        newNode->left=buildTree();
    }

    cout<<"Does "<<value<<" have a right child? ";
    cin>>choice;
    if (choice == 'y'){
        newNode->right=buildTree();
    }

    return newNode;
}


void inorderTraversal(Node* root){
    if (root == nullptr)
    return;
    inorderTraversal(root->left);
    cout<<root->data << " -> ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root){
    if (root == nullptr)
    return;
    cout<<root->data << " -> ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root){
    if(root == nullptr)
    return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data << " -> ";
}

int main(){
    cout<<"....Build a binary tree...."<<endl;
    Node* root = buildTree();

    cout<<"\nInorder Traversal : "<<endl;
    inorderTraversal(root);

    
    cout<<"\nPreorder Traversal : "<<endl;
    preorderTraversal(root);

    cout<<"\nPostorder Traversal : "<<endl;
    postorderTraversal(root);

}