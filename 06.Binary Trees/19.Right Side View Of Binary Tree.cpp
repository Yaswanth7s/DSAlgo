                            //Right Side View Of Binary Tree

//Time Complexity: O(n)
//Space Complexity: O(h) where h is the height of the tree
#include<iostream>
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
void recursion(Node* root,int level,vector<int>& ans){
    if(root==nullptr) return;
    if(level==ans.size()) ans.push_back(root->data);
    recursion(root->right,level+1,ans);
    recursion(root->left,level+1,ans);
}
vector<int> RightSideView(Node* root){
    vector<int> ans;
    recursion(root,0,ans);
    return ans;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->right->right=new Node(4);
    vector<int> result=RightSideView(root);
    for(int x:result){
        cout<<x<<" ";
    }
}
