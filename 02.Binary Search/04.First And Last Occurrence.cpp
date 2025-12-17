//Finding the First and Last Occurence of a given number
//Method-1: Brute Force
//Time complexity: O(n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
void firstandlastoccurences(int arr[],int n,int target){
    int first=-1;
    int last=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            if(first==-1){
                first=i;
                
            }
            last=i;
        }
    }
    cout<<"First Occurence of "<<target<<" is: "<<first<<endl;
    cout<<"Last Occurence of "<<target<<" is: "<<last<<endl;
    
}
int main(){
    int n;
    cout<<"ENter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements into the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enterthe value of target: ";
    cin>>target;
    firstandlastoccurences(arr,n,target);
}

//Method-2: Better Solution
//Time complexity: O(2 log n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int lowerbound(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int Upperbound(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>target){
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
    cout<<"Enter the elements into the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the value of target: ";
    cin>>target;
    int lb=lowerbound(arr,n,target);
    int ub=Upperbound(arr,n,target);
    if(lb==n || arr[lb]!=target){
        cout<<-1;
        return 0;
    }
    cout<<"First Occurence of "<<target<<" is: "<<lb<<endl;
    cout<<"Last Occurence of "<<target<<" is: "<<ub-1<<endl;
}

//Method-3: Optimal Solution
//Time complexity: O(log n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int firstoccurence(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    int first=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            first=mid;
            high=mid-1;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return first;
}
int lastoccurence(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    int last=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            last=mid;
            low=mid+1;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return last;
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
    int result1=firstoccurence(arr,n,target);
    if(result1==-1){
        cout<<"{-1,-1}";
        return 0;
    }
    int result2=lastoccurence(arr,n,target);
    cout<<"First Occurence of "<<target<<" is: "<<result1<<endl;
    cout<<"Last Occurence of "<<target<<" is: "<<result2<<endl;
}
