//problem link: https://codeforces.com/contest/2242/problem/A
//authored by a human (i guess?)


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int k,c2=0;
    bool yes=false;
    cin>>k;
    for (int i = 0; i < k; i++)
    {
        ll a;
        cin>>a;
        if(a>2)yes=true;
        if(a==2)c2++;
    }
    if(c2>1 || yes)cout<<"YES\n";
    else cout<<"NO\n";

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