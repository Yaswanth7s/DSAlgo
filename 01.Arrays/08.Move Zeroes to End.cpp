                                  //moving all zeroes to the end

//Method-1: Brute Force
//Time Complexity: O(n)
//Space Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
void movezeroestoend(int arr[],int n){
    int temp[n];
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp[j++]=arr[i];
        }
    }
    while(j<n){
        temp[j++]=0;
    }
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
    movezeroestoend(arr,n);
    cout<<"Array after moving zeroes to end is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


//Method-2: Optimal Solution
//Time Complexity: O(n)
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
void movezeroestoend(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
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
    movezeroestoend(arr,n);
    cout<<"Array after moving zeroes to end is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
