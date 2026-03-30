                         //Implementation of Queue Using Arrays
/*Time complexities:    01.For enqueue   :   O(1)
                        02.For  dequeue  :   O(1)
                        03.For front     :   O(1)
                        04.For size()    :   O(1)
  Space complexity : O(n)
*/
#include<bits/stdc++.h>
using namespace std;
class ArrayQueue{
    private:
    int* QueueArray;
    int capacity;
    int start;
    int end;
    int currsize;
    
    public:
    ArrayQueue(int size=1000){
        capacity=size;
        QueueArray=new int[capacity];
        start=-1;
        end=-1;
        currsize=0;
    }
    
    ~ArrayQueue(){
        delete[] QueueArray;
    }
    
    void enqueue(int x){
        if(currsize==capacity){
            cout<<"Queue is full"<<endl;
            return;
        }
        if(currsize==0){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%capacity;
        }
        QueueArray[end]=x;
        currsize+=1;
    }
    
    int dequeue(){
        if(currsize==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int ele=QueueArray[start];
        if(currsize==1){
            start=end=-1;
        }
        else{
            start=(start+1)%capacity;
        }
        currsize-=1;
        return ele;
    }
    
    int front(){
        if(currsize==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return QueueArray[start];
    }
    
    int size(){
        return currsize;
    }
};
int main(){
    ArrayQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Front after dequeue: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;
    return 0;
}
