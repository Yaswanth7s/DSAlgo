                            //Deletion Of Nth Node From The End in a Linked List

//Method-1: Brute Force
//Time complexity: O(N)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* ConvertArr2LL(vector<int> arr){
    if(arr.size()==0) return nullptr;
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* DeletionOfNthFromEnd(Node* head,int N){
    Node* temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    if(cnt==N){
        Node* NewHead=head->next;
        delete(head);
        return NewHead;
    }
    int res=cnt-N;
    temp=head;
    while(temp!=nullptr){
        res--;
        if(res==0){
            Node* DelNode=temp->next;
            temp->next=temp->next->next;
            delete(DelNode);
            break;
        }
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
    vector<int> arr={22,4,5412,412,3432,32};
    int N;
    cin>>N;
    Node* head=ConvertArr2LL(arr);
    head=DeletionOfNthFromEnd(head,N);
    print(head);
}


//Method-2: Optimal Solution
//Time complexity: O(N)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* ConvertArr2LL(vector<int> arr){
    if(arr.size()==0) return nullptr;
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* DeletionOfNthFromEnd(Node* head,int N){
    Node* fast=head;
    for(int i=0;i<N;i++){
        if(fast==nullptr) return head;
        fast=fast->next;
    }
    if(fast==nullptr){
        Node* NewHead=head->next;
        delete(head);
        return NewHead;
    }
    Node* slow=head;
    while(fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next;
    }
    Node* DelNode=slow->next;
    slow->next=slow->next->next;
    delete(DelNode);
    return head;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={12,34,5,6,43,2,3,32,12};
    int N;
    cout<<"Enter the value of N: ";
    cin>>N;
    Node* head=ConvertArr2LL(arr);
    head=DeletionOfNthFromEnd(head,N);
    print(head);
}
