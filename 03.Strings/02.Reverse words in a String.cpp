                                             //Reverse the words in a String
//Method-1: Better/Optimal Solution
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
string Reversewordsinastring(string s){
    int n=s.length();
    string ans="";
    reverse(s.begin(),s.end());
    for(int i=0;i<n;i++){
        string word="";
        while(i<n && s[i]!=' '){
            word+=s[i];
            i++;
        }
        reverse(word.begin(),word.end());
        if(word.length()>0){
            ans+=" "+word;
        }
    }
    return ans.substr(1);
}
int main(){
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);
    string result=Reversewordsinastring(s);
    cout<<"After reversing words in a string: "+result;
}
