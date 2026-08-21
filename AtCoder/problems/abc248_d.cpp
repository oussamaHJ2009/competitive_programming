#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin>>n;
    vector<int>a(n);
    vector<vector<int>>cnt(n+1);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        cnt[a[i]].push_back(i+1);
    }
    int q;
    cin>>q;
    while (q--)
    {
        int l,r,x;cin>>l>>r>>x;
        int c=upper_bound(cnt[x].begin(),cnt[x].end(),r)-lower_bound(cnt[x].begin(),cnt[x].end(),l);
        cout<<c<<endl;
    }
    

    return 0;

}