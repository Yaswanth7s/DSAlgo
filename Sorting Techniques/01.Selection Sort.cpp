                                            //Selection Sorting

// Time complexity: 1.Best Case:-> O(n²)
//                    2.Average Case:-> O(n²)
//                    3.Worst Case:-> O(n²)
//Space complexity: O(1)
                   
#include<bits/stdc++.h>
using namespace std;
void selection_sort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        int mini=i;
        for(int j=i+1;j<=n-1;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        int temp=arr[mini];
        arr[mini]=arr[i];
        arr[i]=temp;
    }
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
    selection_sort(arr,n);
    cout<<"Elements after sorting is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
