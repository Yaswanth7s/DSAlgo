                              //Deleting the Middle Node Of a Linked List

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
Node* DeleteMiddleNodeOfLL(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;
    Node* temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    int res=cnt/2;
    temp=head;
    while(temp!=nullptr){
        res--;
        if(res==0){
            Node* middle=temp->next;
            temp->next=temp->next->next;
            delete(middle);
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
    vector<int> arr={223,4,5,2,4,12,565,543};
    Node* head=ConvertArr2LL(arr);
    head=DeleteMiddleNodeOfLL(head);
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
Node* DeleteMiddleNodeOfLL(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;
    Node* slow=head;
    Node* fast=head;
    fast=fast->next->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* middle=slow->next;
    slow->next=slow->next->next;
    delete(middle);
    return head;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={3,4,21,4,12,412,12,1132,5};
    Node* head=ConvertArr2LL(arr);
    head=DeleteMiddleNodeOfLL(head);
    print(head);
}
