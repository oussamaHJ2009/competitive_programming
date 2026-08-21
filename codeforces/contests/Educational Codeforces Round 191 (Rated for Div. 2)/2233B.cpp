//problem link: https://codeforces.com/contest/2233/problem/B
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(4*n);
    for (int i = 0; i < n; i++)
    {
        a[i]=i+1;
    }
    for(int i=n;i<2*n;i++){
        a[i]=i+1-n;
    }
    vector<int>m(n);
    for (int i = 0; i < n; i++)
    {
        m[i]=(i+1)%n + 1;
    }
    for (int i = 2*n; i < 3*n; i++)
    {
        a[i]=m[i-2*n];
    }
    for (int i = 3*n; i < 4*n; i++)
    {
        a[i]=i-3*n +1;
    }
    for(auto x:a){
        cout<<x<<' ';
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