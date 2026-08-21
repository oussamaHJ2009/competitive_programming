//problem link: https://atcoder.jp/contests/abc462/tasks/abc462_c
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second < b.second;
}

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>>cords(n);
    for (auto &[x,y] : cords)
    {
        cin>>x>>y;
    }
    sort(cords.begin(),cords.end());
    int miny=cords[0].second;
    int ans=n;
    for (int i = 1; i < n; i++)
    {
        if(cords[i].second>miny){
            ans--;
        }else{
            miny=cords[i].second;
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