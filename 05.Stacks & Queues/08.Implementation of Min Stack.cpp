                                  //Implementing Min Stack
//Method-1: Brute Force
/*Time complexities:    01.For Push   :   O(1)
                        02.For Pop    :   O(1)
                        03.For top    :   O(1)
                        04.For size() :   O(1)
                        05.For get_min:   O(1)
  Space complexity : O(2n)
*/
#include<bits/stdc++.h>
using namespace std;
class stack1{
    stack<pair<int,int>> st;
    public:
    void push(int val){
        if(st.empty()){
            st.push({val,val});
        }
        else{
            st.push({val,min(val,st.top().second)});
        }
    }
    int pop(){
        if(st.empty()) return -1;
        int poppingval=st.top().first;
        st.pop();
        return poppingval;
    }
    int top(){
        if(st.empty()) return -1;
        return st.top().first;
    }
    int size(){
        return st.size();
    }
    int get_min(){
        if(st.empty()) return -1;
        return st.top().second;
    }
};
int main(){
    stack1 s;
    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);
    cout << "Top element: " << s.top() << endl;
    cout << "Minimum element: " << s.get_min() << endl;
    cout<<"Popping: "<<s.pop()<<endl;
    cout << "Top element: " << s.top() << endl;
    cout << "Minimum element: " << s.get_min() << endl;
    cout << "Size of stack: " << s.size() << endl;
}


//Method-2: Optimal Solution
/*Time complexities:    01.For Push   :   O(1)
                        02.For Pop    :   O(1)
                        03.For top    :   O(1)
                        04.For size() :   O(1)
                        05.For get_min:   O(1)
  Space complexity : O(n)
*/
#include<bits/stdc++.h>
using namespace std;
class stack1{
    stack<int> st;
    int mini=INT_MAX;
    public:
    void push(int val){
        if(st.empty()){
            mini=val;
            st.push(val);
        }
        else if(val>mini){
            st.push(val);
        }
        else{
            st.push(2*val-mini);    //Intuition:     10     <   12
            mini=val;                    //   =>    val     <  mini 
        }                                //   => val - mini < 0
    }                                    //   => Adding val on both sides
    int pop(){                           //   => val+val-min< val
        if(st.empty()){                  //   => 2val-mini  < val
            return -1;                   //   =>new val     < val
        }
        int x=st.top();
        st.pop();
        if(x<mini){
            int original=mini;
            mini=2*mini-x;
            return original;
        }
        return x;
    }
    int top(){
        if(st.empty()){
            return -1;
        }
        int x=st.top();
        if(x<mini){
            return mini;
        }
        else{
            return x;
        }
    }
    int get_min(){
        if(st.empty()){
            return -1;
        }
        return mini;
    }
    int size(){
        return st.size();
    }
};
int main(){
    stack1 s;
    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);
    cout << "Top element: " << s.top() << endl;
    cout << "Minimum element: " << s.get_min() << endl;
    cout<<"Popping: "<<s.pop()<<endl;
    cout << "Top element: " << s.top() << endl;
    cout << "Minimum element: " << s.get_min() << endl;
    cout << "Size of stack: " << s.size() << endl;
}
