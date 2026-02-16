                                      //Type 2: Deletion at End(Tail Node)
//Time complexity: O(n)
//Space complexity: O(n)

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    
    public:
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
Node* ConvertArr2DLL(vector<int> arr){
    if(arr.empty()) return nullptr;
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        prev->next=temp;
        temp->back=prev;
        prev=temp;
    }
    return head;
}
Node* DeleteTail(Node* head){
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    Node* tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    Node* newTail=tail->back;
    newTail->next=nullptr;
    tail->back=nullptr;
    delete tail;
    return head;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={231,34,12,6};
    Node* head=ConvertArr2DLL(arr);
    head=DeleteTail(head);
    print(head);
}


