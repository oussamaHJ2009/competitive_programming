//problem link: https://codeforces.com/contest/2240/problem/A
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,k;
    cin>>n>>k;
    int ans=0,cnt=0;
    int s=0;
    while (cnt+(1<<s)*k <=n)
    {
        ans+=k;
        cnt+=(1<<s)*k;
        s++;
    }
    while (cnt+(1<<s)<=n)
    {
        cnt+=(1<<s);
        ans++;
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