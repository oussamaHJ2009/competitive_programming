//problem link: https://codeforces.com/contest/2240/problem/C
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    int s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s^=a[i];
    }
    int ans=(s==0);
    for(int i=0;i<n;i++)ans+=((s^a[i])<a[i]);
    cout<<(n>1?ans:0)<<'\n';
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