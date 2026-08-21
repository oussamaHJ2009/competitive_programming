/*
*created: 2026-08-16 at 20:26:11
*problem: Fermat Poll of Binary Strings, link: https://atcoder.jp/contests/arc227/tasks/arc227_a
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> get(){
    string s;
    cin>>s;
    vector<ll>id;
    for(ll i=0;i<s.size();i++){
        if(s[i]=='1')id.push_back(i);
    }
    return id;
}

void solve() {
    ll n;cin>>n;
    vector<vector<ll>>f(3);
    for(ll i=0;i<3;i++)f[i]=get();
    string ans(2*n,'0');
    ll dist=0;
    for(ll i=0;i<n;i++){
        vector<ll>cur = {f[0][i],f[1][i],f[2][i]};
        sort(cur.begin(),cur.end());
        dist+=cur[2]-cur[0];
        ans[cur[1]]='1';
    }

    cout<<dist<<'\n'<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}