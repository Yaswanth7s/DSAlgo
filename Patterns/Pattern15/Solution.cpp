#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(char ch='E'-(i-1);ch<='E';ch++){
            cout<<ch;
        }
        cout<<endl;
    }
}
