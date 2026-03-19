                                //Right Rotation of Linked List By K Places
                                
//Method-1: Optimal Solution
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
Node* findNewTail(Node* temp,int k){
    int cnt=1;
    while(temp!=nullptr && cnt<k){
        cnt++;
        temp=temp->next;
    }
    return temp;
}
Node* RightRotateLLByKPositions(Node* head,int k){
    if(head==nullptr || k==0) return head;
    Node* tail=head;
    int len=1;
    while(tail->next!=nullptr){
        len++;
        tail=tail->next;
    }
    k=k%len;
    if(k==0) return head;
    tail->next=head;
    Node* newTail=findNewTail(head,len-k);
    head=newTail->next;
    newTail->next=nullptr;
    return head;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={2,3,12,41,12,4,12,32};
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    Node* head=ConvertArr2LL(arr);
    head=RightRotateLLByKPositions(head,k);
    print(head);
}
