//Print name N times using recursion
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
void printName(int i,int n){
    if(i>n){
        return;
    }
    else{
        cout<<"Yaswanth"<<endl;
    }
    printName(i+1,n);
}
int main(){
    int n;
    int i=1;
    cout<<"Enter the value of n: ";
    cin>>n;
    printName(i,n);
}
