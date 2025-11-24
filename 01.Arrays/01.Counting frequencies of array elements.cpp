//Finding the no of occurences of specific element in an array
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the values in the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the Target: ";
    cin>>target;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==target){  //add cout<<i to print the index also
            count++;
        }
    }
    cout<<"The count of "<<target<<" is: "<<count;
}
