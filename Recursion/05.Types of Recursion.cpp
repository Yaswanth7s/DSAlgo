//Type-1: parameterized recursion
//Ex-1: Sum of n numbers
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
void sumofn(int i,int sum){
    if(i<0){
        cout<<sum<<endl;
        return;
    }
    else{
        sumofn(i-1,sum+i);
    }
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    sumofn(n,0);
}

//Ex-2: Factorial of n
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
void factorial(int i,int product){
    if(i<=1){
        cout<<product;
        return;
    }
    else{
        factorial(i-1,product*i);
    }

}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    factorial(n,1);
}



//Type-2: functional recursion
//Ex-1: Sum of n
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
int sumofn(int n){
    if(n==0)
        return 0;
        return n+sumofn(n-1);
    
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Sum is: "<<sumofn(n)<<endl;
}

//Ex-2: Factorial of n
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
    if(n<=1){
        return 1;
    }
    return n*factorial(n-1);
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Factoial of "<<n<<" is: "<<factorial(n)<<endl;
}
