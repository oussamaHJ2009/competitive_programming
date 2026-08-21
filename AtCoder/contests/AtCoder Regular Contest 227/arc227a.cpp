/*
*created: 2026-08-16 at 13:12:31
*problem: Fermat Poll of Binary Strings, link: https://atcoder.jp/contests/arc227/tasks/arc227_a
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin>>n;
    string s[3];
    for(ll i=0;i<3;i++)cin>>s[i];
    sort(s,s+3);
    string b = s[1];
    auto cnt = [&](string t){
        ll ret=0;
        vector<int>C[2]{{},{}};
        for(ll i=0;i<2*n;i++){
            if(t[i]!=b[i]){
                C[t[i]-'0'].push_back(i);
            }
        }
        for(int i=0;i<C[0].size();i++){
            ret+=abs(C[0][i]-C[1][i]);
        }
        return abs(ret);
    };

    cout<<cnt(s[0])+cnt(s[2])<<'\n';
    cout<<b<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}