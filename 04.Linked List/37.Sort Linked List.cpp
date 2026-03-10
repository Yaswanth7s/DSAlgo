                                    //Sorting the Linked List

//Method-1: Brute Force
//Time complexity: O(N log N)
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
Node* SortingLL(Node* head){
    vector<int> arr={};
    Node* temp=head;
    while(temp!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    int n=arr.size();
    sort(arr.begin(),arr.end());
    temp=head;
    int i=0;
    while(temp!=nullptr){
        temp->data=arr[i];
        i++;
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
    vector<int> arr={312,32,1,34,5,43};
    Node* head=ConvertArr2LL(arr);
    head=SortingLL(head);
    print(head);
}


//Method-2: Optimal Solution
//Time complexity: O(N log N)
//Space complexity: O(log N)
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
Node* findmid(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node* mergetwosortedLL(Node* list1,Node* list2){
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    while(list1!=nullptr && list2!=nullptr){
        if(list1->data<list2->data){
            temp->next=list1;
            list1=list1->next;
        }
        else{
            temp->next=list2;
            list2=list2->next;
        }
        temp=temp->next;
    }
    if(list1) temp->next=list1;
    else temp->next=list2;
    return dummyNode->next;
}
Node* SortingLL(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* mid=findmid(head);
    Node* right=mid->next;
    mid->next=nullptr;
    Node* left=head;
    left=SortingLL(left);
    right=SortingLL(right);
    return mergetwosortedLL(left,right);
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={23,4,12,34,1,4231,241};
    Node* head=ConvertArr2LL(arr);
    head=SortingLL(head);
    print(head);
}
