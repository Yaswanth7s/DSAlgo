                          //Finding the second largest element in an array
//Method-1: Brute Force
//Time Complexity: O(nlogn)+O(n)
//Space Complexity: O(1)
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
    sort(arr,arr+n);
    int largest=arr[n-1];
    int secondlargest;
    for(int i=n-2;i>=0;i--){
        if(arr[i]!=largest){
            secondlargest=arr[i];
            break;
        }
    }
    cout<<"The Second largest element is: "<<secondlargest;
}


//Method-2: Better Approach
//Time Complexity: O(n)
//Space Complexity: O(1)
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
    int largest=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest)
        largest=arr[i];
    }
    int secondlargest=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>secondlargest && arr[i]!=largest){
            secondlargest=arr[i];
        }
    }
    cout<<"The Second largest element is: "<<secondlargest;
}


//Method-3: Optimal Solution
//Time Complexity: O(n)
//Space Complexity: O(1)
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
    int largest=arr[0];
    int slargest=-1;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            slargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest){
            slargest=arr[i];
        }
    }
    cout<<"The Second largest element is: "<<slargest;
}
