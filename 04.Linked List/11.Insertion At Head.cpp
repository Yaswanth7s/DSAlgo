                                            //Insertions in Linked List
                                    //Type-1: Insertion at Beginning(Head Node)
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
    Node* head=new  Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* InsertionAtHead(Node* head,int val){
    Node* temp=new Node(val,head);
    return temp;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    vector<int> arr={332,34,23,54,432};
    Node* head=convertArr2LL(arr);
    head=InsertionAtHead(head,1);
    print(head);
}
