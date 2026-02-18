                //Type-4: Case:2:-> Deletion By Element(Value)[With Duplicates] in Doubly Linked List
//Time complexity: O(n)
//Space complexity: O(1)

#include<bits/stdc++.h>
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
Node* DeleteNodeByValue(Node* head,int val){
    if(head==nullptr) return nullptr;
    Node* temp=head;
    while(temp!=nullptr){
        Node* nextNode=temp->next;
        if(temp->data==val){
        Node* prev=temp->back;
        Node* front=temp->next;
        if(prev==nullptr && front==nullptr){
            delete temp;
            return nullptr;
        }
        else if(prev==nullptr){
            head=front;
            if(front!=nullptr)
                front->back=nullptr;
            delete temp;
        }
        else if(front==nullptr){
            prev->next=nullptr;
            temp->back=nullptr;
            delete temp;
        }
        else{
        prev->next=front;
        front->back=prev;
        temp->next=nullptr;
        temp->back=nullptr;
        delete temp;
        }
    }
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
    vector<int> arr={12,34,12,6787,5432,12,2};
    Node* head=ConvertArr2DoublyLL(arr);
    head=DeleteNodeByValue(head,12);
    print(head);
}
