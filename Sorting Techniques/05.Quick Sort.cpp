                                            //Quick Sort
                                            
// Time complexity: 1.Best Case:-> O(n log n)
//                    2.Average Case:-> O(n log n)
//                    3.Worst Case:-> O(n²)
//Space complexity: 1.Best/Average Case:-> O(log n)
//                  2.Worst Case:-> O(n)

#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int pindex=partition(arr,low,high);
        quicksort(arr,low,pindex-1);
        quicksort(arr,pindex+1,high);
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
    quicksort(arr,0,n-1);
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
