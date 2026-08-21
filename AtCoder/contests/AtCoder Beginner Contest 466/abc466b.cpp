//problem link: https://atcoder.jp/contests/abc466/tasks/abc466_b
//authored by a human (i guess?)


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int>mx(m+1,-1);
    for (int i = 0; i < n; i++)
    {
        int c,s;
        cin>>c>>s;
        mx[c]=max(mx[c],s);
    }
    for (int i = 1; i <= m; i++)
    {
        cout<<mx[i]<<' ';
    }
    cout<<'\n';
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