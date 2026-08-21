/*
*created: 2026-08-09 at 13:07:07
*problem: Meeting Division, link: https://atcoder.jp/contests/arc226/tasks/arc226_a
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 998244353;

ll binpow(ll a, ll b) {
    a%=mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res%mod;
}


void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>>val(2*n);
    for(int i=0;i<n;i++){
        cin>>val[2*i].first;
        cin>>val[2*i+1].first;
        val[2*i].second = i;
        val[2*i + 1].second = i;
    }

    sort(val.begin(),val.end());
    vector<vector<int>>adj(n);
    int cc=n;
    unordered_set<int>op;
    for(int i=0;i<2*n;i++){
        // for(auto x:op)cerr<<x<<'\n';
        if(op.count(val[i].second))op.erase(val[i].second);
        else if(op.size()>1){
            cout<<"0\n";
            return;
        }
        else{
            if(!op.empty())cc--;
            op.insert(val[i].second);
        }
        // cerr<<'\n';
    }

    cout<<binpow(2,cc)<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}