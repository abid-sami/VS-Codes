#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data=value;
        left=nullptr;
        right=nullptr;
    }
};
Node* buildTree(Node* root, int value) {
    if(root==nullptr) {
        return new Node(value);
    }
    if(value<root->data) {
root->left=buildTree(root->left, value);
    }else{
root->right=buildTree(root->right, value);
    }
    return root;
}
void inorderTraversal(Node* root){
    if(root==nullptr)
    return;
    inorderTraversal(root->left);
    cout<<root->data << " -> ";
    inorderTraversal(root->right);
}
int sumTree(Node* root){
    if (root == nullptr){
        return 0;}

int leftSum=sumTree(root->left);
int rightSum=sumTree(root->right);
int totalSum=root->data+leftSum+rightSum;
    return totalSum;
}
int main(){
    int n;
    cin>>n;
    Node* root=nullptr;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        root=buildTree(root,a);
    }
cout<<"\nInorder Traversal of BST: "<<endl;
    inorderTraversal(root);
    int item=10;
    int leftSum=sumTree(root->left);
    int rightSum=sumTree(root->right);

cout<<"\nLeft Subtree Sum: "<<leftSum;
cout<<"\nRight Subtree Sum: "<<rightSum<<endl;

    if(leftSum>rightSum){
cout<<"Left sum is greater than right sum.";
    }
    else if(rightSum>leftSum){
cout<<"Right sum is greater than left sum.";
    }
    else{
cout<<"Left and right sums are equal.";
    }
}
