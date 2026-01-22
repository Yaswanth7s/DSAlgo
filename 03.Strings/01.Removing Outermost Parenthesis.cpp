                                                    //Removing Outermost Parenthesis
//Method-1: Brute Force
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
string removeparenthesis(string s){
    string result="";
    int level=0;
    for(char ch : s){
        if(ch=='('){
            if(level>0){
                result+=ch;
            }
            level++;
        }
        else if(ch==')'){
            level--;
            if(level>0){
                result+=ch;
            }
        }
        else{
            if(level>0){
                result+=ch;
            }
        }
    }
    return result;
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    string ans=removeparenthesis(s);
    cout<<"Valid Parenthesis is: "<<ans;
    
}
