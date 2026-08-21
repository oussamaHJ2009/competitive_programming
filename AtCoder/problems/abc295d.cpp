//problem link: https://atcoder.jp/contests/abc295/tasks/abc295_d
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int cnt[1024];
int p[10];

void solve() {
    string s;
    cin>>s;
    for(int i=0;i<10;i++)p[i]=0;
    for(int i=0;i<1024;i++)cnt[i]=0;
    cnt[0]++;
    ll ans=0;
    for(auto c:s){
        p[c-'0']++;
        int mask=0;
        for(int i=0;i<10;i++)mask|=(p[i]&1)<<i;
        ans+=cnt[mask];
        cnt[mask]++;
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}