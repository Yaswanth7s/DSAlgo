                          //Type-3: Deletion at Specific Position(index Based)
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
Node* DeleteKthPosition(Node* head,int k){
    if(head==nullptr){
        return head;
    }
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;//prev->next=temp->next(for safer reason)
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
    vector<int> arr={12,45,78,3,2};
    Node* head=convertArr2LL(arr);
    head=DeleteKthPosition(head,1);
    print(head);
}
