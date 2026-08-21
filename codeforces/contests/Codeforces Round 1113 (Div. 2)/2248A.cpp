/*
*created: 2026-08-01 at 15:35:13
*problem: A. You Delete, I Delete, link: https://codeforces.com/contest/2248/problem/A
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin>>s;
    int z=-1,o=-1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0' && z==-1){z=i;}
        else if(s[i]=='1' && o==-1)o=i;
        else cout<<s[i];
    }
    cout<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}