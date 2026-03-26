                              //Removing Duplicates from the Sorted Doubly Linked List

//Method-1: Optimal Solution
//Time complexity: O(N)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    
    public:
    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
    
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};
Node* ConvertArr2DoublyLL(vector<int> arr){
    if(arr.size()==0) return nullptr;
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        temp->prev=mover;
        mover=temp;
    }
    return head;
}
Node* RemovingDuplicatesFromSortedDoublyLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr && temp->next!=nullptr){
        Node* nextNode=temp->next;
        while(nextNode!=nullptr && nextNode->data==temp->data){
            Node* duplicate=nextNode;
            nextNode=nextNode->next;
            delete(duplicate);
        }
        temp->next=nextNode;
        if(nextNode) nextNode->prev=temp;
        temp=temp->next;
    }
    return head;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={1,1,1,2,3,4,4,4,5,5,6};
    Node* head=ConvertArr2DoublyLL(arr);
    head=RemovingDuplicatesFromSortedDoublyLL(head);
    print(head);
}
