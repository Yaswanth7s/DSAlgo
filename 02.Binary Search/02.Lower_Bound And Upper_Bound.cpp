//Finding the Lower Bound (smallest index such that arr[index]>=target) 
//Method-1: Using Binary Search
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
int lowerbound(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
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
    int target;
    cout<<"Enter the value of target: ";
    cin>>target;
    int result=lowerbound(arr,n,target);
    cout<<"Lower bound is at index: "<<result;
}

//Method-2: Using STL
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements into the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the value of target: ";
    cin>>target;
    int result=lower_bound(arr,arr+n,target)-arr;
    cout<<"Lower bound is at index: "<<result;
}



//Finding the Upper Bound(smallest index such that arr[index]>target)
//Method-1: Using Binary Search
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
int Upperbound(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
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
    int target;
    cout<<"Enter the value of target: ";
    cin>>target;
    int result=Upperbound(arr,n,target);
    cout<<"Upper bound is at index: "<<result;
}

//Method-2: Using STL
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements into the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the value of target: ";
    cin>>target;
    int result=upper_bound(arr,arr+n,target)-arr;
    cout<<"Upper bound is at index: "<<result;
}
