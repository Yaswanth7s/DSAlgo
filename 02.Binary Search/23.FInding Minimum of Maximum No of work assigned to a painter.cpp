                              //Finding the Minimum of maximum of work assigned to a painter
//Method-1: Brute Force
//Time complexity: O((sum − max) × n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int PaintersPartition(int arr[],int n,int k){
    int start=*max_element(arr,arr+n);
    int end=0;
    for(int i=0;i<n;i++){
        end+=arr[i];
    }
    if(k>n){
        return -1;
    }
    for(int i=start;i<=end;i++){
        int painters=1;
        int partitionassigned=0;
        for(int j=0;j<n;j++){
            if(partitionassigned+arr[j]<=i){
                partitionassigned+=arr[j];
            }
            else{
                painters++;
                partitionassigned=arr[j];
            }
        }
        if(painters<=k){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the number of partitions: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the amount of work in each partition: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the no of painters: ";
    cin>>k;
    int result=PaintersPartition(arr,n,k);
    cout<<"The minimum  of maximum of all the partitions: "<<result;
}


//Method-2: Optimal solution
//Time Complexity: O(n log(sum-max))
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int PaintersPartition(int arr[],int n,int k){
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
        int painters=1;
        int partitionassigned=0;
        for(int i=0;i<n;i++){
            if(partitionassigned+arr[i]<=mid){
                partitionassigned+=arr[i];
            }
            else{
                painters++;
                partitionassigned=arr[i];
            }
        }
        if(painters>k){
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
    cout<<"Enter the number of partitions: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the amount of work in each partition: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the no of painters: ";
    cin>>k;
    int result=PaintersPartition(arr,n,k);
    cout<<"The minimum  of maximum of all the partitions: "<<result;
}
