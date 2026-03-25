                      //Finding all Pairs with given sum in Sorted Doubly Linked List 

//Time complexity: O(n²)
//Space complexity: O(K) where k= number of pairs
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    
    public:
    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
    
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};
Node* ConvertArr2DoublyLL(vector<int> arr){
    if(arr.size()==0) return nullptr;
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        temp->prev=mover;
        mover=temp;
    }
    return head;
}
vector<pair<int,int>> PairsWithGivenSum(Node* head,int sum){
    Node* temp1=head;
    vector<pair<int,int>> result;
    while(temp1!=nullptr){
        Node* temp2=temp1->next;
        while(temp2!=nullptr && temp1->data+temp2->data<=sum){
            if(temp1->data+temp2->data==sum){
                result.push_back({temp1->data,temp2->data});
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return result;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    int sum;
    cout<<"Enter the sum: ";
    cin>>sum;
    Node* head=ConvertArr2DoublyLL(arr);
    vector<pair<int,int>> ans=PairsWithGivenSum(head,sum);
    for(auto it: ans){
        cout<<it.first<<" , "<<it.second<<endl;
    }
}


//Method-2: Optimal Solution
//Time complexity: O(N)
//Space complexity: O(K)
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    
    public:
    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
    
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};
Node* ConvertArr2DoublyLL(vector<int> arr){
    if(arr.size()==0) return nullptr;
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        temp->prev=mover;
        mover=temp;
    }
    return head;
}
Node* findtail(Node* head){
    Node* tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    return tail;
}
vector<pair<int,int>> PairsWithGivenSum(Node* head,int sum){
    vector<pair<int,int>> result;
    Node* left=head;
    Node* right=findtail(head);
    while(left!=right && right->next!=left){
        if(left->data+right->data==sum){
            result.push_back({left->data,right->data});
            left=left->next;
            right=right->prev;
        }
        else if(left->data+right->data<sum){
            left=left->next;
        }
        else{
            right=right->prev;
        }
    }
    return result;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    int sum;
    cout<<"Enter the sum: ";
    cin>>sum;
    Node* head=ConvertArr2DoublyLL(arr);
    vector<pair<int,int>> ans=PairsWithGivenSum(head,sum);
    for(auto it: ans){
        cout<<it.first<<" , "<<it.second<<endl;
    }
}
