                                            //Merge Sort
        
// Time complexity: 1.Best Case:-> O(n log n)
//                    2.Average Case:-> O(n log n)
//                    3.Worst Case:-> O(n log n)
//Space complexity: O(n)

#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int low,int mid,int high){
    int temp[high-low+1];
    int tempindex=0;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp[tempindex++]=arr[left++];
        }
        else{
            temp[tempindex++]=arr[right++];
        }
    }
    while(left<=mid){
        temp[tempindex++]=arr[left++];
    }
    while(right<=high){
        temp[tempindex++]=arr[right++];
    }
    for(int i=0;i<tempindex;i++){
        arr[low+i]=temp[i];
    }
}
void mergesort(int arr[],int low,int high){
    if(low>=high){
        return;
    }
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements into array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    cout<<"Array after merge sort is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
