                        //Deleting All The Occurences Of an Element in a Doubly Linked List

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
Node* DeleteOccurencesOfAKey(Node* head,int key){
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==key){
            if(temp==head){
                head=head->next;
                if(head!=nullptr) head->prev=nullptr;
            }
            Node* nextNode=temp->next;
            Node* prevNode=temp->prev;
            if(nextNode!=nullptr) nextNode->prev=prevNode;
            if(prevNode!=nullptr) prevNode->next=nextNode;
            delete(temp);
            temp=nextNode;
        }
        else{
            temp=temp->next;
        }
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
    vector<int> arr={1,3,1,6,7,1,2};
    int key;
    cout<<"Enter the value of key: ";
    cin>>key;
    Node* head=ConvertArr2DoublyLL(arr);
    head=DeleteOccurencesOfAKey(head,key);
    print(head);
}
