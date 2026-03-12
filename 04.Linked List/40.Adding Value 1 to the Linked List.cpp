                            //Adding value 1 to the Linked List

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
Node* ReverseLL(Node* head){
    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=nullptr){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
Node* Adding1ToLL(Node* head){
    head=ReverseLL(head);
    Node* temp=head;
    int carry=1;
    while(temp!=nullptr){
        temp->data=temp->data+carry;
        if(temp->data<10){
            carry=0;
            break;
        }
        else{
            temp->data=0;
            carry=1;
        }
        temp=temp->next;
    }
    if(carry==1){
        Node* NewNode=new Node(1);
        head=ReverseLL(head);
        NewNode->next=head;
        return NewNode;
    }
    else{
        head=ReverseLL(head);
        return head;
    }
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={9,9,9,9};
    Node* head=ConvertArr2LL(arr);
    head=Adding1ToLL(head);
    print(head);
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
int helper(Node* head){
    Node* temp=head;
    if(temp==nullptr) return 1;
    int carry=helper(temp->next);
    temp->data=temp->data+carry;
    if(temp->data<10){
        return 0;
    }
    temp->data=0;
    return 1;
}
Node* Adding1ToLL(Node* head){
    int carry=helper(head);
    if(carry){
        Node* NewNode=new Node(1);
        NewNode->next=head;
        return NewNode;
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
    vector<int> arr={1,5,8};
    Node* head=ConvertArr2LL(arr);
    head=Adding1ToLL(head);
    print(head);
}
