//problem link: https://codeforces.com/gym/378360/problem/A
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,m;
    cin>>n>>m;
    bool ok=1;
    int lo=m,hi=m;
    int lst=0;
    for (int i = 0; i < n; i++)
    {
        int ti,l,r;
        cin>>ti>>l>>r;
        if(!ok)continue;
        hi+=ti-lst;
        lo-=ti-lst;
        lst=ti;
        lo=max(lo,l);
        hi=min(r,hi);
        if(lo>hi)ok=0;
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