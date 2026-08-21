//problem link: https://codeforces.com/contest/2247/problem/A?locale=en
//authored by a human (i guess?)

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    int c1=0,c_1=0,s=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i]==-1)c_1++;
        else c1++;
        s+=a[i];
    }
    if(n%2==0 && (n/2 - min(c1,c_1))%2==0 || (n==2&&s==0)){
        cout<<"YES\n";
    }else cout<<"NO\n";
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}