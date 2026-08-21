//problem link: https://codeforces.com/contest/2242/problem/B
//authored by a human (i guess?)


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int cg=0,ce=0;
    int cur=1;
    int i = 0;
    int R=n-2;
    while(R>1 && a[R]==3)R--;
    for (; i <= R && cur<3; i++)
    {
        if(a[i]>cur)cg++;
        else ce++;
        if(ce>=cg){cur++;ce=0;cg=0;}
    }
    if(cur==3)cout<<"YES\n";
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