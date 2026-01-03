                                  //Finding the Least capacity to ship packages within D days
//Method-1: Brute Force
//Time complexity: O((sum-max)*n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int shippingpackages(int weights[],int n,int days){
    int maxi=*max_element(weights,weights+n);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=weights[i];
    }
    for(int capacity=maxi;capacity<=sum;capacity++){
        int Reqdays=1;
        int load=0;
        for(int i=0;i<n;i++){
            if(load+weights[i]>capacity){
                Reqdays++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        if(Reqdays<=days){
            return capacity;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the no of packages: ";
    cin>>n;
    int weights[n];
    cout<<"Enter the weights of each package: ";
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    int days;
    cout<<"Enter the no of days: ";
    cin>>days;
    int result=shippingpackages(weights,n,days);
    cout<<"The least capcity to ship packages within "<<days<<" days is: "<<result;
}


//Method-2: Optimal solution
//Time complexity: O(n log(sum-max))
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int shippingpackages(int weights[],int n,int days){
    int low=*max_element(weights,weights+n);
    int high=0;
    for(int i=0;i<n;i++){
        high+=weights[i];
    }
    while(low<=high){
        int mid=low+(high-low)/2;
        int Reqdays=1;
        int load=0;
        for(int i=0;i<n;i++){
            if(load+weights[i]>mid){
                Reqdays++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        if(Reqdays<=days){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int main(){
    int n;
    cout<<"Enter the no of packages: ";
    cin>>n;
    int weights[n];
    cout<<"Enter the weights of each package: ";
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    int days;
    cout<<"Enter the no of days: ";
    cin>>days;
    int result=shippingpackages(weights,n,days);
    cout<<"The least capcity to ship packages within "<<days<<" days is: "<<result;
}
