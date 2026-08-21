//problem link: https://codeforces.com/gym/104114/problem/N
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for (int i = 1; i < n; i++)
    {
        if(a[i]<a[i-1]-m)a[i]=a[i-1]-m;
    }
    for(int i=n-2;i>=0;i--){
        if(a[i]<a[i+1]-m)a[i]=a[i+1]-m;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<' ';
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