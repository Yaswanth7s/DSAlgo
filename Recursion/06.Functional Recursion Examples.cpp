//Functional Recursion Examples
//Ex-1: Reverse array Using Two Pointers concept
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
void reversearr(int arr[],int l,int m){
    if(l>=m){
        return;
    }
    else{
        swap(arr[l],arr[m]);
        reversearr(arr,l+1,m-1);
    }
}
int main(){
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reversearr(arr,0,n-1);
    cout<<"The reversed array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//Ex-2: Reverse array Using Index and Size of array
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
void reversearr(int arr[],int i,int n){
    if(i>=n/2){
        return;
    }
    else{
        swap(arr[i],arr[n-i-1]);
        reversearr(arr,i+1,n);
    }
}
int main(){
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reversearr(arr,0,n);
    cout<<"Reversed array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//Ex-3: Check if String is a Palindrome
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
bool palindrome(string s,int i){
    if(i>=s.size()/2){
        return true;
    }
    if(s[i]!=s[s.size()-i-1]){
        return false;
    }
    return palindrome(s,i+1);
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    if(palindrome(s,0)){
        cout<<"Yes it is palindrome";
    }
    else{
        cout<<"No it is not a palindrome";
    }
}
