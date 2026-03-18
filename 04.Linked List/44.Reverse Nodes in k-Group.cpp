                              //Reversing Nodes in K-Groups in a Linked list

//Method-1:Optimal Solution
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
Node* ReverseLL(Node* temp){
    Node* prev=nullptr;
    while(temp!=nullptr){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
Node* findKthNode(Node* temp,int k){
    k-=1;
    while(temp!=nullptr && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}
Node* KReverse(Node* head,int k){
    Node* temp=head;
    Node* prevNode=nullptr;
    while(temp!=nullptr){
        Node* KthNode=findKthNode(temp,k);
        if(KthNode==nullptr){
            if(prevNode){
                prevNode->next=temp;
            }
            break;
        }
        Node* nextNode=KthNode->next;
        KthNode->next=nullptr;
        Node* newHead=ReverseLL(temp);
        if(temp==head){
            head=newHead;
        }
        else{
            prevNode->next=newHead;
        }
        prevNode=temp;
        temp=nextNode;
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
    vector<int> arr={12,34,12,34,1,3,7,53,2,11234,32};
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    Node* head=ConvertArr2LL(arr);
    head=KReverse(head,k);
    print(head);
}
