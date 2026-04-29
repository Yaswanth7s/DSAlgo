                          //Post Order Traversal (Iterative Method Using 1 Stack)

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
void PostOrderIterative1Stack(Node* root){
    if(root==nullptr) return;
    stack<Node*> st;
    Node* curr=root;
    Node* lastvisited=nullptr;
    while(curr!=nullptr || !st.empty()){
        if(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }
        else{
            Node* temp=st.top();
            if(temp->right!=nullptr && lastvisited!=temp->right){
                curr=temp->right;
            }
            else{
                cout<<temp->data<<" ";
                lastvisited=temp;
                st.pop();
            }
        }
    }
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    PostOrderIterative1Stack(root);
}
