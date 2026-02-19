                            //Type-3: Insertion At Position(Before Index) in Doubly Linked List
//Time complexity: O(n)
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
    Node* newhead=new Node(val,head,nullptr);
    if(head!=nullptr){
        head->back=newhead;
    }
    return newhead;
}
Node* InsertionBeforeKthPosition(Node* head,int val,int pos){
    if(pos==1){
        return InsertionBeforeHead(head,val);
    }
    Node* temp=head;
    int cnt=1;
    while(temp!=nullptr && cnt<pos){
        temp=temp->next;
        cnt++;
    }
    if(temp==nullptr){
        cout<<"Invalid position"<<endl;
        return head;
    }
    Node* prev=temp->back;
    Node* newNode=new Node(val,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={21,43,6,12,54};
    Node* head=ConvertArr2DoublyLL(arr);
    head=InsertionBeforeKthPosition(head,10,5);
    print(head);
}
