                                  //Type 2: Deletion at End(Tail Node)
//Time complexity: O(n)
//Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node (int data1,Node* next1){
        data=data1;
        next=next1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* converArr2LL(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* DeleteTail(Node* head){
    if(head==nullptr){
        return nullptr;
    }
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=nullptr;
    return head;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    vector<int> arr={6,592,35,86};
    Node* head=converArr2LL(arr);
    head=DeleteTail(head);
    print(head);
}
