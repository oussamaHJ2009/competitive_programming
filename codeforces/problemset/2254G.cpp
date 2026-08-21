/*
*created: 2026-08-04 at 21:39:28
*problem: G. Nightcrawler, link: https://codeforces.com/contest/2254/problem/G
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>>T;
vector<int>a;

void solve() {
    int n;
    cin>>n;
    a.assign(n,0);
    T.assign(n,vector<int>());
    for(int i=0;i<n;i++){
        int p;cin>>p;
        if(i){
            T[--p].push_back(i);
            T[i].push_back(p);
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}