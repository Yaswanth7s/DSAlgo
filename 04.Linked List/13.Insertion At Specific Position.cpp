                                      //Type-3: Insertion At Position(Index)
//Time complexity: O(n)
//Space complexity: O(n)

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
Node* convertArr2LL(vector<int> arr){
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
Node* InsertionAtPosition(Node* head,int k,int val){
    if(k<=0){
        return head;
    }
    if(k==1){
        return new Node(val,head);
    }
    Node* temp=head;
    int cnt=1;
    while(temp!=nullptr && cnt<k-1){
        temp=temp->next;
        cnt++;
    }
    if(temp==nullptr) return head;
        Node* newNode=new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
        return head;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={12,34,65,13,34};
    Node* head=convertArr2LL(arr);
    head=InsertionAtPosition(head,6,1);
    print(head);
}
