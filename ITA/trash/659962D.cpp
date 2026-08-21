/*
*created: 2026-08-11 at 19:36:49
*problem: D. Restaurant Customers, link: https://codeforces.com/group/lRRb3iToWJ/contest/659962/problem/D
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int>cc{0};
    vector<pair<int,int>>p(n);
    for(int i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
        cc.push_back(p[i].first);
        cc.push_back(p[i].second+1);
    }
    vector<int>d(cc.size()+2);
    sort(cc.begin(),cc.end());
    for(int i=0;i<n;i++){
        int l = lower_bound(cc.begin(),cc.end(),p[i].first) - cc.begin();
        int r = lower_bound(cc.begin(),cc.end(),p[i].second+1) - cc.begin();
        d[l]++;
        d[r]--;
    }
    for(int i=1;i<d.size();i++){
        d[i]+=d[i-1];
    }

    cout<<*max_element(d.begin(),d.end())<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}