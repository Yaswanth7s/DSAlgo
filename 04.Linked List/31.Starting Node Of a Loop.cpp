                                  //Finding The Starting Node Of the Loop/Cycle

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
Node* StartingNodeOfLoop(Node* head){
    Node* temp=head;
    map<Node*,int> mpp;
    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end()){
            return temp;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
    return nullptr;
}
int main(){
    vector<int> arr={12,34,4,56,7,12};
    Node* head=ConvertArr2LL(arr);
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=head->next;
    Node* start=StartingNodeOfLoop(head);
    if(start!=nullptr){
        cout<<"Starting Node of Loop is: "<<start->data;
    }
    else{
        cout<<"No loop";
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
Node* StartingNodeOfLoop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return fast;
        }
    }
    return nullptr;
}
int main(){
    vector<int> arr={2,34,54,6,7,89,32};
    Node* head=ConvertArr2LL(arr);
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=head->next->next;
    Node* start=StartingNodeOfLoop(head);
    if(start!=nullptr){
        cout<<"Starting Point of Loop/Cycle is: "<<start->data;
    }
    else{
        cout<<"No Loop";
    }
}
