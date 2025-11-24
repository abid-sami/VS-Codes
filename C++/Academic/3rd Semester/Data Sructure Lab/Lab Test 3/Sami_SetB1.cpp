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
Node* buildTree(Node* root, int value) {
    if(root== nullptr) {
        return new Node(value);
    }
    if(value<root->data) {
root->left = buildTree(root->left,value);
    }else{
root->right=buildTree(root->right,value);
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

int Threshold(Node* root, int threshold) {
    if(root==nullptr) return 0;
    int sum=0;
    if(root->data<threshold)
        sum+=root->data;
    sum+=Threshold(root->left, threshold);
    sum+=Threshold(root->right, threshold);
    return sum;
}
void LessThreshold(Node*root,int threshold){
    if(root==nullptr) return;
    LessThreshold(root->left, threshold);
if(root->data< threshold)
    cout << root->data << " ";
    LessThreshold(root->right, threshold);
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
    int threshold;
    cin>>threshold;
    cout<<"In-Order Traversal: ";
    inorderTraversal(root);
cout<<"\nEnergy usage "<<threshold<<": ";
    LessThreshold(root, threshold);
int total=Threshold(root, threshold);
cout<<"\nTotal Energy Usage: "<<total;
}
