                        //Sorting a Linked List Of 0's,1's and 2's

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
Node* SortingLL(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* temp=head;
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    while(temp!=nullptr){
        if(temp->data==0) cnt0++;
        else if(temp->data==1) cnt1++;
        else cnt2++;
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        if(cnt0){
            temp->data=0;
            cnt0--;
        }
        else if(cnt1){
            temp->data=1;
            cnt1--;
        }
        else{
            temp->data=2;
            cnt2--;
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
    vector<int> arr={2,1,0,0,2,1,2};
    Node* head=ConvertArr2LL(arr);
    head=SortingLL(head);
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
Node* SortingLL(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* zerohead=new Node(-1);
    Node* onehead=new Node(-1);
    Node* twohead=new Node(-1);
    Node* zero=zerohead;
    Node* one=onehead;
    Node* two=twohead;
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==0){
            zero->next=temp;
            zero=temp;
        }
        else if(temp->data==1){
            one->next=temp;
            one=temp;
        }
        else{
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }
    zero->next=(onehead->next)?onehead->next:twohead->next;
    one->next=twohead->next;
    two->next=nullptr;
    Node* NewHead=zerohead->next;
    delete zerohead;
    delete onehead;
    delete twohead;
    return NewHead;
}
void print(Node* NewHead){
    while(NewHead!=nullptr){
        cout<<NewHead->data<<" ";
        NewHead=NewHead->next;
    }
}
int main(){
    vector<int> arr={1,0,2,0,1,2,1};
    Node* head=ConvertArr2LL(arr);
    Node* NewHead=SortingLL(head);
    print(NewHead);
}
