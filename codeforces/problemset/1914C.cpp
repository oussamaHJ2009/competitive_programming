#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (auto &it : a)
            cin >> it;
        for (auto &it : b)
            cin >> it;
        int ans=0;
        int s=0;
        int best=0;
        for (int i = 0; i < min(n,k); i++)
        {
            s+=a[i];
            best=max(best,b[i]);
            ans=max(ans,s+best*(k-i-1));
        }
        cout<<ans<<'\n';
    }

    return 0;
}