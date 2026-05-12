                                        //ZigZag Level Order Traversal

//Time Complexity: O(n)
//Space Complexity: O(n)
#include<iostream>
#include<queue>
#include<vector>
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
vector<int> zigzagTraversal(Node* root){
    vector<int>result;
    if(root==nullptr) return result;
    queue<Node*> q;
    q.push(root);
    bool LeftToRight=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> level(size);
        for(int i=0;i<size;i++){
            Node* node=q.front();
            q.pop();
            int index;
            if(LeftToRight){
                index=i;
            }
            else{
                index=size-1-i;
            }
            level[index]=node->data;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        for(int val:level){
            result.push_back(val);
        }
        LeftToRight=!LeftToRight;
    }
    return result;
}
int main(){
    Node* root=new Node(3);
    root->left=new Node(9);
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(7);
    vector<int> ans=zigzagTraversal(root);
    for(int x:ans){
        cout<<x<<" ";
    }
}
