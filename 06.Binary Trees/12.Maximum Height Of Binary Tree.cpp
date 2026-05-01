                            //Finding the Maximum Height/Depth Of a Tree 

//Method-1: Using Recursion
//Time Complexity: O(n)
//Space Complexity: O(h) where h is the height of a tree
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
int HeightOfTree(Node* root){
    if(root==nullptr) return 0;
    return 1+max(HeightOfTree(root->left),HeightOfTree(root->right));
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->left=new Node(4);
    root->right->right=new Node(6);
    root->right->left->left=new Node(5);
    int result=HeightOfTree(root);
    cout<<"Height of the Tree is: "<<result<<endl;
}


//Method-2: Using Iteration
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
int HeightOfTree(Node* root){
    if(root==nullptr) return 0;
    queue<Node*> q;
    int height=0;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        height++;
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return height;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->left=new Node(4);
    root->right->right=new Node(6);
    root->right->left->left=new Node(5);
    int result=HeightOfTree(root);
    cout<<"Height of the tree is: "<<result<<endl;
}
