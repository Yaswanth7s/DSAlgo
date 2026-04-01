                              //Implementation of Queue Using Stacks

//Method-1: Using Two Stacks(Less Push Operations)
/*Time complexities:    01.For enqueue   :   O(2n)
                        02.For  dequeue  :   O(1)
                        03.For front     :   O(1)
                        04.For size()    :   O(1)
  Space complexity : O(n)*/
#include<bits/stdc++.h>
using namespace std;
class StackQueue{
    stack<int>s1,s2;
    
    public:
    void push(int x){
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop(){
        if(s1.empty()){
            cout<<"Queue is empty";
            return -1;
        }
        int val=s1.top();
        s1.pop();
        return val;
    }
    int top(){
        if(s1.empty()){
            cout<<"Queue is empty";
            return -1;
        }
        return s1.top();
    }
    int size(){
        return s1.size();
    }
};
int main(){
    StackQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.pop() << endl;
    cout << q.top() << endl;
    cout << q.size() << endl;
    return 0;
}


//Method-2: Using Two Stacks(More Push Operations)
/*Time complexities:    01.For enqueue   :   O(1)
                        02.For  dequeue  :   O(n)
                        03.For front     :   O(n)
                        04.For size()    :   O(1)
  Space complexity : O(n)*/
#include<bits/stdc++.h>
using namespace std;
class StackQueue{
    stack<int>s1,s2;
    
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        if(!s2.empty()){
            int val=s2.top();
            s2.pop();
            return val;
        }
        else{
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            int val=s2.top();
            s2.pop();
            return val;
        }
    }
    int top(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        if(!s2.empty()){
            return s2.top();
        }
        else{
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    int size(){
        return s1.size()+s2.size();
    }
};
int main(){
    StackQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.pop() << endl;
    cout << q.top() << endl;
    cout << q.size() << endl;
    return 0;
}
