//problem link: https://codeforces.com/contest/2236/problem/B
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int>cnt(k);
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='1')cnt[i%k]++;
    }
    bool ok=1;
    for (int i = 0; i < k; i++)
    {
        if(cnt[i]%2)ok=0;
    }
    cout<<(ok?"YES":"NO")<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}