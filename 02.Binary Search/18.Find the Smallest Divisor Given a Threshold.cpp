                                //Finding the Smallest Divisor Given a threshold value
//Method-1: Brute Force
//Time complexity: O(n* (max(arr))
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int smallestdivisor(int arr[],int n,int threshold){
    int maxi=*max_element(arr,arr+n);
    for(int divisor=1;divisor<=maxi;divisor++){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(arr[i]+divisor-1)/divisor;
        }
        if(sum<=threshold){
            return divisor;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the values into the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int threshold;
    cout<<"Enter the threshold value: ";
    cin>>threshold;
    int result=smallestdivisor(arr,n,threshold);
    cout<<"The smallest divisor that gives <= threshold is: "<<result;
}


//Method-2: Optimal solution
//Time complexity: O(n log(max(arr)))
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int smallestdivisor(int arr[],int n,int threshold){
    int maxi=*max_element(arr,arr+n);
    int low=1;
    int high=maxi;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(arr[i]+mid-1)/mid;
        }
        if(sum<=threshold){
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
    cout<<"Enter the values into the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int threshold;
    cout<<"Enter the threshold value: ";
    cin>>threshold;
    int result=smallestdivisor(arr,n,threshold);
    cout<<"The smallest divisor which is <= threshold is: "<<result;
}
