#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353
const int N=1e6+1;
int n, a[N], cnt[N], ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cnt[0] = 1;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        vector<int> div;
        for (int j=1;j*j<=a[i];j++)
        {
            if (a[i]%j==0)
            {
                div.push_back(j);
                if (j!=a[i]/j)
                    div.push_back(a[i]/j);
            }
        }
        sort(div.begin(), div.end());
        reverse(div.begin(), div.end());
        for (auto x : div)
        {
            cnt[x]+=cnt[x-1];
            cnt[x]%=mod;
        }
    }

    ll ans = 0;
    for (int i=1;i<=n;i++)
        ans+=cnt[i];
    ans%=mod;
    cout<<ans<<endl;

    return 0;
}