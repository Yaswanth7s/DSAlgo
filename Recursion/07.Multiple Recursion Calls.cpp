//Multiple Recursion Calls (Example)
//Time complexity: O(2ⁿ)
//Space complexiy: O(n)
#include<bits/stdc++.h>
using namespace std;
int fibo(int n){
    if(n<=1){
        return n;
    }
    else{
        int last=fibo(n-1);
        int secondlast=fibo(n-2);
        return last+secondlast;
    }
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    fibo(n);
    cout<<"Fibonacci number at "<<n<<" is: "<<fibo(n);
}
