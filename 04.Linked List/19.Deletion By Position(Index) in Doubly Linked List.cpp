                    //Type-3: Deletion at Specific Position(index Based) in Doubly Linked List
//Time complexity: O(n)
//Space complexity: O(1)

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
Node* ConvertArr2DoublyLL(vector<int> arr){
    if(arr.size()==0) return nullptr;
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
Node* Deletehead(Node* head){
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
        Node* prev=head;
        head=head->next;
        head->back=nullptr;
        prev->next=nullptr;
        delete prev;
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
    Node* NewTail=tail->back;
    NewTail->next=nullptr;
    tail->back=nullptr;
    delete tail;
    return head;
}
Node* DeleteKthPosition(Node* head,int k){
    if(head==nullptr) return nullptr;
    int cnt=0;
    Node* KthNode=head;
    while(KthNode!=nullptr){
        cnt++;
        if(cnt==k)break;
        KthNode=KthNode->next;
    }
    Node* prev=KthNode->back;
    Node* front=KthNode->next;
    if(prev==nullptr && front==nullptr){
        delete KthNode;
        return nullptr;
    }
    else if(prev==nullptr){
        return Deletehead(head);
    }
    else if(front==nullptr){
        return DeleteTail(head);
    }
    prev->next=front;
    front->back=prev;
    KthNode->next=nullptr;
    KthNode->back=nullptr;
    delete KthNode;
    return head;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={231,34,132,54,34};
    Node* head=ConvertArr2DoublyLL(arr);
    head=DeleteKthPosition(head,5);
    print(head);
}
