                            //Type-4: Case:1:-> Deletion By Element(Value)[No Duplicates]
//Time complexity: O(n)
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
Node* convertArr2LL(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* RemoveElement(Node* head,int value){
    if(head==nullptr){
        return head;
    }
    if(head->data==value){
        Node* temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=nullptr){
        if(temp->data==value){
            prev->next=temp->next;//prev->next=prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
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
    vector<int> arr={12,13,5654,374,12};
    Node* head=convertArr2LL(arr);
    head=RemoveElement(head,12);
    print(head);
}
