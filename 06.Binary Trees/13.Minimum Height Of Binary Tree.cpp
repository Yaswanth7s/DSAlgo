                              //Finding the Minimum Depth/Height Of Binary Tree

//Method-1: Using Recursion
//Time Complexity: O(n)
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
int MinDepthOfTree(Node* root){
    if(root==nullptr) return 0;
    if(root->left==nullptr){
        return 1+MinDepthOfTree(root->right);
    }
    if(root->right==nullptr){
        return 1+MinDepthOfTree(root->left);
    }
    return 1+min(MinDepthOfTree(root->left),MinDepthOfTree(root->right));
}
int main(){
   Node* root=new Node(1);
   root->left=new Node(2);
   root->right=new Node(3);
   root->right->left=new Node(4);
   root->right->right=new Node(6);
   root->right->left->left=new Node(5);
   int result=MinDepthOfTree(root);
   cout<<"Minimum Depth Of the Tree is: "<<result<<endl;
}


//Method-2: Using Iterative
//Time Complexity: O(n)
//Space Complexity: O(n)
#include<iostream>
#include<queue>
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
int MinDepthOfTree(Node* root){
    if(root==nullptr) return 0;
    queue<Node*> q;
    q.push(root);
    int depth=1;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(!temp->left && !temp->right){
                return depth;
            }
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        depth++;
    }
    return depth;
}
int main(){
   Node* root=new Node(1);
   root->left=new Node(2);
   root->right=new Node(3);
   root->right->left=new Node(4);
   root->right->right=new Node(6);
   root->right->left->left=new Node(5);
   int result=MinDepthOfTree(root);
   cout<<"Minimum Depth Of the Tree is: "<<result<<endl;
}
