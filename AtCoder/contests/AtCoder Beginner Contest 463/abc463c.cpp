//problem link: https://atcoder.jp/contests/abc463/tasks/abc463_c
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>>tak(n);
    vector<int>L;
    for(auto &[l,h]:tak){
        cin>>h>>l;
        L.push_back(l);
    }
    sort(tak.begin(),tak.end());
    sort(L.begin(),L.end());
    int mx=tak[n-1].second;
    for (int i = n - 2; i >= 0; i--)
    {
        tak[i].second=max(tak[i+1].second,tak[i].second);
    }
    
    
    
    int q;
    cin>>q;
    while (q--)
    {
        int ti;cin>>ti;
        int ans=upper_bound(L.begin(),L.end(),ti) - L.begin();
        cout<<tak[ans].second<<'\n';
    }
    
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