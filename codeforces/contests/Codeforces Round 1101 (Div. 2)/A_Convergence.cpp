#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int &it:a)cin>>it;
        sort(a.begin(),a.end());
        int l=0,r=n-1;
        while (a[l]!=a[(n+1)/2])l++;
        while (a[r]!=a[(n+1)/2])r--;
        cout<<min(max(l,n-r-1),n/2)<<'\n';
    }   
}