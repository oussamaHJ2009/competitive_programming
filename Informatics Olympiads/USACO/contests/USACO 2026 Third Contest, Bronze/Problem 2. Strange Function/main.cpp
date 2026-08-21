#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const ll mod = 1e9+7;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() {
    string s;
    cin>>s;
    ll res=0;
    for(auto &c:s){
        if(c-'0'!=((c-'0')%2)){
            res=1;
            c=((c-'0')%2)+'0';
        }
    }
    cerr<<s<<'\n';
    reverse(s.begin(),s.end());
    cerr<<s<<'\n';
    int p=1,pp=0;
    for(auto c:s){
        if(c=='1'){
            res = (res + (p + pp)%mod)%mod;
        }
        pp=p;
        p=(p<<1)%mod;
    }
    cout<<res<<'\n';
}

int main() {
    setIO("");
    int t = 1;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}