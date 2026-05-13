                            //Vertical Order Traversal Of a Binary Tree
                            
//Time Complexity: O(n log n)
//Space Complexity: O(n)
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
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

vector<vector<int>> VerticalOrder(Node* root){
    vector<vector<int>>ans;
    if(root==nullptr) return ans;
    map<int,map<int,multiset<int>>> nodes;
    queue<pair<Node*,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        Node* temp=p.first;
        int x=p.second.first;
        int y=p.second.second;
        nodes[x][y].insert(temp->data);
        if(temp->left){
            q.push({temp->left,{x-1,y+1}});
        }
        if(temp->right){
            q.push({temp->right,{x+1,y+1}});
        }
    }
    for (auto a:nodes){
        vector<int>col;
        for(auto b:a.second){
            col.insert(col.end(),b.second.begin(),b.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
int main(){
    Node* root=new Node(3);
    root->left=new Node(9);
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(7);
    vector<vector<int>> result=VerticalOrder(root);
    for(auto col:result){
        for(auto val:col){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}
