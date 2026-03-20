                                    //Flattening a Linked List
    
//Method-1: Brute Force
//Time complexity: O(N log N)
//Space complexity: O(N)
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* child;
    
    public:
    Node(int data1,Node* next1,Node* child1){
        data=data1;
        next=next1;
        child=child1;
    }
    
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        child=nullptr;
    }
};
Node* ConvertArr2FlattenLL(vector<int> arr){
    if(arr.size()==0) return nullptr;
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->child=temp;
        mover=temp;
    }
    return head;
}
Node* flattenLL(Node* head){
    vector<int> arr;
    Node* temp1=head;
    while(temp1!=nullptr){
        Node* temp2=temp1;
        while(temp2!=nullptr){
            arr.push_back(temp2->data);
            temp2=temp2->child;
        }
        temp1=temp1->next;
    }
    sort(arr.begin(),arr.end());
    return ConvertArr2FlattenLL(arr);
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->child;
    }
}
int main(){
    Node* head = new Node(5);
    head->child = new Node(7);
    head->child->child = new Node(8);
    head->next = new Node(6);
    head->next->child = new Node(9);
    Node* flat = flattenLL(head);
    print(flat);
}


//Method-2: Optimal Solution
//Time complexity: O(N)
//Space complexity: O(N)
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* child;
    
    public:
    Node(int data1,Node* next1,Node* child1){
        data=data1;
        next=next1;
        child=child1;
    }
    
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        child=nullptr;
    }
};
Node* merge2LL(Node* list1,Node* list2){
    Node* dummyNode=new Node(-1);
    Node* res=dummyNode;
    while(list1!=nullptr && list2!=nullptr){
        if(list1->data<list2->data){
            res->child=list1;
            res=list1;
            list1=list1->child;
        }
        else{
            res->child=list2;
            res=list2;
            list2=list2->child;
        }
        res->next=nullptr;
    }
    if(list1) res->child=list1;
    else res->child=list2;
    if(dummyNode->child) dummyNode->child->next=nullptr;
    return dummyNode->child;
}
Node* FlattenLL(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* mergedhead=FlattenLL(head->next);
    head=merge2LL(head,mergedhead);
    return head;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->child;
    }
}
int main(){
    Node* head = new Node(5);
    head->child = new Node(7);
    head->child->child = new Node(8);
    head->next = new Node(6);
    head->next->child = new Node(9);
    Node* flat = FlattenLL(head);
    print(flat);
}
