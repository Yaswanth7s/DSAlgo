                                               //Insertion Sort

// Time complexity: 1.Best Case:-> O(n)
//                    2.Average Case:-> O(n²)
//                    3.Worst Case:-> O(n²)
//Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
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
    insertion_sort(arr,n);
    cout<<"Elements after sorting is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
