                          //Finding whether the given string forms a goal string after rotations
//Method-1: Brute Force 
//Time complexity: O(n²)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
bool RotateString(string s,string goal){
    if(s.length()!=goal.length()){
        return false;
    }
    for(int i=0;i<s.length();i++){
        string rotated=s.substr(i)+s.substr(0,i);
        if(rotated==goal){
            return true;
        }
    }
    return false;
}
int main(){
    string s;
    string goal;
    cout<<"Enter the string s: ";
    cin>>s;
    cout<<"Enter the string goal: ";
    cin>>goal;
    bool result=RotateString(s,goal);
    if(result){
        cout<<"Yes after some rotations the given string is matched with goal";
    }
    else{
        cout<<"No the given string cannot be formed as goal string";
    }
}


//Method-2: Better Solution
//Time complexity: O(n²)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
bool RotateString(string s,string goal){
    if(s.length()!=goal.length()){
        return false;
    }
    for(int i=0;i<s.length();i++){
        if(s==goal){
            return true;
        }
        char temp=s[0];
        s.erase(0,1);
        s.push_back(temp);
    }
    return false;
}
int main(){
    string s;
    string goal;
    cout<<"Enter the string s: ";
    cin>>s;
    cout<<"Enter the string goal: ";
    cin>>goal;
    bool result=RotateString(s,goal);
    if(result){
        cout<<"Yes after some rotations the given string is matched with goal";
    }
    else{
        cout<<"No the given string cannot be formed as goal string";
    }
}


//Method-3: Optimal Solution
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
bool RotateString(string s,string goal){
    if(s.length()!=goal.length()){
        return false;
    }
    return (s+s).find(goal)!=string::npos;
}
int main(){
    string s;
    string goal;
    cout<<"Enter the string s: ";
    cin>>s;
    cout<<"Enter the string goal: ";
    cin>>goal;
    bool result=RotateString(s,goal);
    if(result){
        cout<<"Yes after some rotations the given string is matched with goal";
    }
    else{
        cout<<"No the given string cannot be formed as goal string";
    }
}
