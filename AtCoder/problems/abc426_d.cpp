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
        string s;
        int n;
        cin >> n >> s;
        
        vector<int>cnt(2),mx(2);
        for (int l = 0; l < n;)
        {
            int r=l+1;
            while (r<n && s[r]==s[l])r++;
            int c=s[l]-'0';
            mx[c]=max(mx[c],r-l);
            cnt[c]+=r-l;
            l=r;
        }
        int ans=1e6;
        for (int i = 0; i < 2; i++)
        {
            ans=min(ans,(cnt[i]-mx[i])*2+cnt[!i]);
        }
        cout<<ans<<'\n';
    }

    return 0;
}