/*
*created: 2026-08-06 at 15:35:10
*problem: A. Boss Fight, link: https://codeforces.com/contest/2252/problem/A
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first == b.first)return a.second < b.second;
    return a.first > b.first;
}

void solve() {
    vector<int>cnt(1001,0);
    int n;
    cin>>n;
    vector<int>a(n);
    int S=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        S+=a[i];
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