#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    vector<bool>cnt(n+1);
    a[n]=1;
    cnt[1]=1;
    for (int i = n-1; i > 1; i--)
    {
        a[i]=1^i;
        cnt[a[i]]=1;  
    }
    int x=1;
    while (x<=n && cnt[x])x++;
    a[1]=x;
    for (int i = 1; i <= n; i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<'\n';
    
    
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
}