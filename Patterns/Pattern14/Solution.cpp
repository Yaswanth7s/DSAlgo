#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<n-i;j++){
            cout<<" ";
        }
        char ch='A';
        for(int j=1;j<=i;j++){
            cout<<ch++;
        }
        ch-=2;
        for(int j=1;j<i;j++){
            cout<<ch--;
        }
        for(int j=1;j<n-i;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
