                                    //In Order Traversal (Iterative Method)

//Time Complexity: O(n) 
//Space Complexity: O(h) where h is the height of the tree
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
void InOrderIterative(Node* root){
    if(root==nullptr) return;
    stack<Node*> st;
    Node* curr=root;
    while(curr!=nullptr || !st.empty()){
        if(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }
        else{
            curr=st.top();
            st.pop();
            cout<<curr->data<<" ";
            curr=curr->right;
        }
    }
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(6);
    root->left->right->right=new Node(7);
    InOrderIterative(root);
}
