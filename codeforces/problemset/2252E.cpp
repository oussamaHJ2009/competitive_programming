/*
*created: 2026-08-06 at 18:39:02
*problem: E. Generational Triplets, link: https://codeforces.com/contest/2252/problem/E
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void pr(unsigned int num) {
    bool p=0;
    for (int i = sizeof(num) * 8 - 1; i >= 0; --i) {
        if((num >> i) & 1)p=1;
        if(p)cerr << ((num >> i) & 1);
    }
    cerr << "\n";
}

void solve() {
    ll n;
    cin>>n;
    int ans=0;
    for(int a=1;a<=n;a++){
        for(int c=a+1;c<=n;c++){
            if((a&c)<<1 == (a^c)){
                ans++;
                // cerr<<a<<"->";
                // pr(a);
                // cerr<<(a+c)/2<<"->";
                // pr((a+c)/2);
                // cerr<<c<<"->";
                // pr(c);
                // cerr<<c-a<<"->";
                // pr(c-a);
                // cerr<<'\n';
            }
        }
    }
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--){
        solve();}
    return 0;
}