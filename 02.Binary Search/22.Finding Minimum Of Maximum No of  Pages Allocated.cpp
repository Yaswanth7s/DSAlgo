                                //The Minimum of Maximum no of pages allocated to a students
//Method-1: Brute Force
//Time complexity: O((sum − max) × n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int BooksAllocation(int arr[],int n,int m){
    int start=*max_element(arr,arr+n);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int end=sum;
    if(m>n){
        return -1;
    }
    for(int i=start;i<=end;i++){
        int students=1;
        int pagesallocated=0;
        for(int j=0;j<n;j++){
            if(pagesallocated+arr[j]<=i){
                pagesallocated+=arr[j];
            }
            else{
                students++;
                pagesallocated=arr[j];
            }
        }
        if(students<=m){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the no of books: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the number of pages in each book: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cout<<"Enter the no of students: ";
    cin>>m;
    int result=BooksAllocation(arr,n,m);
    cout<<"The minimum of Maximum no of pages assigned to a student is: "<<result;
}


//Method-2: Optimal solution
//Time Complexity: O(n log(sum-max))
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int BooksAllocation(int arr[],int n,int m){
    int low=*max_element(arr,arr+n);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int high=sum;
    if(m>n){
        return -1;
    }
    while(low<=high){
        int mid=low+(high-low)/2;
        int students=1;
        int pagesallocated=0;
        for(int i=0;i<n;i++){
            if(pagesallocated+arr[i]<=mid){
                pagesallocated+=arr[i];
            }
            else{
                students++;
                pagesallocated=arr[i];
            }
        }
        if(students>m){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
int main(){
    int n;
    cout<<"Enter the no of books: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the number of pages in each book: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cout<<"Enter the no of students: ";
    cin>>m;
    int result=BooksAllocation(arr,n,m);
    cout<<"The minimum of Maximum no of pages assigned to a student is: "<<result;
}
