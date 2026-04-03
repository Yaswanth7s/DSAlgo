                              //Left Rotating Array by K Places

//Method-1: Brute Force
//Time Complexity: O(n)
//Space Complexity: O(K)
#include<bits/stdc++.h>
using namespace std;
void lrotatebyk(int arr[],int n,int k){
    k=k%n;
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i]=arr[i];
    }
    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }
    for(int i=0;i<k;i++){
        arr[n-k+i]=temp[i];
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
    int k;
    cout<<"Enter how many places by left to move the array: ";
    cin>>k;
    lrotatebyk(arr,n,k);
    cout<<"Array after left rotating by k places is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


//Method-2:Optimal solution
//Time Complexity: O(n)
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
void reversearray(int arr[],int start,int end){
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
void lrotatebyk(int arr[],int n,int k){
    k=k%n;
    if(k==0){
        return;
    }
    reversearray(arr,0,k-1);
    reversearray(arr,k,n-1);
    reversearray(arr,0,n-1);
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
    int k;
    cout<<"Enter how many places by left to move the array: ";
    cin>>k;
    lrotatebyk(arr,n,k);
    cout<<"Array after left rotating by k places is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
