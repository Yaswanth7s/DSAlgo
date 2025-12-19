                          //Search in Rotated Sorted Array (contains duplicates)
//Method-1: Brute Force
//Time complexity: O(n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
void searchinrotatedsortedarray(int arr[],int n,int target){
    bool found=false;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cout<<"Target found at index: "<<i<<endl;
            found=true;
        }
    }
    if(!found){
        cout<<"Target not found";
    }
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
    cout<<"Enter the target: ";
    cin>>target;
    searchinrotatedsortedarray(arr,n,target);
}

//Method-2: Optimal Solution
//Time complexity: O(n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int searchinrotatedsortedarray(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low=low+1;
            high=high-1;
            continue;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && target<=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(arr[mid]<=target && target<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
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
    cout<<"Enter the target: ";
    cin>>target;
    int index=searchinrotatedsortedarray(arr,n,target);
    if(index==-1){
        cout<<"Target not found";
        return 0;
    }
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cout<<"Target found at index: "<<i<<endl;
        }
    }
}
