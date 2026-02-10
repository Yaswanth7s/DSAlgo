                                           //Searching in Linked list
//Time complexity: Best Case:->O(1)
                 //Average case:->O(n)
                 //Worst Cae:->O(n)
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
Node* convertArr2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
bool SearchinLL(Node* head,int val){
    Node* temp=head;
    while(temp){
        if(temp->data==val){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
int main(){
    vector<int> arr={3,8,2,9};
    Node* head= convertArr2LL(arr);
    int val=13;
    if (SearchinLL(head, val)) {
        cout << "Value found";
    } else {
        cout << "Value not found";
    }
}
