                        //Clone a Linked List with Random And Next Pointers

//Method-1: Brute Force
//Time complexity: O(N log N)
//Space complexity: O(N)
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* random;
    
    public:
    Node(int data1,Node* next1,Node* random1){
        data=data1;
        next=next1;
        random=random1;
    }
    
    public:
    Node( int data1){
        data=data1;
        next=nullptr;
        random=nullptr;
    }
};
Node* CloneALLWithRandomPointer(Node* head){
    Node* temp=head;
    map<Node* ,Node*> mpp;
    while(temp!=nullptr){
        Node* newNode=new Node(temp->data);
        mpp[temp]=newNode;
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        Node* copyNode=mpp[temp];
        copyNode->next=mpp[temp->next] ? mpp[temp->next] : nullptr;
        copyNode->random=mpp[temp->random] ? mpp[temp->random] : nullptr;
        temp=temp->next;
    }
    return mpp[head];
}
void printList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << "Data: " << temp->data;
        if(temp->random)
            cout << ", Random: " << temp->random->data;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }
}
int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    head->next = second;
    second->next = third;
    third->next = fourth;
    head->random = third; 
    second->random = head;    
    third->random = fourth;    
    fourth->random = second;   
    cout << "Original List:\n";
    printList(head);
    Node* clonedHead = CloneALLWithRandomPointer(head);
    cout << "\nCloned List:\n";
    printList(clonedHead);
    return 0;
}


//Method-2: Optimal Solution
//Time complexity: O(N)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* random;
    
    public:
    Node(int data1,Node* next1,Node* random1){
        data=data1;
        next=next1;
        random=random1;
    }
    
    public:
    Node( int data1){
        data=data1;
        next=nullptr;
        random=nullptr;
    }
};
Node* CloneALLWithRandomPointer(Node* head){
    Node* temp=head;
    Node* copyNode;
    while(temp!=nullptr){
        copyNode=new Node(temp->data);
        copyNode->next=temp->next;
        temp->next=copyNode;
        temp=temp->next->next;
    }
    temp=head;
    while(temp!=nullptr){
        copyNode=temp->next;
        if(temp->random){
            copyNode->random=temp->random->next;
        }
        else{
            copyNode->random=nullptr;
        }
        temp=temp->next->next;
    }
    temp=head;
    Node* dummyNode=new Node(-1);
    Node* res=dummyNode;
    while(temp!=nullptr){
        res->next=temp->next;
        res=res->next;
        temp->next=temp->next->next;
        temp=temp->next;
    }
    return dummyNode->next;
}
void printList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << "Data: " << temp->data;
        if(temp->random)
            cout << ", Random: " << temp->random->data;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }
}
int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    head->next = second;
    second->next = third;
    third->next = fourth;
    head->random = third; 
    second->random = head;     
    third->random = fourth;    
    fourth->random = second; 
    cout << "Original List:\n";
    printList(head);
    Node* clonedHead = CloneALLWithRandomPointer(head);
    cout << "\nCloned List:\n";
    printList(clonedHead);
    return 0;
}
