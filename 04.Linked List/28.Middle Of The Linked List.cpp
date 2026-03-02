                              //Finding the Middle Element in a Linked list
//Method-1: Brute Force
//Time complexity: O(n+(n/2))
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
    if(arr.size()==0){
        return nullptr;
    }
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* MiddleElementOfLL(Node* head){
    Node* temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    int MidNode=(cnt/2)+1;
    temp=head;
    while(temp!=nullptr){
        MidNode=MidNode-1;
        if(MidNode==0){
            break;
        }
        temp=temp->next;
    }
    return temp;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={32,34,1,11,54};
    Node* head=ConvertArr2LL(arr);
    Node* temp=MiddleElementOfLL(head);
    print(temp);
}


//Method-2: Optimal Solution [Using Tortoise & Hare]
//Time complexity: O(n)
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
Node* MiddleElementOfLL(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={32,12,5,1,56,12};
    Node* head=ConvertArr2LL(arr);
    Node* mid=MiddleElementOfLL(head);
    print(mid);
}
