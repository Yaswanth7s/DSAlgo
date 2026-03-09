                              //Segregating Odd And Even Nodes in Linked List

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
Node* OddEvenLinkedList(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    vector<int> arr;
    Node* temp=head;
    while(temp!=nullptr && temp->next!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    temp=head->next;
    while(temp!=nullptr && temp->next!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    int i=0;
    temp=head;
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
    vector<int> arr={21,34,1,4,12,34,12};
    Node* head=ConvertArr2LL(arr);
    head=OddEvenLinkedList(head);
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
Node* OddEvenLinkedList(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* Odd=head;
    Node* Even=head->next;
    Node* EvenHead=head->next;
    while(Even!=nullptr && Even->next!=nullptr){
        Odd->next=Odd->next->next;
        Even->next=Even->next->next;
        Odd=Odd->next;
        Even=Even->next;
    }
    Odd->next=EvenHead;
    return head;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={12,4,56,5,32,4,2};
    Node* head=ConvertArr2LL(arr);
    head=OddEvenLinkedList(head);
    print(head);
}
