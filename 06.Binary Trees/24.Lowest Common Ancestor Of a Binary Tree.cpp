                                  //Lowest Common Ancestor Of a Binary Tree

//Time Complexity: O(n)
//Space Complexity: O(h) where h is the height of the tree
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
Node* LowestCommonAncestor(Node* root,int p,int q){
    if(root==nullptr){
        return nullptr;
    }
    if(root->data==p || root->data==q){
        return root;
    }
    Node* left=LowestCommonAncestor(root->left,p,q);
    Node* right=LowestCommonAncestor(root->right,p,q);
    if(left==nullptr){
        return right;
    }
    else if(right==nullptr){
        return left;
    }
    else{
        return root;
    }
}
int main(){
   Node* root=new Node(3);
   root->left=new Node(5);
   root->right=new Node(1);
   root->left->left=new Node(6);
   root->left->right=new Node(2);
   root->right->left=new Node(0);
   root->right->right=new Node(8);
   root->left->right->left=new Node(7);
   root->left->right->right=new Node(4);
   int p;
   cout<<"Enter the first node value: ";
   cin>>p;
   int q;
   cout<<"Enter the second node value: ";
   cin>>q;
   Node* ans=LowestCommonAncestor(root,p,q);
   if(ans!=nullptr){
       cout<<"Least Common Ancestor is: "<<ans->data;
   }
   else{
       cout<<"No Common Ancestor";
   }
}
