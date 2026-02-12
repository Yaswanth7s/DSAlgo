                                    //Type-4: Insertion Before A Value
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
Node* convertArr2LL(vector<int>arr){
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
Node* InsertionBeforeValue(Node* head,int presentvalue,int insertingvalue){
    if(head==nullptr){
        return nullptr;
    }
    if(head->data==presentvalue){
        return new Node(insertingvalue,head);
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        if(temp->next->data==presentvalue){
            Node* newNode=new Node(insertingvalue,temp->next);
            temp->next=newNode;
            break;
        }
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
    vector<int> arr={13,32,53,354};
    Node* head=convertArr2LL(arr);
    head=InsertionBeforeValue(head,53,52);
    print(head);
    
}
