                                      //Finding the floor square root of a number
//Method-1: Brute Force
//Time complexity: O(√n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int Sqrtofanumber(int n){
    int ans=1;
    for(int i=0;i<=n;i++){
        if(i*i<=n){
            ans=i;
        }
        else{
            break;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the integer: ";
    cin>>n;
    int result=Sqrtofanumber(n);
    cout<<"Square root of "<<n<<" is: "<<result;
}


//Method-2: Better Solution
//Time complexity: O(1)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int root=sqrt(n);
    cout<<"The square root of "<<n<<" is: "<<root;
}


//Method-3: Optimal solution
//Time complexity: O(log n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int sqrtofanumber(int n){
    int low=1;
    int high=n;
    int ans=1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if((mid*mid)<=n){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int result=sqrtofanumber(n);
    cout<<"Square root of "<<n<<" is:  "<<result;
}
