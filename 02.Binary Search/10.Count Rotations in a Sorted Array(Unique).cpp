                          //Finding the No of Rotations in a Sorted array (Unique Elements)
//Method-1: Optimal solution
//Time complexity: O(log n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int noofrotations(int arr[],int n){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[low]<=arr[high]){
           return low;
        }
        if(arr[low]<=arr[mid]){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    return 0;
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
    int result=noofrotations(arr,n);
    cout<<"No of times the array has rotated: "<<result;
}
