//problem link: https://codeforces.com/contest/2246/problem/B
//authored by a human (i guess?)


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<ll>a(n);
    a[0]=1;
    if(n>1)a[1]=2;
    ll s = 3;
    for (ll i = 2; i < n; i++)
    {
        a[i]=s;s+=s;
    }
    if(n==2){cout<<"-1\n";return;}
    for (int i = 0; i < n; i++)
    {
        cout<<a[i] << ' ';
    }
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