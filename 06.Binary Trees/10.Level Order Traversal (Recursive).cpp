                                //Level Order Traversal (Recursive Method)

//Time Complexity: O(n²)
//Space Complexity: O(h) where h is the height of the tree
#include<iostream>
#include<algorithm>
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
int height(Node* root){
    if(root==nullptr) return 0;
    return 1+max(height(root->left),height(root->right));
}
void printlevel(Node* root,int level){
    if(root==nullptr) return;
    if(level==1){
        cout<<root->data<<" ";
    }
    else{
        printlevel(root->left,level-1);
        printlevel(root->right,level-1);
    }
}
void LevelOrderTraversal(Node* root){
    int h=height(root);
    for(int i=1;i<=h;i++){
        printlevel(root,i);
    }
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    LevelOrderTraversal(root);
}
