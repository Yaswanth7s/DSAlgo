                              //Pre Order Traversal (Iterative Method)

//Time Complexity: O(n)
//Space Complexity: O(n)
#include<iostream>
#include<stack>
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
void preorderIterative(Node* root){
    if(root==nullptr) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* curr=st.top();
        st.pop();
        cout<<curr->data<<" ";
        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
    }
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(7);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->left->right->left=new Node(5);
    root->left->right->right=new Node(6);
    preorderIterative(root);
}
