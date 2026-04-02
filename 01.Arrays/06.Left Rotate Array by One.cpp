                                //Left rotating an array by one place

//Method-1: Brute Force
//Time Complexity: O(n) 
//Space Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
void lrotateby1(int arr[],int n){
    int temp[n];
    for(int i=0;i<n-1;i++){
        temp[i]=arr[i+1];
    }
    temp[n-1]=arr[0];
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the values into array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    lrotateby1(arr,n);
    cout<<"Array after left rotating by one place is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


//Method-1: Optimal Solution
//Time complexity: O(n)
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
void lrotateby1(int arr[],int n){
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the values into array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    lrotateby1(arr,n);
    cout<<"Array after left rotating by one place is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
