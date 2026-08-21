//problem link: https://codeforces.com/contest/2246/problem/A
//authored by a human (i guess?)


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    iota(a.begin(),a.end(),1);
    for (int i = 0; i < n; i+=2)
    {
        swap(a[i],a[i+1]);
    }
    
    for(auto x:a)cout<<x<<' ';
    cout<<'\n';
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