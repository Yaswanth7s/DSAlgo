                                //Finding the Maximum Path Sum in a Binary Tree

//Time Complexity: O(n)
//Space Complexity: O(h) where h is the height of the tree
#include<iostream>
#include<algorithm>
#include<climits>
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
int maxi=INT_MIN;
int MaxPathSum(Node* root){
    if(root==nullptr) return 0;
    int leftsum=max(0,MaxPathSum(root->left));
    int rightsum=max(0,MaxPathSum(root->right));
    maxi=max(maxi,root->data+leftsum+rightsum);
    return root->data+max(leftsum,rightsum);
}
int main(){
    Node* root=new Node(-10);
    root->left=new Node(9);
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(7);
    MaxPathSum(root);
    cout<<"Maximum Path Sum is: "<<maxi;
}
