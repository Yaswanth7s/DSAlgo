                                //Finding the Maximum Nesting Depth of the Parenthesis
//Method-1: Brute Force
//Time complexity: O(n²)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int MaxNestedDepth(string s){
    int n=s.length();
    int ans=0;
    for(int i=0;i<n;i++){
        int depth=0;
        for(int j=i;j<n;j++){
            if(s[j]=='('){
                depth++;
            }
            else if(s[j]==')'){
                depth--;
            }
            ans=max(depth,ans);
        }
    }
    return ans;
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    int result=MaxNestedDepth(s);
    cout<<"Maximum Nested Depth of parenthesis is: "<<result;
}


//Method-2: Better Solution
//Time complexity: O(n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
int MaxNestedDepth(string s){
    stack<char> st;
    int maxdepth=0;
    for(char ch:s){
        if(ch=='('){
            st.push(ch);
            maxdepth=max(maxdepth,(int)st.size());
        }
        else if(ch==')'){
            st.pop();
        }
    }
    return maxdepth;
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    int result=MaxNestedDepth(s);
    cout<<"Maximum Nested Depth of parenthesis is: "<<result;
}


//Method-3: Optimal Solution
//Time complexity: O(n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int MaxNestedDepth(string s){
    int depth=0;
    int maxdepth=0;
    for(char ch:s){
        if(ch=='('){
            depth++;
            maxdepth=max(maxdepth,depth);
        }
        else if(ch==')'){
            depth--;
        }
    }
    return maxdepth;
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    int result=MaxNestedDepth(s);
    cout<<"Maximum Nested Depth of parenthesis is: "<<result;
}
