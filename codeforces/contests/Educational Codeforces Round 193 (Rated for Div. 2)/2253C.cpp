/*
*created: 2026-08-07 at 16:21:49
*problem: C. Sum of Distinct Values in a Matrix, link: https://codeforces.com/contest/2253/problem/C
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int N=1e6+2;
void solve() {
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<int>a(x),b(y);
    for(int i=0;i<x;i++)cin>>a[i];
    for(int i=0;i<y;i++)cin>>b[i];
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    ll ans=0;
    vector<bool>cnt(N,0);
    int ii=0,jj=0,ca=0,cb=0;
    {
        while(ca<n && ii < x && ((jj < y && a[ii]>=b[jj])||jj>=y)){
            if(!cnt[a[ii]]){
                ans+=a[ii];
                ca++;
                cnt[a[ii]]=1;
            }
            ii++;
        }
        while(cb<n && jj < y && ((ii < x && b[jj]>a[ii])||ii>=x)){
            if(!cnt[b[jj]]){
                ans+=b[jj];
                cb++;
                cnt[b[jj]]=1;
            }
            jj++;
        }
    }

    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}