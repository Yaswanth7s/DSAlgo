                                    //Add Two Numbers Using Linked List

//Method-1: Optimal Solution                                    
//Time complexity: O(max(N, M)) where N=Length of Linked List l1 and
                                  //  M=Length of Linked List l2
//Space complexity: O(max(N, M))                                       

#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* ConvertArr2LL(vector<int> arr){
    if(arr.size() == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
Node* addTwoNumbers(Node* l1, Node* l2){
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    Node* temp1 = l1;
    Node* temp2 = l2;
    int carry = 0;
    while(temp1 != nullptr || temp2 != nullptr){
        int sum = carry;
        if(temp1) sum += temp1->data;
        if(temp2) sum += temp2->data;
        carry = sum / 10;
        Node* newNode = new Node(sum % 10);
        curr->next = newNode;
        curr = curr->next;
        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    if(carry){
        curr->next = new Node(carry);
    }
    return dummyNode->next;
}
void print(Node* head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main(){
    vector<int> arr1 = {2,4,3};
    vector<int> arr2 = {5,6,4};
    Node* l1 = ConvertArr2LL(arr1);
    Node* l2 = ConvertArr2LL(arr2);
    Node* result = addTwoNumbers(l1, l2);
    print(result);
}
