                            //Implementation of Queue Using Linked List
/*Time complexities:    01.For enqueue   :   O(1)
                        02.For  dequeue  :   O(1)
                        03.For front     :   O(1)
                        04.For size()    :   O(1)
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
class LinkedListQueue{
    private:
    Node* start;
    Node* end;
    int sz;
    
    public:
    LinkedListQueue(){
        start=end=nullptr;
        sz=0;
    }
    void enqueue(int x){
        Node* temp=new Node(x);
        if(start==nullptr){
            start=end=temp;
        }
        else{
            end->next=temp;
            end=temp;
        }
        sz++;
    }
    int dequeue(){
        if(start==nullptr) return -1;
        int val=start->data;
        Node* temp=start;
        start=start->next;
        if(start==nullptr){
            end=nullptr;
        }
        delete temp;
        sz--;
        return val;
    }
    int front(){
        if(start==nullptr) return -1;
        else{
            return start->data;
        }
    }
    int size(){
        return sz;
    }
};
int main(){
    LinkedListQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.front() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Front: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;
    return 0;
}
