                                //Implementation of Stack Using Linked List
/*Time complexities:    01.For Push  :   O(1)
                        02.For Pop   :   O(1)
                        03.For top   :   O(1)
                        04.For size():   O(1)
  Space complexity : O(n)
*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
class LinkedListStack{
    private:
    Node* head;
    int sz;
    
    public:
    LinkedListStack(){
        head=nullptr;
        sz=0;
    }
    
    void push(int x){
        Node* temp=new Node(x);
        temp->next=head;
        head=temp;
        sz++;
    }
    
    int pop(){
        if(head==nullptr) return -1;
        int poppingval=head->data;
        Node* temp=head;
        head=head->next;
        delete temp;
        sz--;
        return poppingval;
    }
    int top(){
        if(head==nullptr) return -1;
        return head->data;
    }
    int size(){
        return sz;
    }
};
int main(){
    LinkedListStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.top() << endl;
    cout << "Popped: " << st.pop() << endl;
    cout << "Top: " << st.top() << endl;
    cout << "Size: " << st.size() << endl;
    return 0;
}
