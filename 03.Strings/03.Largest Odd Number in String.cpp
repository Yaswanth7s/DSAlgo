                                    //Finding the Largest Odd Number in a given String
//Method-1: Brute Force
//Time complexity: O(n³)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
string LargestOddNumberinString(string s){
    long long maxodd=-1;
    int n=s.length();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string sub=s.substr(i,j-i+1);
            long long val=stoll(sub);
            if(val%2==1){
                maxodd=max(maxodd,val);
            }
        }
    }
    if(maxodd==-1){
        return "";
    }
    return to_string(maxodd);
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    string result=LargestOddNumberinString(s);
    cout<<"Largest Odd Number from the given String is: "<<result;
}


//Method-2: Optimal Solution
//Time complexity: O(n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
string LargestOddNumberinString(string s){
    int n=s.length();
    for(int i=n-1;i>=0;i--){
        int digit=s[i]-'0';
        if(digit%2==1){
            return s.substr(0,i+1);
        }
    }
    return "";
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    string result=LargestOddNumberinString(s);
    cout<<"Largest Odd Number from given String is: "<<result;
}
