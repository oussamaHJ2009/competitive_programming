#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rng (chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l,ll r){
    return l + rng() % (r-l+1);
}

void solve() {
    int n = rnd(5, 10);
    string s = "bdeilmrs";
    string res(n,' ');
    for(int i=0;i<n;i++){
        res[i] = s[rnd(0,s.size()-1)];
    }
    cout<<res<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}