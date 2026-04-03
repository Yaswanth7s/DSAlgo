                                    //Finding the Element Using Linear Search
//Time Complexity: O(n)
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int linearsearch(int arr[],int n,int num){
    for(int i=0;i<n;i++){
        if(arr[i]==num){
            return i;
        }  
    }
    return -1;
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
    int num;
    cout<<"Enter the number that you want to find: ";
    cin>>num;
    int index=linearsearch(arr,n,num);
    cout<<"Index position of given number is: "<<index;
}
