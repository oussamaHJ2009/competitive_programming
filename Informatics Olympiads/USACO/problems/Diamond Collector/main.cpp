#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int l=0,r=0;
    vector<int>L(n);
    for (;l<n;l++)
    {
        while (r<n && a[r]-a[l]<=k)r++;
        L[l]=r-l;
    }
    vector<int>suf(n+1);
    suf[n]=0;
    for (int i = n-1; i >= 0; i--)
    {
        suf[i]=max(suf[i+1],L[i]);
    }
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        ans=max(L[i]+suf[i+L[i]],ans);
    }
    cout<<ans<<'\n';

}

int main() {
    setIO("diamond");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}