                                //Finding the Minimum of Maximum of Split Array Sum
//Method-1: Brute Force
//Time complexity: O((sum − max) × n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int SplitArray(int arr[],int n,int k){
    int start=*max_element(arr,arr+n);
    int end=0;
    for(int i=0;i<n;i++){
        end+=arr[i];
    }
    if(k>n){
        return -1;
    }
    for(int i=start;i<=end;i++){
        int splits=1;
        int sum=0;
        for(int j=0;j<n;j++){
            if(sum+arr[j]<=i){
                sum+=arr[j];
            }
            else{
                splits++;
                sum=arr[j];
            }
        }
        if(splits<=k){
            return i;
        }
    }
    return -1;
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
    cout<<"Enter the no of partitions: ";
    cin>>k;
    int result=SplitArray(arr,n,k);
    cout<<"The minimum of maximum of sum after k splits is: "<<result;
}


//Method-2: Optimal solution
//Time Complexity: O(n log(sum-max))
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int SplitArray(int arr[],int n,int k){
    int low=*max_element(arr,arr+n);
    int high=0;
    for(int i=0;i<n;i++){
        high+=arr[i];
    }
    if(k>n){
        return -1;
    }
    while(low<=high){
        int mid=low+(high-low)/2;
        int splits=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }
            else{
                splits++;
                sum=arr[i];
            }
        }
        if(splits>k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
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
    cout<<"Enter the no of partitions: ";
    cin>>k;
    int result=SplitArray(arr,n,k);
    cout<<"The minimum of maximum of sum after k splits is: "<<result;
}
