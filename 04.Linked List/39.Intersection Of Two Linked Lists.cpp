                        //Finding the Intersection Of Two Linked Lists

//Method-1: Brute Force
//Time complexity: O(N + M) where N=Nodes in List1 & M=Nodes in List2
//Space complexity: O(N)
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
Node* ConvertArr2LL(vector<int> arr){
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
Node* IntersectionOfLL(Node* head1,Node* head2){
    map<Node*,int> mpp;
    Node* temp=head1;
    while(temp!=nullptr){
        mpp[temp]=1;
        temp=temp->next;
    }
    temp=head2;
    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end()){
            return temp;
        }
        temp=temp->next;
    }
    return nullptr;
}
int main(){
    vector<int> arr1={1,3,5,8,10};
    vector<int> arr2={6,7};
    Node* head1=ConvertArr2LL(arr1);
    Node* head2=ConvertArr2LL(arr2);
    Node* temp=head1;
    while(temp!=nullptr && temp->data!=8){
        temp=temp->next;
    }
    Node* temp2=head2;
    while(temp2->next!=nullptr){
        temp2=temp2->next;
    }
    temp2->next=temp;
    Node* ans=IntersectionOfLL(head1,head2);
    if(ans!=nullptr)
        cout<<"Intersection at node: "<<ans->data;
    else
        cout<<"No intersection";
}


//Method-2: Better Solution
//Time complexity: O(N + M)
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
Node* ConvertArr2LL(vector<int> arr){
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
Node* intersectionNode(Node* head1,Node* head2,int d){
    Node* t1=head1;
    Node* t2=head2;
    while(d){
        d--;
        t2=t2->next;
    }
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
    }
    return t1;
}
Node* IntersectionOfLL(Node* head1,Node* head2){
    Node* temp=head1;
    int cnt1=0;
    while(temp!=nullptr){
        cnt1++;
        temp=temp->next;
    }
    temp=head2;
    int cnt2=0;
    while(temp!=nullptr){
        cnt2++;
        temp=temp->next;
    }
    if(cnt1<cnt2){
        return intersectionNode(head1,head2,cnt2-cnt1);
    }
    else{
        return intersectionNode(head2,head1,cnt1-cnt2);
    }
}
int main(){
    vector<int> arr1={1,3,5,8,10};
    vector<int> arr2={6,7};
    Node* head1=ConvertArr2LL(arr1);
    Node* head2=ConvertArr2LL(arr2);
    Node* temp=head1;
    while(temp!=nullptr && temp->data!=8){
        temp=temp->next;
    }
    Node* temp2=head2;
    while(temp2->next!=nullptr){
        temp2=temp2->next;
    }
    temp2->next=temp;
    Node* ans=IntersectionOfLL(head1,head2);
    if(ans!=nullptr)
        cout<<"Intersection at node: "<<ans->data;
    else
        cout<<"No intersection";
}


//Method-3: Optimal Solution
//Time complexity: O(N + M)
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
Node* ConvertArr2LL(vector<int> arr){
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
Node* IntersectionOfLL(Node* head1,Node* head2){
    if(head1==nullptr || head2==nullptr) return nullptr;
    Node* temp1=head1;
    Node* temp2=head2;
    while(temp1!=temp2){
        if(temp1==nullptr) temp1=head2;
        else temp1=temp1->next;
        if(temp2==nullptr) temp2=head1;
        else temp2=temp2->next;
    }
    return temp1;
}
int main(){
    vector<int> arr1={1,3,5,8,10};
    vector<int> arr2={6,7};
    Node* head1=ConvertArr2LL(arr1);
    Node* head2=ConvertArr2LL(arr2);
    Node* temp=head1;
    while(temp!=nullptr && temp->data!=8){
        temp=temp->next;
    }
    Node* temp2=head2;
    while(temp2->next!=nullptr){
        temp2=temp2->next;
    }
    temp2->next=temp;
    Node* ans=IntersectionOfLL(head1,head2);
    if(ans!=nullptr)
        cout<<"Intersection at node: "<<ans->data;
    else
        cout<<"No intersection";
}
