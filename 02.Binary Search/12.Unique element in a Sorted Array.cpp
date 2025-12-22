                                //Finding the Single time appearance element in a sorted array
//Method-1: Brute Force
//Time complexity: O(n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int Uniqueelement(int arr[],int n){
    if(n==1){
        return arr[0];
    }
    for(int i=0;i<n;i++){
        if(i==0){
            if(arr[i]!=arr[i+1]){
                return arr[i];
            }
        }
        else if(i==n-1){
            if(arr[i]!=arr[i-1]){
                return arr[i];
            }
        }
        else{
            if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1]){
                return arr[i];
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
    int result=Uniqueelement(arr,n);
    cout<<"The element that is appearing 1 time is: "<<result;
}


//Method-2: Optimal solution
//Time complexity: O(log n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int Uniqueelement(int arr[],int n){
    if(n==1){
        return arr[0];
    }
    if(arr[0]!=arr[1]){
        return arr[0];
    }
    if(arr[n-1]!=arr[n-2]){
        return arr[n-1];
    }
    int low=1;
    int high=n-2;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
            return arr[mid];
        }
        if(mid%2==1 && arr[mid]==arr[mid-1] || 
            mid%2==0 && arr[mid]==arr[mid+1]){
            low=mid+1;
        }
        else{
            high=mid-1;
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
    int result=Uniqueelement(arr,n);
    if(result==-1){
        cout<<"No element occurred one time";
    }
    else{
        cout<<"The element that is appearing 1 time is: "<<result;
    }
}
