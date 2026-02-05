                                          //Sort characters by frequency
//Method-1: Brute Force
//Time complexity: O(n²)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
string SortCharByFrequency(string s){
    unordered_map<char,int> freq;
    for(char ch:s){
        freq[ch]++;
    }
    string result=" ";
    while(!freq.empty()){
        char maxchar;
        char maxfreq=0;
        for(auto it:freq){
            if(it.second>maxfreq){
                maxfreq=it.second;
                maxchar=it.first;
            }
        }
        for(int i=0;i<maxfreq;i++){
            result+=maxchar;
        }
        freq.erase(maxchar);
    }
    return result;
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    string ans=SortCharByFrequency(s);
    cout<<"New String After sorting characters by frequency is: "<<ans;
}


//Method-2: Better Solution
//Time complexity: O(n log k)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
string SortCharByFrequency(string s){
    unordered_map<char,int> freq;
    for(char ch:s){
        freq[ch]++;
    }
    priority_queue<pair<int,char>> pq;
    for(auto it: freq){
        pq.push({it.second,it.first});
    }
    string result=" ";
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        result.append(p.first,p.second);
    }
    return result;
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    string ans=SortCharByFrequency(s);
    cout<<"New String After sorting characters by frequency is: "<<ans;
}


//Method-3: Optimal solution
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
string SortCharByFrequency(string s){
    unordered_map<char,int> freq;
    for(char ch:s){
        freq[ch]++;
    }
    vector<string> bucket(s.length()+1);
    for(auto it:freq){
        bucket[it.second].append(it.second,it.first);
    }
    string result=" ";
    for(int i=bucket.size()-1;i>0;i--){
        result+=bucket[i];
    }
    return result;
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    string ans=SortCharByFrequency(s);
    cout<<"New String After sorting characters by frequency is: "<<ans;
}
