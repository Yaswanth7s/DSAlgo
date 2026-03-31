                            //Implementation Of Stack Using Queue
/*Time complexities:    01.For Push  :   O(n)
                        02.For Pop   :   O(1)
                        03.For top   :   O(1)
                        04.For size():   O(1)
  Space complexity : O(n)
*/
#include<bits/stdc++.h>
using namespace std;
class QueueStack{
    queue<int> q;
    
    public:
    void push(int x){
        int s=q.size();
        q.push(x);
        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    int pop(){
        if(q.empty()) return -1;
        int val=q.front();
        q.pop();
        return val;
    }
    int top(){
        if(q.empty()) return -1;
        return q.front();
    }
    int size(){
        return q.size();
    }
    bool isEmpty(){
        return q.empty();
    }
};
int main(){
    QueueStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.top() << endl;
    cout << "Popped: " << st.pop() << endl;
    cout << "Top: " << st.top() << endl;
    cout << "Size: " << st.size() << endl;
    return 0;
}
