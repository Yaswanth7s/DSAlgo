                                        //Diameter Of Binary Tree

//Method-1: Brute Force
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
int diameter(Node* root){
    if(root==nullptr) return 0;
    int left=height(root->left);
    int right=height(root->right);
    int diathroughroot=left+right;
    int leftdia=diameter(root->left);
    int rightdia=diameter(root->right);
    return max(diathroughroot,max(leftdia,rightdia));
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    int result=diameter(root);
    cout<<"Diameter of Binary Tree is: "<<result;
}


//Method-2: Optimal Solution
//Time Complexity: O(n)
//Space Complexity: O(h)
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
int dia=0;
int height(Node* root){
    if(root==nullptr) return 0;
    int left=height(root->left);
    int right=height(root->right);
    dia=max(dia,left+right);
    return 1+max(left,right);
}
int diameter(Node* root){
    height(root);
    return dia;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    int result=diameter(root);
    cout<<"Diameter of Binary Tree is: "<<result;
}
