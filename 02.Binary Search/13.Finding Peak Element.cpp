                            //Finding the Peak element i.e(arr[i-1]<arrr[i]>arr[i+1])
//Method-1: Brute Force
//Time complexity: O(n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int Peakelement(int arr[],int n){
    for(int i=0;i<n;i++){
        if((i==0 || arr[i-1]<arr[i]) && (i==n-1 || arr[i]>arr[i+1])){
            return arr[i];
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
    int result=Peakelement(arr,n);
    cout<<"Peak element is: "<<result;
}


//ethod-2: Optimal solution
//Time complexity: O(log n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int Peakelement(int arr[],int n){
    if(n==1){
        return arr[0];
    }
    if(arr[0]>arr[1]){
        return arr[0];
    }
    if(arr[n-1]>arr[n-2]){
        return arr[n-1];
    }
    int low=1;
    int high=n-2;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return arr[mid];
        }
        else if(arr[mid]>arr[mid-1]){    //if multiple peaks are present then arr[mid]<arr[mid+1] it finds any peak
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
    int result=Peakelement(arr,n);
    cout<<"Peak element is: "<<result;
}


