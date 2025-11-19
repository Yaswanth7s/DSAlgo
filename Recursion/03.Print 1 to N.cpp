//Print 1 to N using recursion
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
void printNumber(int i,int n){
    if(i>n){
        return;
    }
    else{
        cout<<i<<endl;;
    }
    printNumber(i+1,n);
}
int main(){
    int n;
    int i=1;
    cout<<"Enter the value of n: ";
    cin>>n;
    printNumber(i,n);
}
