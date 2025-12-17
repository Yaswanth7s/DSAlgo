//Types Of Binary Search 

//Method-1: Iterative method
//Time complexity: O(log n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int iterativebinarysearch(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
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
    int target;
    cout<<"Enter the value of target: ";
    cin>>target;
    int index=iterativebinarysearch(arr,n,target);
    cout<<"Target is found at index: "<<index;
}

//Method-2: Recursive binary search
//Time complexity: O(log n)
//Space complexity: O(log n)
#include<bits/stdc++.h>
using namespace std;
int Recursivebinarysearch(int arr[],int low,int high,int target){
    if(low>high){
        return -1;
    }
    int mid=low+(high-low)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]>target){
        return Recursivebinarysearch(arr,0,mid-1,target);
    }
    else{
        return Recursivebinarysearch(arr,mid+1,high,target);
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
    int target;
    cout<<"Enter the value of target: ";
    cin>>target;
    int index=Recursivebinarysearch(arr,0,n-1,target);
    if(index=-1){
        cout<<"Target is not found";
    }
    else{
    cout<<"Target is found at index: "<<index;
    }
}
