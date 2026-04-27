                                      //Pre Order Traversal

//Time Complexity: O(n)
//Space Complexity: O(h) where h is the height of tree
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
void preorder(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node* root=new Node(5);
    root->left=new Node(4);
    root->right=new Node(3);
    root->right->left=new Node(2);
    root->right->right=new Node(1);
    preorder(root);
}
