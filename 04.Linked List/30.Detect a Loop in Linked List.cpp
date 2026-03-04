                                  //Detecting a loop in a Linked List

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
bool DetectionOfLoop(Node* head){
    Node* temp=head;
    map<Node*,int> mpp;
    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end()){
            return true;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
    return false;
}
int main(){
    vector<int> arr={23,2,12,4,3,4,12};
    Node* head=ConvertArr2LL(arr);
    // Creation of loop manually
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = head->next;  // last node points to second node
    if(DetectionOfLoop(head)){
        cout<<"Loop Detected";
    } else {
        cout<<"No Loop";
    }
}


//Method-2: Optimal Solution [Using Tortoise & Hare]
//Time coplexity: O(N)
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
bool DetectionOfLoop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
int main(){
    vector<int> arr={21,34,12,6,2,86};
    Node* head=ConvertArr2LL(arr);
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=head->next;
    if(DetectionOfLoop(head)){
        cout<<"Loop Detected";
    }
    else{
        cout<<"No Loop";
    }
}
