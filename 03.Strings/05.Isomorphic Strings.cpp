                                //Finding whether the given two strings are isomorphic or not
//Method-1: Brute Force
//Time complexity: O(n²)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s1,string s2){
    int n1=s1.length();
    int n2=s2.length();
    if(n1!=n2){
        return false;
    }
    for(int i=0;i<n1;i++){
        for(int j=i+1;j<n1;j++){
            if(s1[i]==s1[j] && s2[i]!=s2[j]){
                return false;
            }
            if(s1[i]!=s1[j] && s2[i]==s2[j]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    string s1;
    string s2;
    cout<<"Enter the first string: ";
    cin>>s1;
    cout<<"Enter the second string: ";
    cin>>s2;
    bool result=isIsomorphic(s1,s2);
    if(result==true){
        cout<<"Yes the given strings are isomorphic";
    }
    else{
        cout<<"No the given strings are not isomorphic";
    }
}


//Method-2: Optimal solution
//Time complexity: O(n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s1,string s2){
    int n1=s1.length();
    int n2=s2.length();
    if(n1!=n2){
        return false;
    }
    unordered_map<char, char>mapping1,mapping2;
    for(int i=0;i<n1;i++){
        char c1=s1[i];
        char c2=s2[i];
        if(mapping1.count(c1) && mapping1[c1]!=c2){
            return false;
        }
        if(mapping2.count(c2) && mapping2[c2]!=c1){
            return false;
        }
        mapping1[c1]=c2;
        mapping2[c2]=c1;
    }
    return true;
}
int main(){
    string s1;
    string s2;
    cout<<"Enter the first string: ";
    cin>>s1;
    cout<<"Enter the second string: ";
    cin>>s2;
    bool result=isIsomorphic(s1,s2);
    if(true){
        cout<<"Yes the given strings are isomorphic";
    }
    else{
        cout<<"No the given strings are not isomorphic";
    }
}
