//problem link: https://codeforces.com/contest/2224/problem/A
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ll acc=0;
    int ans=0;
    for (int i = n-1; i >= 0; i--)
    {
        if(a[i]+acc>0){
            ans++;
            acc+=a[i];
        }else{
            acc=0;
        }
    }
    cout<<ans<<'\n';
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