                                    //Minimum No of Days to make m Bouquets
//Method-1: Brute Force
//Time complexity: O((maxDay−minDay)×n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
bool possible(int bloomDay[],int n,int m,int k,int day){
    int cnt=0;
    int noofbouquets=0;
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=day){
            cnt++;
        }
        else{
            noofbouquets+=(cnt/k);
            cnt=0;
        }
    }
    noofbouquets+=(cnt/k);
    if(noofbouquets>=m){
        return true;
    }
    else{
        return false;
    }
}
int Minnoofdaystomakembouquets(int bloomDay[],int n,int m,int k){
    if((m*k)>n){
        return -1;
    }
    int low=*min_element(bloomDay,bloomDay+n);
    int high=*max_element(bloomDay,bloomDay+n);
    for(int i=low;i<=high;i++){
        if(possible(bloomDay,n,m,k,i)==true){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int bloomDay[n];
    cout<<"Enter the values into the array: ";
    for(int i=0;i<n;i++){
        cin>>bloomDay[i];
    }
    int m;
    cout<<"Enter the no of bouquets: ";
    cin>>m;
    int k;
    cout<<"Enter the number of adjacent flowers that each bouquet contains: ";
    cin>>k;
    int ans=Minnoofdaystomakembouquets(bloomDay,n,m,k);
    cout<<"The min of days to make m bouquets is: "<<ans;
}


//Method-2: Optimal Solution
//Time complexity: O(n log(maxDay))
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
bool possible(int bloomDay[],int n,int m,int k,int day){
    int cnt=0;
    int noofbouquets=0;
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=day){
            cnt++;
        }
        else{
            noofbouquets+=(cnt/k);
            cnt=0;
        }
    }
    noofbouquets+=(cnt/k);
    return noofbouquets>=m;
}
int binarysearch(int bloomDay[],int n,int m,int k){
    if((m*k)>n){
        return -1;
    }
    int low=*min_element(bloomDay,bloomDay+n);
    int high=*max_element(bloomDay,bloomDay+n);
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(possible(bloomDay,n,m,k,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int bloomDay[n];
    cout<<"Enter the values into the array: ";
    for(int i=0;i<n;i++){
        cin>>bloomDay[i];
    }
    int m;
    cout<<"Enter the no of bouquets: ";
    cin>>m;
    int k;
    cout<<"Enter the number of adjacent flowers that each bouquet contains: ";
    cin>>k;
    int ans=binarysearch(bloomDay,n,m,k);
    cout<<"The min of days to make m bouquets is: "<<ans;
}
