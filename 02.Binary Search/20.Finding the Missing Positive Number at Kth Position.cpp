                                //Finding the Positive Missing Number at Kth Position
//Method-1: Brute Force
//Time complexity: O(n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int MissingPositiveNumber(int arr[],int n,int k){
    for(int i=0;i<n;i++){
        if(arr[i]<=k){
            k++;
        }
        else{
            break;
        }
    }
    return k;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements into the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    int result=MissingPositiveNumber(arr,n,k);
    cout<<"Missing Positive Number at "<<k<<" position is: "<<result;
}


//Method-2: Optimal solution
//Time complexity: O(log n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int MissingPositiveNumber(int arr[],int n,int k){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high+1+k;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements into the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    int result=MissingPositiveNumber(arr,n,k);
    cout<<"Missing Positive Number at "<<k<<" position is: "<<result;
}
