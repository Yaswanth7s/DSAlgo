                          //Checking whether the given two strings are Valid Anagrams or not
//Method-1: Brute Force
//Time complexity: O(n²)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s,string t){
    if(s.length()!=t.length()){
        return false;
    }
    for(int i=0;i<s.length();i++){
        bool found=false;
        for(int j=0;j<t.length();j++){
            if(s[i]==t[j]){
                t[j]='*';
                found=true;
                break;
            }
        }
        if(!found){
            return false;
        }
    }
    return true;
}
int main(){
    string s;
    string t;
    cout<<"Enter the string s: ";
    cin>>s;
    cout<<"Enter the string t: ";
    cin>>t;
    bool result=isAnagram(s,t);
    if(result){
        cout<<"Yes the given two strings are Anagrams";
    }
    else{
        cout<<"No the given two strings are not Anagrams";
    }
}


//Method-2: Better Solution
//Time complexity: O(n log n)
//Space complexity: O(1) || O(log n) used for Sorting
#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s,string t){
    if(s.length()!=t.length()){
        return false;
    }
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s==t;
}
int main(){
    string s;
    string t;
    cout<<"Enter the string s: ";
    cin>>s;
    cout<<"Enter the string t: ";
    cin>>t;
    bool result=isAnagram(s,t);
    if(result){
        cout<<"Yes the given two strings are Anagrams";
    }
    else{
        cout<<"No the given two strings are not Anagrams";
    }
}


//Method-3: Optimal Solution (Type-1)
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s,string t){
    if(s.length()!=t.length()){
        return false;
    }
    unordered_map<char,int> freq;
    for(char c:s){
        freq[c]++;
    }
    for(char c:t){
        freq[c]--;
        if(freq[c]<0){
            return false;
        }
    }
    return true;
}
int main(){
    string s;
    string t;
    cout<<"Enter the string s: ";
    cin>>s;
    cout<<"Enter the string t: ";
    cin>>t;
    bool result=isAnagram(s,t);
    if(result){
        cout<<"Yes the given two strings are Anagrams";
    }
    else{
        cout<<"No the given two strings are not Anagrams";
    }
}

        //Optimal Solution (Type-2)
//Time complexity: O(n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s,string t){
    if(s.length()!=t.length()){
        return false;
    }
    int count[26]={0};
    for(char c:s){
        count[c-'a']++;
    }
    for(char c:t){
        count[c-'a']--;
        if(count[c-'a']<0){
            return false;
        }
    }
    return true;
}
int main(){
    string s;
    string t;
    cout<<"Enter the string s: ";
    cin>>s;
    cout<<"Enter the string t: ";
    cin>>t;
    bool result=isAnagram(s,t);
    if(result){
        cout<<"Yes the given two strings are Anagrams";
    }
    else{
        cout<<"No the given two strings are not Anagrams";
    }
}
