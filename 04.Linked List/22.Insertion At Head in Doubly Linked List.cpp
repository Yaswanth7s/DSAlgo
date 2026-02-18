                      //Type-1: Insertion at Beginning(Before Head Node) in Doubly Linked List
//Time complexity: O(1)
//Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    
    public:
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
Node* ConvertArr2DoublyLL(vector<int> arr){
    if(arr.size()==0) return nullptr;
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        prev->next=temp;
        temp->back=prev;
        prev=temp;
    }
    return head;
}
Node* InsertionBeforeHead(Node* head,int val){
    Node* NewHead=new Node(val,head,nullptr);
    if(head!=nullptr){
        head->back=NewHead;
    }
    return NewHead;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={};
    Node* head=ConvertArr2DoublyLL(arr);
    head=InsertionBeforeHead(head,10);
    print(head);
}
