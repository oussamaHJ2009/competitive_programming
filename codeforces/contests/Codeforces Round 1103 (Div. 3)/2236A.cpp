//problem link: https://codeforces.com/contest/2236/problem/A
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    int mx=0,mn=100;
    for (int i = 0; i < n; i++)
    {
        int a;cin>>a;
        mn=min(a,mn);
        mx=max(a,mx);
    }
    cout<<mx-mn+1<<'\n';
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