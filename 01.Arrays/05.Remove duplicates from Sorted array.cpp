                                //Removing Duplicates from a Sorted Array

//Method-1: Brute Force
//Time Complexity:O(nlogn)+O(n)
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
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    cout<<"No of Unique elements are: "<<st.size()<<endl;
    cout<<"The unique elements are: ";
    //cout << "Smallest: " << *st.begin() << endl;
    //cout << "Largest: " << *st.rbegin() << endl;
    for(auto it: st){
        cout<<it<<" ";
    }
}


//Method-2: Better Solution
//Time Complexity: O(nlogn)
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
    sort(arr,arr+n);
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    cout<<"No of unique elements are: "<<i+1<<endl;
    cout<<"Unique elements are: ";
    for(int k=0;k<=i;k++){
        cout<<arr[k]<<" ";
    }
}


//Method-3: Optimal Solution
//Time Complexity:O(n)
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
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    cout<<"No of Unique elements are: "<<st.size()<<endl;
    cout<<"The unique elements are: ";
    //cout << "Smallest: " << *st.begin() << endl;
    //cout << "Largest: " << *st.rbegin() << endl;
    for(auto it: st){
        cout<<it<<" ";
    }
}
