#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rnd(ll l,ll r){
    return l+rng()%(r-l+1);
}

void solve() {
    int n = rnd(1, 3);
    ll k= rnd(0,20);
    vector<int>R(n),L(n);
    for(int i=0;i<n;i++){
        int l=rnd(1,10);
        int r = rnd(l,10);
        R[i]=r;L[i]=l;
    }
    cout<<n<<' '<<k<<'\n';
    for(int i=0;i<n;i++){
        cout<<L[i]<<' '<<R[i]<<'\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}