/*
*created: 2026-08-11 at 19:52:51
*problem: S. In Search of an Easy Problem, link: https://codeforces.com/group/lRRb3iToWJ/contest/659962/problem/S
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    int s=0;
    cin>>n;
    while(n--){
        int x;cin>>x;
        s+=x;
    }
    if(s)cout<<"HARD\n";
    else cout<<"EASY\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}