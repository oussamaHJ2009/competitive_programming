//problem link: https://codeforces.com/contest/2236/problem/C
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int a,b,x;
    cin>>a>>b>>x;
    int ans=abs(a-b);
    int cnt=0;
    while (a!=b)
    {
        if(a>b)a/=x;
        else b/=x;
        cnt++;
        ans=min(ans,cnt+abs(a-b));
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