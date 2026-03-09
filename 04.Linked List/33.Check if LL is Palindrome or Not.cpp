                          //Checking Whether the Linked List is Palindrome Or Not

//Method-1: Brute Force
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
bool IsLinkedListPalindrome(Node* head){
    stack<int> st;
    Node* temp=head;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        if(temp->data!=st.top()) return false;
        temp=temp->next;
        st.pop();
    }
    return true;
}
int main(){
    vector<int> arr={1,2,3,2,1,4};
    Node* head=ConvertArr2LL(arr);
    bool ans=IsLinkedListPalindrome(head);
    if(ans){
        cout<<"Linked List is Palindrome";
    }
    else{
        cout<<"Linked List is not Palindrome";
    }
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
Node* reverseLL(Node* head){
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
bool IsLinkedListPalindrome(Node* head){
    if(head==nullptr || head->next==nullptr) return true;
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* NewHead=reverseLL(slow->next);
    Node* first=head;
    Node* second=NewHead;
    while(second!=nullptr){
        if(first->data!=second->data){
            reverseLL(NewHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverseLL(NewHead);
    return true;
}
int main(){
    vector<int> arr={1,2,3,4,3,2,1};
    Node* head=ConvertArr2LL(arr);
    bool ans=IsLinkedListPalindrome(head);
    if(ans){
        cout<<"Linked List is Palindrome";
    }
    else{
        cout<<"Linked List is not Palindrome";
    }
}
