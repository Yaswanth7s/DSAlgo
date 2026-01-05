                                  //Finding the Maximum posible minimum distance between two cows
//Method-1: Brute Force
//Time complexity: O(nlogn + n*(max-min))
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int AggressiveCows(int arr[],int n,int k){
    sort(arr,arr+n);
    int mini=arr[0];
    int maxi=arr[n-1];
    int ans=-1;
    for(int dist=1;dist<=maxi-mini;dist++){
        int cntcows=1;
        int lastcow=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-lastcow>=dist){
                cntcows++;
                lastcow=arr[i];
            }
        }
        if(cntcows>=k){
            ans=dist;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the No of stalls: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the places at which stall is present: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the no of cows: ";
    cin>>k;
    int result=AggressiveCows(arr,n,k);
    cout<<"The maximum possible minimum distance between two cows is: "<<result;
}


//Method-2: Optimal solution
//Time complexity: O(nlogn + nlog(max-min))
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int AggressiveCows(int arr[],int n,int k){
    sort(arr,arr+n);
    int low=0;
    int high=arr[n-1]-arr[0];
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int cntcows=1;
        int lastcow=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-lastcow>=mid){
                cntcows++;
                lastcow=arr[i];
            }
        }
        if(cntcows>=k){
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
    cout<<"Enter the No of stalls: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the places at which stall is present: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the no of cows: ";
    cin>>k;
    int result=AggressiveCows(arr,n,k);
    cout<<"The maximum possible minimum distance between two cows is: "<<result;
}
