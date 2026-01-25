                                      //Finding the Longest Common Prefix
//Method-1: Optimal Solution
//Time complexity: O(N × M) where N = No of strings and M = Length of shortest string 
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
string LongestCommonPrefix(string arr[],int n){
    if(n==0){
        return "";
    }
    string result="";
    string base=arr[0];
    for(int i=0;i<base.length();i++){
        for(int j=1;j<n;j++){
            if(i==arr[j].length() || arr[j][i]!=base[i]){
                return result;
            }
        }
        result+=base[i];
    }
    return result;
}
int main(){
    int n;
    cout<<"Enter the no of words in a string: ";
    cin>>n;
    string arr[n];
    cout<<"Enter the words: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    string ans=LongestCommonPrefix(arr,n);
    cout<<"Longest common prefix is: "<<ans;
}
