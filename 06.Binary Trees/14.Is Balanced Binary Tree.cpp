                        //Verifying Whether the given Binary Tree is Balanced or Not

//Method-1: Brute Force
//Time Complexity: O(n²)
//Space Complexity: O(h) where h is the height of the tree
#include<iostream>
#include<algorithm>
#include<cmath>
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
bool IsBalanced(Node* root){
    if(root==nullptr) return true;
    int left=height(root->left);
    int right=height(root->right);
    if(abs(left-right)>1) return false;
    return IsBalanced(root->left) && IsBalanced(root->right);
}
int main(){
   Node* root=new Node(3);
   root->left=new Node(9);
   root->right=new Node(20);
   root->right->left=new Node(15);
   root->right->right=new Node(7);
   if(IsBalanced(root)){
       cout<<"true";
   }
   else{
       cout<<"false";
   }
}


//Method-2: Optimal Solution
//Time Complexity: O(n)
//Space Complexity: O(h)
#include<iostream>
#include<algorithm>
#include<cmath>
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
    int left=height(root->left);
    if(left==-1) return -1;
    int right=height(root->right);
    if(right==-1) return -1;
    if(abs(left-right)>1) return -1;
    return 1+max(left,right);
}
bool IsBalanced(Node* root){
    return height(root) !=-1;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(3);
    root->left->left->left=new Node(4);
    root->left->left->right=new Node(4);
    if(IsBalanced(root)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}
