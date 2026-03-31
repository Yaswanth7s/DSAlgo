#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int initialspaces=2*n-2;
    for(int i=1;i<=n;i++){
        //stars
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        //spaces
        for(int j=1;j<=initialspaces;j++){
            cout<<" ";
        }
        //stars
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        initialspaces-=2;
        cout<<endl;
    }
    initialspaces=2;
    for(int i=n;i>=1;i--){
        //stars
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        //spaces
        for(int j=1;j<initialspaces;j++){
            cout<<" ";
        }
        //stars
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        initialspaces+=2;
        cout<<endl;
    }
}
