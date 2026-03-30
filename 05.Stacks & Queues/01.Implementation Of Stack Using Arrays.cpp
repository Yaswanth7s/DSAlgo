                              //Implementation of Stack Using Arrays
/*Time complexities:    01.For Push  :   O(1)
                        02.For Pop   :   O(1)
                        03.For top   :   O(1)
                        04.For size():   O(1)
  Space complexity : O(n)
*/
#include<bits/stdc++.h>
using namespace std;
class ArrayStack{
    private:
    int* StackArray;
    int capacity;
    int topIndex;
    
    public:
    ArrayStack(int size=1000){
        capacity=size;
        StackArray=new int[capacity];
        topIndex=-1;
    }
    ~ArrayStack(){
        delete[] StackArray;
    }
    
    void push(int x){
        if(topIndex>=capacity-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        StackArray[++topIndex]=x;
    }
    
    int pop(){
        if(topIndex==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return StackArray[topIndex--];
    }
    
    int top(){
        if(topIndex==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return StackArray[topIndex];
    }
    
    int size(){
        return topIndex+1;
    }
};
int main(){
    ArrayStack st(6);
    st.push(2);
    st.push(11);
    st.push(15);
    cout<<"Top of the stack is: "<<st.top()<<endl;
    cout<<"Size of the stack is: "<<st.size()<<endl;
    cout<<"Popped: "<<st.pop()<<endl;
    cout<<"Top of the stack is: "<<st.top()<<endl;
    cout<<"Size of the stack is: "<<st.size()<<endl;
}
