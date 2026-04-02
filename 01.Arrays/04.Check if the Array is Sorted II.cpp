                              //Finding whether the array is sorted or not
//Time Complexity:O(n)
//Space Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the values into array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool sort=true;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            sort=false;
            break;
        }
    }
    if(sort){   
        cout<<"The array is sorted";
    }
    else{
        cout<<"the array is not sorted";
    }
}
