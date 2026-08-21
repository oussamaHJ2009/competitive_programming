//problem link: https://codeforces.com/contest/2157/problem/C
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,q,k;
    cin>>n>>k>>q;
    vector<int>mx(n+1),mn(n+1);
    for (int i = 0; i < q; i++)
    {
        int c,l,r;
        cin>>c>>l>>r;
        for (int i = l; i <= r; i++)
        {
            if(c==1)mn[i]=1;
            else mx[i]=1;
        }
    }
    vector<int>a(n+1);
    for (int i = 1; i <= n; i++)
    {
        if(mn[i]&&mx[i])a[i]=k+1;/* code */
        else if(mx[i]==1)a[i]=i%k;
        else a[i]=k;
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<' ';
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