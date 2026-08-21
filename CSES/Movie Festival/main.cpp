#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

bool cmp(pair<int,int>a,pair<int,int>b){
    if(b.second==a.second)return a.first<b.first;
    return a.second<b.second;
}

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>>m(n);
    for (auto &[a,b]:m)
    {
        cin>>a>>b;
    }
    sort(m.begin(),m.end(),cmp);
    int ans=0;
    int lst=0;
    for (int i = 0; i < n; i++)
    {
        if(m[i].first >= lst){
            ans++;
            lst=m[i].second;
        }
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