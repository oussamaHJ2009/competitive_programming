//problem link: https://atcoder.jp/contests/abc466/tasks/abc466_f
//authored by a human (i guess?)


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    ll x;
    cin>>n>>x;
    vector<ll>a;
    int L=1;
    for (int i = 0; i < n; i++)
    {
        ll it;
        cin>>it;
        if(!i || it<a.back()){L=lcm(L,it);a.push_back(it);}
    }
    cout<<x/L<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}