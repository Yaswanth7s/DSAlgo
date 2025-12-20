                          //Finding minimum in a rotated sorted array (Contains duplicates)
//Method-1: Brute Force
//Time complexity: O(n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int mininrotatedsortedarray(int arr[],int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return arr[i+1];
        }
    }
    return arr[0];
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
    int result=mininrotatedsortedarray(arr,n);
        cout<<"Min element is: "<<result;
}

//Method-2: Optimal solution
//Time complexity: O(log n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int mininrotatedsortedarray(int arr[],int n){
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            ans=min(ans,arr[low]);
            low++;
            high--;
        }
        if(arr[low]<=arr[mid]){
            ans=min(ans,arr[low]);
            low=mid+1;
        }
        else{
            high=mid-1;
            ans=min(ans,arr[mid]);
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
    int result=mininrotatedsortedarray(arr,n);
    cout<<"Minumum from the rotated sorted array is: "<<result;
}
