//Printing N to 1 
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
void printNumberReverse(int i,int n){
    if(i<1){
        return;
    }
    else{
        cout<<i<<endl;
    }
    printNumberReverse(i-1,n);
}
int main(){
    int n;
    int i=1;
    cout<<"Enter the value of n: ";
    cin>>n;
    printNumberReverse(n,n);
}
