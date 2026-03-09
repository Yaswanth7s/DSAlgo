                            //Finding the Length Of THe Loop in a Linked List

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
int LengthOfTheLoop(Node* head){
    Node* temp=head;
    int timer=1;
    map<Node*,int> mpp;
    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end()){
            int value=mpp[temp];
            return timer-value;
        }
        mpp[temp]=timer;
        timer++;
        temp=temp->next;
    }
    return 0;
}
int main(){
    vector<int> arr={212,34,12,34,21,4,4};
    Node* head=ConvertArr2LL(arr);
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=head->next->next;
    int Length=LengthOfTheLoop(head);
        cout<<"Length of the loop is: "<<Length;
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
    Node* head=new Node( arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
int LengthOfTheLoop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            int cnt=1;
            fast=fast->next;
            while(slow!=fast){
                cnt++;
                fast=fast->next;
            }
            return cnt;
        }
    }
    return 0;
}
int main(){
    vector<int> arr={32,212,3,342,112,34,12,2};
    Node* head=ConvertArr2LL(arr);
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=head->next;
    int Length=LengthOfTheLoop(head);
    cout<<"Length of the Loop is: "<<Length;
}
